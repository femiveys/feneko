<?php
/**
 * Makes the content of a line item beautiful
 *
 * @param $line_item
 *   The line item
 * @param $text_only
 *   Flag to indicate if the output needs to be text only or a render array
 * @return array/string
 *   Renderable array of string
 */
function fc_line_item_details($line_item, $text_only = FALSE) {
  $fields = array(
    'commerce_product' => array(
      'field_mke_type',
      'field_muurkap_type',
      'field_standaardprofiel_type',
      'field_muurkap_diepte',
      'field_raamtablet_eindstuk_typeiepte',
      'field_plaatbewerking_dikte',
      'field_raamtablet_eindstuk_type',
      'field_anti_dreunstrook',
      'field_hoek_type',
      'field_maat',
    ),
    'commerce_line_item' => array(
      'field_type_bewerking',
      'field_tekening',
      'field_lakzijde',
      'field_lengte',
      'field_breedte',
      'field_multi_breedte',
      'field_multi_hoek',
      'field_knippen',
      'field_plooien',
      'field_ophanging',
      'field_isolatie_dikte',
      'field_bicolor_kleur',
      'field_eindstukken',
      'field_hoeken',
      'field_koppelstukken',
      'field_anti_dreunstrook',
      'field_aantal_adsn',
      'field_beugels',
      'field_rug',
      'field_kant',
      'field_raamtablet_diepte',
    ),
  );

  $product = commerce_product_load($line_item->commerce_product[LANGUAGE_NONE][0]['product_id']);
  $output = array();
  $text = '';
  $weight = 0;

  // if($product->type === 'raamtablet_eindstuk' or $product === 'muurkap_eindstuk') {
  //   $fields['commerce_product'][] = 'title';
  // }
// dpm($line_item);

  foreach ($fields as $entity_type => $field_names) {
    $e = $entity_type === 'commerce_product' ? $product : $line_item;

    foreach ($field_names as $field_name) {
      if (isset($e->$field_name)) {
        if($field_ra = _fc_field_output($field_name, $e, $entity_type, $text_only)) {
          $output[$field_name] = $field_ra;
          $output[$field_name]['#weight'] = $weight++;
        }
      }
    }
  }

  if($text_only) {
    $text = '';
    foreach ($output as $field_name => $value) {
      $text .= $value['text'];
    }
    $output = $text;
  } else {
    // If not empty, add wrapper
    if (!empty($output)) {
      $output = array(
        '#type' => 'container',
        '#attributes' => array('class' => array('line-item-details')),
        'data' => $output,
        '#attached' => array('css' => array(
          drupal_get_path('module', 'feneko_calculator') . '/css/extra_fields.css'
        )),
      );
    }
  }

  return $output;
}


/**
 * Helper function to render a specific field.
 *
 * @param array $field_name
 *   The name of the field
 * @param array $field
 *   The entity instance field value
 * @param array $entity_type
 *   The entity type
 * @param boolean $text_only
 *   TRUE if the output has to be an array with a text key
 *   FALSE if the output has to be a renderable array
 * @return array / string
 *   Renderable array representing the field or an array with a text key.
 *   NULL otherwise
 */
function _fc_field_output($field_name, $entity, $entity_type, $text_only) {
  $ra = array();

  // if($field_name === 'TOREMOVE') {
  // } else {
    if ($info = field_info_field($field_name)) {
      $raw_values = field_get_items($entity_type, $entity, $field_name);

      // Multifields have to be rendered differently
      if ($info['cardinality'] == 1) {
        // We don't render fields having an empty value
        if (!empty($raw_values[0]['value']) or $field_name === 'field_tekening') {
          $display = array(
            'label' => 'inline',
            'settings' => array(
              'decimal_separator' => ',',
              'prefix_suffix' => TRUE,
              'scale' => 0,
              'thousand_separator' => '',
            ),
          );
          $ra = field_view_field($entity_type, $entity, $field_name, $display);

          // For products, we need to take the label from the ATTRIBUTE FIELD SETTINGS
          if($entity_type === 'commerce_product') {
            $instance_info = field_info_instance($entity_type, $field_name, $entity->type);
            $ra['#title'] =  commerce_cart_attribute_widget_title($instance_info);
          }

          // Convert this to just the text for text-only output
          if ($text_only) {
            if($field_name === 'field_tekening') {
              if(isset($ra[0]['#file'])) {
                $file = $ra[0]['#file'];
                $ra = array(
                  'text' => $ra['#title'] . ": " . $file->filename . "\n",
                );
              }
            } else {
              $ra = array(
                'text' => $ra['#title'] . ": " . $ra[0]['#markup'] . "\n",
              );
            }
          }

        }
      } else {
        $ra = _fc_multi_field_ra($entity, $field_name, $text_only);
      }
    } else {
      $msg = t('Field info for :field was not found', array(':field' => $field_name));
      drupal_set_message($msg, 'error');
    }

  // }


  return $ra;
}


/**
 * Get the renderable array for multivalue fields
 *
 * @param stdClass $entity
 *   The entity holding the field
 * @param string $field_name
 *   The name of the field
 * @param boolean $text_only
 *   TRUE if the output has to be an array with a text key
 *   FALSE if the output has to be a renderable array
 * @return array
 *   The renderable array
 */
function _fc_multi_field_ra($entity, $field_name, $text_only) {
  $muurkap_type = NULL;

  if ($entity->type === 'muurkap') {
    $product = commerce_product_load($entity->commerce_product[LANGUAGE_NONE][0]['product_id']);
    $mapping = fc_get_multi_field_mapping($product->field_muurkap_type['und'][0]['value']);
  } else {
    $mapping = fc_get_multi_field_mapping();
  }

  $ra = array();
  foreach ($entity->{$field_name}[LANGUAGE_NONE] as $index => $value) {
    if (!empty($value['value'])) {
      $label = $mapping[$field_name][$index];
      if ($text_only) {
        // $utf_mapping = array(
        //   'α' => 'alpha',
        //   'β' => 'beta ',
        //   'γ' => 'gamma',
        //   'δ' => 'delta',
        // );
        // $label = strtr($label, $utf_mapping);
        $text = '';
        $text .= $field_name === 'field_eindstukken' ? "&nbsp;&nbsp;- " : '';
        $text .= "$label: " . $value['value'];
        $text .= $field_name === 'field_eindstukken' ? "\n" : '';
        $ra[] = $text;
      } else {
        $ra[] = array(
          '#prefix' => '<li>',
          '#suffix' => '</li>',
          'data' => array(
            '#prefix' => '<dl>',
            '#suffix' => '</dl>',
            'label' => array(
              '#prefix' => '<dt>',
              '#suffix' => '</dt>',
              '#markup' => $label,
            ),
            'value' => array(
              '#prefix' => '<dd>',
              '#suffix' => '</dd>',
              '#markup' => $value['value'],
            ),
          ),
        );

      }
    }
  }

  // If not empty, we need to add some wrappers and the label
  if (!empty($ra)) {
    if ($label = commerce_cart_attribute_widget_title(
                  field_info_instance('commerce_line_item', $field_name, $entity->type))) {

      if ($text_only) {
        $delim = $field_name === 'field_eindstukken' ? "" : ', ';
        $text  = $label . ": ";
        $text .= $field_name === 'field_eindstukken' ? "\n" : '';
        $text .= implode($delim, $ra);
        $text .= $field_name === 'field_eindstukken' ? "" : "\n";
        $ra = array('text' => $text);
      } else {
        $ra = array(
          '#type' => 'container',
          '#attributes' => array('class' => array(
            "field",
            "field-name-field-" . drupal_clean_css_identifier($field_name),
            "field-type-number-integer",
            "field-cardinality-multi",
            "field-label-above",
            "clearfix",
          )),
          'label' => array(
            '#type' => 'container',
            '#attributes' => array('class' => array('field-label')),
            'data' => array('#markup' => $label . ":&nbsp;")
          ),
          'value' => array(
            '#prefix' => '<ul>',
            '#suffix' => '</ul>',
            'data' => $ra,
          ),
        );
      }
    } else {
      $msg = t('Instance info for :field on :type Line Item was not found',
                      array(':field' => $field_name, ':type' => $entity->type));
      drupal_set_message($msg, 'error');
    }
  }

  return $ra;
}

function fc_order_overview_mail_text($order) {
  $text = '';

  foreach ($order->commerce_line_items[LANGUAGE_NONE] as $key => $value) {
    $line_item = commerce_line_item_load($value['line_item_id']);
    $text .= strtoupper($line_item->type) . "\n";
    $text .= fc_line_item_details($line_item, TRUE);
    $text .= "\n";
  }

  return $text;
}
