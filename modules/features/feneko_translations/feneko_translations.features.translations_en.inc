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
  $translations['en:field']['8bdb6f3c0dc443d33247b930eb4931dc'] = array(
    'source' => 'BTW nummer',
    'context' => 'field_btw_nummer:user:label',
    'location' => 'field:field_btw_nummer:user:label',
    'translation' => 'BTW nummer',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('BTW nummer', array(), array('context' => 'field_btw_nummer:user:label'));
  $translations['en:field']['8d9ff4331de53522c9c3458f7f9e1db1'] = array(
    'source' => 'Order total',
    'context' => 'commerce_order_total:commerce_order:label',
    'location' => 'field:commerce_order_total:commerce_order:label',
    'translation' => 'Order total',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Order total', array(), array('context' => 'commerce_order_total:commerce_order:label'));
  $translations['en:field']['fc514092eaecc5da4d39edc331233a03'] = array(
    'source' => 'Naam Bedrijf',
    'context' => 'field_naam_bedrijf:user:label',
    'location' => 'field:field_naam_bedrijf:user:label',
    'translation' => 'Naam Bedrijf',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Naam Bedrijf', array(), array('context' => 'field_naam_bedrijf:user:label'));
  return $translations;
}
