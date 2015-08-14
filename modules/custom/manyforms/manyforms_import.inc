<?php
/**
 * @file
 * Import Many Forms
 */

function manyforms_import_form($form, &$form_state) {
  return array(
    'description' => array(
      '#markup' => 'Hier kan je statussen van Screens orders updaten. '
                 . 'Upload hiertoe een <strong>.zip</strong> of een <strong>.txt</strong> document',
    ),
    'file_upload' => array(
      '#title' => 'Bestand',
      '#type' => 'file',
      '#description' => 'De kolommen worden gescheiden door <strong>tabs</strong>.<br>'
                      . 'Volgende kolommen worden verwacht en en deze volgorde:<br>'
                      . '"Klant" "orderbon" "Datum order" "Omschrijving" "Referentie" "Fase leverings" "Aantal"     "bedrag" "leverconditie"',
    ),
    'submit' => array(
      '#type' => "submit",
      "#value" => "Importeer statussen",
    ),
  );
}

function manyforms_import_form_submit($form, &$form_state) {
  $file = file_save_upload('file_upload', array(
    'file_validate_extensions' => array('txt', 'zip'),
  ));

  if($file) {
    $delimiter = "\t";
    $table = FENEKO_SCREENS_ORDER_STATUSES_TABLE;

    // Open the file.
    $handle = fopen($file->uri, "r");

    // Skip the header and the empty line
    fgetcsv($handle, 0, $delimiter);
    fgetcsv($handle, 0, $delimiter);

    $num_inserted = 0;
    $num_updated  = 0;

    // Loop through the csv file and insert into database.
    while ($data = fgetcsv($handle, 0, $delimiter)) {
      $fields = array(
        'klant'         => trim(drupal_convert_to_utf8($data[0], 'Windows-1252')),
        'orderbon'      => trim(drupal_convert_to_utf8($data[1], 'Windows-1252')),
        'ref'           => trim(drupal_convert_to_utf8($data[4], 'Windows-1252')),
        'omschrijving'  => trim(drupal_convert_to_utf8($data[3], 'Windows-1252')),
        'order_datum'   => trim(drupal_convert_to_utf8($data[2], 'Windows-1252')),
        'lever_datum'   => trim(drupal_convert_to_utf8($data[6], 'Windows-1252')),
        'fase'          => trim(drupal_convert_to_utf8($data[5], 'Windows-1252')),
        'aantal'        => trim(drupal_convert_to_utf8($data[7], 'Windows-1252')),
        'bedrag'        => str_replace(',', '.', trim(drupal_convert_to_utf8($data[8], 'Windows-1252'))) ,
        'leverconditie' => trim(drupal_convert_to_utf8($data[9], 'Windows-1252')),
      );

      $dt = DateTime::createFromFormat('d/m/Y', $fields['order_datum']);
      $fields['order_datum'] = $dt->getTimestamp();

      $dt = DateTime::createFromFormat('d/m/Y', $fields['lever_datum']);
      $fields['lever_datum'] = $dt->getTimestamp();

      $type = db_merge($table)->key(array('orderbon' => $fields['orderbon']))
                              ->fields($fields)->execute();

      // Increment the counters
      switch ($type) {
        case MergeQuery::STATUS_INSERT: $num_inserted++; break;
        case MergeQuery::STATUS_UPDATE: $num_updated++;  break;
      }
    }
    fclose($handle);

    $msg_ins = t('Er werden :num statussen toegevoegd.', array(':num' => $num_inserted));
    $msg_upd = t('Er werden :num statussen aangepast.' , array(':num' => $num_updated));

    drupal_set_message($msg_ins);
    drupal_set_message($msg_upd);

  } else {
    drupal_set_message(t('Er werd geen bestand meegegeven.'));
  }
}
