<?php
/**
 * @file
 * feneko_calculator_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feneko_calculator_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer product display types'.
  $permissions['administer product display types'] = array(
    'name' => 'administer product display types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_backoffice_product',
  );

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce',
  );

  // Exported permission: 'create field_order4'.
  $permissions['create field_order4'] = array(
    'name' => 'create field_order4',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_order4'.
  $permissions['edit field_order4'] = array(
    'name' => 'edit field_order4',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_order4'.
  $permissions['edit own field_order4'] = array(
    'name' => 'edit own field_order4',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_order4'.
  $permissions['view field_order4'] = array(
    'name' => 'view field_order4',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_order4'.
  $permissions['view own field_order4'] = array(
    'name' => 'view own field_order4',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
