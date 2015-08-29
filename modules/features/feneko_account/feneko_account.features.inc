<?php
/**
 * @file
 * feneko_account.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feneko_account_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
