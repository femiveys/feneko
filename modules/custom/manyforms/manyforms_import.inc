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
      '#description' => 'De kolommen worden gescheiden door tabs.',
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
        'klant'         => trim($data[0]),
        'orderbon'      => trim($data[1]),
        'ref'           => trim($data[4]),
        'omschrijving'  => trim($data[3]),
        'order_datum'   => trim($data[2]),
        'lever_datum'   => trim($data[6]),
        'fase'          => trim($data[5]),
        'aantal'        => trim($data[7]),
        'bedrag'        => str_replace(',', '.', trim($data[8])) ,
        'leverconditie' => trim($data[9]),
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
