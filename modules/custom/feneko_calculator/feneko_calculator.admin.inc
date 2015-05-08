<?php
/**
 * @file
 * For settings
 */

function feneko_calculator_settings_form($form, &$form_state) {
  $form['fc_minimum_order_amount'] = array(
    '#type' => 'textfield',
    '#title' => 'Minimum facturatie bedrag',
    '#size' => 2,
    '#maxlength' => 30,
    '#field_prefix' => '€',
    '#default_value' => variable_get('fc_minimum_order_amount'),
    '#element_validate' => array('element_validate_number'),
  );

  return system_settings_form($form);
}

function feneko_calculator_export($order) {
    header("Content-type: application/octet-stream");
    header("Content-Disposition: attachment; filename=\"order_" . $order->order_id . ".txt\"");
    echo feneko_calculator_order_to_xml($order);
    exit;
}

function feneko_calculator_order_to_xml($order) {
  module_load_include('inc', 'feneko_calculator', 'extra_fields');
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  $xml = "<Order>";

  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'order_id');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'uid');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'status');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'created');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'changed');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_color');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_comment');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_reference');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_maritime');
  $xml .= _feneko_calculator_add_xml_field($order_wrapper, 'field_color');

  foreach ($order_wrapper->commerce_line_items as $delta => $line) {
    if($line->type->value() !== 'commerce_discount') {
      $xml .= "<LineItem>";
      $xml .= _feneko_calculator_add_xml_field($line, 'line_item_id');
      $xml .= _feneko_calculator_add_xml_field($line, 'quantity');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'sku');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'product_id');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'title');
      $xml .= _feneko_calculator_add_xml_field($line->commerce_product, 'type');
      $xml .= fc_line_item_details($line->value(), 'xml');
      $xml .= "</LineItem>";
    }
  }

  $xml .= "</Order>";

  $dom = new DOMDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);
  $dom->formatOutput = TRUE;
  return $dom->saveXml();

  return $xml;
}

function _feneko_calculator_add_xml_field($wrapper, $name) {
  $tag = camelCase(str_replace('field', '', $name));
  if(!empty($wrapper->$name->value())) {
    return "<$tag>" . $wrapper->$name->value() . "</$tag>";
  }
}
