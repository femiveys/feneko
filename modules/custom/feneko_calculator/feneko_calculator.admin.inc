<?php
/**
 * @file
 * For settings
 */

function feneko_calculator_settings_form($form, &$form_state) {
  $form['fc_minimum_order_amount'] = array(
    '#type' => 'textfield',
    '#title' => 'Minimum facturatie bedrag',
    '#size' => 4,
    '#maxlength' => 30,
    '#field_prefix' => '€',
    '#default_value' => variable_get('fc_minimum_order_amount'),
    '#element_validate' => array('element_validate_number'),
  );

  $form['fc_notification_email'] = array(
    '#type' => 'textfield',
    '#title' => 'E-mail',
    '#size' => 20,
    '#maxlength' => 30,
    '#element_validate' => array('element_validate_mail'),
    '#default_value' => variable_get('fc_notification_email', variable_get('manyforms_notification_email', '')),
    '#description' => t('Email address where all submission notifications will be sent'),
  );

  $form['fc_order_email_text'] = array(
    '#title' => t('Client e-mail text for an order'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_order_email_text', ''),
    '#description' => t('Text of the email that will be sent to user who has submitted an order. You can use the
                         token <strong>{name}</strong> to provide the username of the submitter.'),
  );

  $form['fc_offer_email_text'] = array(
    '#title' => t('Client e-mail text for an offer'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_offer_email_text', ''),
    '#description' => t('Text of the email that will be sent to user who has submitted an offer. You can use the
                         token <strong>{name}</strong> to provide the username of the submitter.'),
  );

  $form['fc_notification_email_text'] = array(
    '#title' => t('Admin e-mail text'),
    '#type' => 'textarea',
    '#default_value' => variable_get('fc_notification_email_text', ''),
    '#description' => t('Text of the email that will be sent to the email provided above. You can use following placeholders: <strong>{name}, {client_number}, {company}</strong>'),
  );

  return system_settings_form($form);
}


function element_validate_mail($element, &$form_state) {
  $value = $element['#value'];
  if (!valid_email_address($value)) {
    form_error($element, t('%name must be valid e-mail address.', array('%name' => $element['#title'])));
  }
}


/**
 * Sends the XML export to the browser for immediate download
 *
 * @param stdClass $order
 */
function feneko_calculator_xml(stdClass $order) {
    header("Content-type: application/octet-stream");
    header("Content-Disposition: attachment; filename=\"order_" . $order->order_id . ".xml\"");
    echo feneko_calculator_order_to_xml($order);
    exit;
}

/**
 * Transforms an order into an XML string
 *
 * @param stdClass $order
 *
 * @return string The formatted XML
 */
function feneko_calculator_order_to_xml(stdClass $order) {
  module_load_include('inc', 'feneko_calculator', 'extra_fields');
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  $xml = "<Order>";

  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'order_id');
  $xml .= empty($order->field_order4)
          ? _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_klantennummer')
          : _feneko_calculator_add_xml_field($order_wrapper, 'field_order4', "Klantennummer");
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'status');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'created');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'changed');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_color');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_comment');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_reference');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_maritime');

  $xml .= "<Owner>";
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'uid');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'name');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'mail');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'language');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_naam_bedrijf');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_btw_nummer');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_telefoon');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper->owner, 'field_geblokkeerd');
  $xml .= "</Owner>";

  foreach ($order_wrapper->commerce_line_items as $delta => $line) {
    if($line->type->value() !== 'commerce_discount') {
      $xml .= "<Item>";
      $xml .= _feneko_calculator_add_xml_field($line, 'line_item_id');
      $xml .= _feneko_calculator_add_xml_field($line, 'quantity');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'type', 'ProductType');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'sku');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'product_id');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'title');
      $xml .= fc_line_item_details($line->value(), 'xml');
      $xml .= "</Item>";
    }
  }

  $totals = _fc_totals_order($order_wrapper);
  $xml .= "<SubTotal><Raw>" . $totals['raw']['subtotal'] . "</Raw>";
  $xml .= "<Formatted>" . $totals['formatted']['subtotal'] . "</Formatted></SubTotal>";
  $xml .= "<Total><Raw>" . $totals['raw']['total'] . "</Raw>";
  $xml .= "<Formatted>" . $totals['formatted']['total'] . "</Formatted></Total>";
  $xml .= "</Order>";

  // Pretty print the XML
  $dom = new DOMDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);
  $dom->formatOutput = TRUE;

  return $dom->saveXml();
}

/**
 * Helper function to add a field to an XML string
 *
 * If it is a multivaluefield, the first value is taken.
 *
 * @param EntityMetadataWrapper $wrapper The wrapper holding the field to
 *                                       transform into a tag
 * @param string $name The name of the field. Field names starting with
 *                     "field_" will get a tag name without the field_ prefix
 * @param string $tag_override Name of the tag if it needs to be overridden
 *
 * @return string The XML tag
 */
function _feneko_calculator_add_xml_field(EntityMetadataWrapper $wrapper, $name,
                                                         $tag_override = NULL) {
  $tag = isset($tag_override) ? $tag_override : camelCase(str_replace('field_', '', $name));
  if(!empty($wrapper->$name->value())) {
    $value = $wrapper->$name->value();
    if(is_array($value)) {
      $value = $value[0];
    }
    return "<$tag>" . htmlspecialchars($value) . "</$tag>";
  }
}
