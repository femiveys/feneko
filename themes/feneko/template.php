<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

function feneko_preprocess_page(&$vars){
  //i18n_taxonomy_localize_terms
  $path = arg();
  if($path[0]=='taxonomy'&&$path[1]=='term'&&is_numeric($path[2])) {
    $term = taxonomy_term_load($path[2]);
    $lterms = i18n_taxonomy_localize_terms(array($term));
    if (isset($lterms[0]->name)) {
      drupal_set_title($lterms[0]->name);
    }
  }
}


function feneko_preprocess_field(&$vars) {
 // var_dump($vars);
}

function feneko_preprocess_node(&$vars) {
  if (isset($vars['field_bestelformulier'][0]['value'])&&$vars['field_bestelformulier'][0]['value']=='1') {
    $vars['classes_array'][] = 'bestelformulier';
  }
}

function feneko_preprocess_views_view($vars) {
  $view = &$vars['view'];
  if($view->name == 'terms'){
  }
}
