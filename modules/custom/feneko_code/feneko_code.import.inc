<?php
function feneko_code_import_form($form, &$form_state) {
  $csv = '<li>Upload een bestand in <strong>CSV</strong> '
       . 'formaat (gescheiden door <strong>punt-comma\'s</strong>).</li>';
  $txt = '<li>Upload een bestand in <strong>.zip</strong> of <strong>.txt</strong> '
       . 'formaat (gescheiden door een <strong>tabs</strong>).</li>';
  $ral         = "<ul>$csv<li>Velden: kleurcode;poedercode;type</li></ul>";
  $renolit     = "<ul>$csv<li>Velden: id;kleurcode;omschrijving</li></ul>";
  $utilo       = "<ul>$csv<li>Velden: ?;referentie;omschrijving</li></ul>";
  $geblokkeerd = "<ul>$csv<li>Velden: klantennummer;geblokkeerd_J/N</li></ul>";
  $statuses    = "<ul>$txt<li>Velden: 'Klant' 'orderbon' 'Orderdatum' 'Omschrijving' "
               . "'Referentie' 'Fase' 'Leverdatum' 'Aantal' 'bedrag' 'leverconditie' 'kleur'</li></ul>";

  $mapping = array(
    'ral'                            => $ral,
    'renolit'                        => $renolit,
    'utilo'                          => $utilo,
    'field_data_field_geblokkeerd'   => $geblokkeerd,
    FENEKO_CODE_ORDER_STATUSES_TABLE => $statuses,
  );

  $manual = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('manual')),
    'title' => array(
      '#markup' => '<h2>Aanwijzingen voor formaat</h2>',
    ),
    'empty' => array(
      '#type' => 'container',
      'markup' => array('#markup' => 'Selecteer een Type upload'),
      '#states' => array(
        'visible' => array('input[name="type"]' => array('value' => FALSE)),
      ),
    ),
  );
  foreach ($mapping as $table => $markup) {
    $manual[$table] = array(
      '#type' => 'container',
      'markup' => array('#markup' => $markup),
      '#states' => array(
        'visible' => array('input[name="type"]' => array('value' => $table)),
      ),
    );
  }

  return array(
    'manual' => $manual,
    'type' => array(
      '#type' => "radios",
      '#title' => 'Type upload',
      '#options' => array(
        'ral'                            => 'RAL codes',
        'renolit'                        => 'Renolit codes',
        'utilo'                          => 'Utilo profielen',
        'field_data_field_geblokkeerd'   => 'Geblokkeerd/EB',
        FENEKO_CODE_ORDER_STATUSES_TABLE => 'Statussen Orders',
      ),
      '#required' => true,
    ),
    'file_upload' => array(
      '#title' => 'Bestand',
      '#type' => 'file',
    ),
    'header' => array(
      '#type' => "checkbox",
      '#title' => 'De eerste lijn overslaan',
      '#description' => 'Het kan dat de eerste lijn de kolom namen bevat. Vink '
                      . 'deze optie aan indien de eerste lijn overgeslaan moet worden.',
      '#states' => array(
        'invisible' => array(
          'input[name="type"]' => array('value' => FENEKO_CODE_ORDER_STATUSES_TABLE),
        ),
      ),
    ),
    'submit' => array(
      '#type' => "submit",
      "#value" => "Importeer",
    ),
  );
}

function feneko_code_import_form_submit($form, &$form_state) {
  $settings = array(
    'extensions' => array(
      'all' => array('csv'),
      'statuses' => array('txt', 'zip'),
    ),
    'delimiter' => array(
      'all' => ';',
      'statuses' => "\t",
      'statuses' => ";",
    ),
  );

  $table = $form_state['values']['type'];

  $type = $table === FENEKO_CODE_ORDER_STATUSES_TABLE ? 'statuses' : 'all';

  $file = file_save_upload('file_upload', array(
    'file_validate_extensions' => $settings['extensions'][$type],
  ));

  if($file) {
    // Open the file.
    $handle = fopen($file->uri, "r");

    // Skip the header if needed
    if($form_state['values']['header'] or $type === 'statuses') {
      fgetcsv($handle, 0, $settings['delimiter'][$type]);
    }

    // Skip the emty line for order statuses
    if($type === 'statuses') {
      // fgetcsv($handle, 0, $settings['delimiter'][$type]);
    }

    if($table !== 'field_data_field_geblokkeerd' and $type === 'all') {
      // First clear the table.
      if (db_table_exists($table)) {
        db_truncate($table)->execute();
      }

      $mapping = array(
        'laken std' => 'ral',
        'laken str' => 'str',
        'Laken std' => 'ral',
        'Laken str' => 'str',
      );
    } else {
      $mapping = array('N' => 0, 'J' => 1);
    }

    $num_updated  = 0;
    $num_inserted = 0;

    // Loop through the csv file and insert into database.
    while ($data = fgetcsv($handle, 0, $settings['delimiter'][$type])) {
      switch ($table) {
        case 'ral':
          if(isset($mapping[$data[2]])) {
            $type = $mapping[$data[2]];
          } else {
            $msg = t("Mapping not found for :mapping. Ignored record.", array(':mapping' => $data[2]));
            drupal_set_message($msg, 'warning');
            continue 2;
          }

          $fields = array(
            'kleur' => drupal_convert_to_utf8($data[0], 'Windows-1252'),
            'ref'   => drupal_convert_to_utf8($data[1], 'Windows-1252'),
            'type'  => $type,
          );
          $num_updated += db_insert($table)->fields($fields)->execute();
          break;

        case 'renolit':
          $fields = array(
            'kleur' => drupal_convert_to_utf8($data[2], 'Windows-1252'),
            'ref'   => drupal_convert_to_utf8($data[1], 'Windows-1252'),
          );
          $num_updated += db_insert($table)->fields($fields)->execute();
          break;

        case 'utilo':
          $fields = array(
            'ref'   => drupal_convert_to_utf8($data[1], 'Windows-1252'),
            'descr' => drupal_convert_to_utf8($data[2], 'Windows-1252'),
            // 'lang'  => drupal_convert_to_utf8($data[3], 'Windows-1252'),
            'lang'  => 'nl',
          );
          $num_updated += db_insert($table)->fields($fields)->execute();
          break;

        case 'field_data_field_geblokkeerd':
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'user')
            ->fieldCondition('field_klantennummer', 'value', $data[0]);

          $result = $query->execute();
          $users_ids = array_keys($result['user']);

          foreach ($users_ids as $uid) {
            $user = user_load($uid);
            $wrapper = entity_metadata_wrapper('user', $user);
            $wrapper->field_geblokkeerd = strtr(strtoupper($data[1]), $mapping);
            $wrapper->save();
            $num_updated++;
          }

          break;

        case FENEKO_CODE_ORDER_STATUSES_TABLE:
          $fields = array(
            'klant'         => trim(drupal_convert_to_utf8($data[0], 'Windows-1252')),
            'orderbon'      => trim(drupal_convert_to_utf8($data[1], 'Windows-1252')),
            'ref'           => trim(drupal_convert_to_utf8($data[4], 'Windows-1252')),
            'omschrijving'  => trim(drupal_convert_to_utf8($data[3], 'Windows-1252')),
            'kleur'         => trim(drupal_convert_to_utf8($data[10],'Windows-1252')),
            'order_datum'   => trim(drupal_convert_to_utf8($data[2], 'Windows-1252')),
            'lever_datum'   => trim(drupal_convert_to_utf8($data[6], 'Windows-1252')),
            'fase'          => trim(drupal_convert_to_utf8($data[5], 'Windows-1252')),
            'aantal'        => trim(drupal_convert_to_utf8($data[7], 'Windows-1252')),
            'bedrag'        => str_replace(',', '.', trim(drupal_convert_to_utf8($data[8], 'Windows-1252'))) ,
            'leverconditie' => trim(drupal_convert_to_utf8($data[9], 'Windows-1252')),
          );

// dpm($fields);

          // Skip invalid lines
          if(!_feneko_oderline_is_valid($fields)) {
            continue;
          }

          $dt = DateTime::createFromFormat('d-m-y', $fields['order_datum']);
          $fields['order_datum'] = $dt->getTimestamp();

          $dt = DateTime::createFromFormat('d-m-y', $fields['lever_datum']);
          $fields['lever_datum'] = $dt->getTimestamp();

          $op_type = db_merge($table)->key(array('orderbon' => $fields['orderbon']))
                                     ->fields($fields)->execute();

          // Increment the counters
          switch ($op_type) {
            case MergeQuery::STATUS_INSERT: $num_inserted++; break;
            case MergeQuery::STATUS_UPDATE: $num_updated++;  break;
          }

          break;
      }
    }
    fclose($handle);

    if($type === 'all') {
      if($table === 'field_data_field_geblokkeerd') {
        if($num_updated > 0) {
          $msg = t('Er werden :num gebruikers aangepast.', array(':num' => $num_updated));
        }
      } else {
        $msg = t(':num records werden succesvol geïmporteerd.', array(':num' => $num_updated));
      }

      drupal_set_message($msg);
    } else {
      $msg_ins = t('Er werden :num statussen toegevoegd.', array(':num' => $num_inserted));
      $msg_upd = t('Er werden :num statussen aangepast.' , array(':num' => $num_updated));

      drupal_set_message($msg_ins);
      drupal_set_message($msg_upd);
    }

  } else {
    drupal_set_message(t('Er werd geen bestand meegegeven.'));
  }
}

function _feneko_oderline_is_valid($fields) {
  if(!ctype_digit($fields['klant'])) return false;
  return true;
}