<?php
/**
 * @file
 * feneko_calculator_feature.features.inc
 */

/**
 * Implements hook_commerce_features_default_checkout_panes().
 */
function feneko_calculator_feature_commerce_features_default_checkout_panes() {
  $panes = array();

  $panes['account'] = array(
    'page' => 'disabled',
    'weight' => -17,
    'pane_id' => 'account',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['cart_contents'] = array(
    'page' => 'checkout',
    'weight' => -19,
    'pane_id' => 'cart_contents',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['checkout_completion_message'] = array(
    'page' => 'complete',
    'fieldset' => 0,
    'pane_id' => 'checkout_completion_message',
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['checkout_review'] = array(
    'page' => 'disabled',
    'fieldset' => 0,
    'pane_id' => 'checkout_review',
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -18,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['commerce_fieldgroup_pane__group_order_info'] = array(
    'enabled' => 1,
    'pane_id' => 'commerce_fieldgroup_pane__group_order_info',
    'page' => 'checkout',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -20,
    'review' => 1,
  );

  $panes['commerce_payment'] = array(
    'page' => 'disabled',
    'weight' => -19,
    'pane_id' => 'commerce_payment',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['commerce_payment_redirect'] = array(
    'page' => 'payment',
    'pane_id' => 'commerce_payment_redirect',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -20,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['customer_profile_billing'] = array(
    'page' => 'disabled',
    'weight' => -16,
    'pane_id' => 'customer_profile_billing',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  return $panes;
}

/**
 * Implements hook_commerce_line_item_default_types().
 */
function feneko_calculator_feature_commerce_line_item_default_types() {
  $items = array(
    'dorpel_stuk' => array(
      'name' => 'Dorpel Stuk',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
    'muurkap' => array(
      'name' => 'Muurkap',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
    'plaatbewerking' => array(
      'name' => 'Plaatbewerking',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
    'raamtablet' => array(
      'name' => 'Dorpel',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
    'raamtablet_eindstuk' => array(
      'name' => 'Dorpel Eindstuk',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
    'sandwichpaneel' => array(
      'name' => 'Sandwichpaneel',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
    'standaardprofiel' => array(
      'name' => 'Standaardprofiel',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Product toevoegen',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function feneko_calculator_feature_commerce_product_default_types() {
  $items = array(
    'dorpel_anti_dreunstrook' => array(
      'type' => 'dorpel_anti_dreunstrook',
      'name' => 'Dorpel Anti-Dreunstrook',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'dorpel_eindstuk' => array(
      'type' => 'dorpel_eindstuk',
      'name' => 'Dorpel Eindstuk',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'dorpel_hoek' => array(
      'type' => 'dorpel_hoek',
      'name' => 'Dorpel Hoek',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'dorpel_koppelstuk' => array(
      'type' => 'dorpel_koppelstuk',
      'name' => 'Dorpel Koppelstuk',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'muurkap' => array(
      'type' => 'muurkap',
      'name' => 'Muurkap',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'muurkap_eindstuk' => array(
      'type' => 'muurkap_eindstuk',
      'name' => 'Muurkap Eindstuk',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'plaatbewerking' => array(
      'type' => 'plaatbewerking',
      'name' => 'Plaatbewerking',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'raamtablet' => array(
      'type' => 'raamtablet',
      'name' => 'Dorpel',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'raamtablet_eindstuk' => array(
      'type' => 'raamtablet_eindstuk',
      'name' => 'Dorpel Eindstuk Old',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'sandwichpaneel' => array(
      'type' => 'sandwichpaneel',
      'name' => 'Sandwichpaneel',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'sandwichpaneel_isolatie' => array(
      'type' => 'sandwichpaneel_isolatie',
      'name' => 'Sandwichpaneel Isolatie',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'standaardprofiel' => array(
      'type' => 'standaardprofiel',
      'name' => 'Standaardprofiel',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
    'unit' => array(
      'type' => 'unit',
      'name' => 'Unit',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function feneko_calculator_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feneko_calculator_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feneko_calculator_feature_node_info() {
  $items = array(
    'dorpel_anti_dreunstrook' => array(
      'name' => t('Dorpel Anti-Dreunstrook'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'dorpel_eindstuk' => array(
      'name' => t('Dorpel Eindstuk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'dorpel_hoek' => array(
      'name' => t('Dorpel Hoek'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'dorpel_koppelstuk' => array(
      'name' => t('Dorpel Koppelstuk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'muurkap' => array(
      'name' => t('Muurkap'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'plaatbewerking' => array(
      'name' => t('Plaatbewerking'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'raamtablet' => array(
      'name' => t('Dorpel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'sandwichpaneel' => array(
      'name' => t('Sandwichpaneel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'standaardprofiel' => array(
      'name' => t('Standaardprofiel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'stuk' => array(
      'name' => t('Stuk'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'unit' => array(
      'name' => t('Unit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_payment_method().
 */
function feneko_calculator_feature_default_payment_method() {
  $items = array();
  $items['no_payment_required'] = entity_import('payment_method', '{
    "controller_data" : [],
    "enabled" : true,
    "name" : "no_payment_required",
    "title_specific" : "No payment required",
    "title_generic" : "No payment required",
    "uid" : 1,
    "controller_class_name" : "PaymentMethodControllerUnavailable"
  }');
  return $items;
}
