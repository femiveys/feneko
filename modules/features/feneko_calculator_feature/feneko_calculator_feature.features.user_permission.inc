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

  // Exported permission: 'create field_orderfor'.
  $permissions['create field_orderfor'] = array(
    'name' => 'create field_orderfor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_orderfor'.
  $permissions['edit field_orderfor'] = array(
    'name' => 'edit field_orderfor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_orderfor'.
  $permissions['edit own field_orderfor'] = array(
    'name' => 'edit own field_orderfor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_orderfor'.
  $permissions['view field_orderfor'] = array(
    'name' => 'view field_orderfor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_orderfor'.
  $permissions['view own field_orderfor'] = array(
    'name' => 'view own field_orderfor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
