<?php
/**
 * @file
 * feneko_translations.features.translations_en.inc
 */

/**
 * Implements hook_translations_en_defaults().
 */
function feneko_translations_translations_en_defaults() {
  $translations = array();
  $translatables = array();
  $translations['en:field']['473f678851bd18c2e3d32969f2e29855'] = array(
    'source' => 'Klantennummer',
    'context' => 'field_order4:commerce_order:label',
    'location' => 'field:field_order4:commerce_order:label',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer', array(), array('context' => 'field_order4:commerce_order:label'));
  return $translations;
}
