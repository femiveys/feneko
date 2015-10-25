<?php
/**
 * @file
 * feneko_translations.features.translations_fr.inc
 */

/**
 * Implements hook_translations_fr_defaults().
 */
function feneko_translations_translations_fr_defaults() {
  $translations = array();
  $translatables = array();
  $translations['fr:commerce']['dabd8232b9d6575cd581f0815cf9c908'] = array(
    'source' => '<p>Je bestellingsnummer is: [commerce-order:order-number].</p>
<p>Je kan je <a href="[commerce-order:url]">bestelling bekijken</a> op je profiel.</p>
<p><a href="/cart/init">Bestel iets anders</a></p>',
    'context' => 'checkout:complete:message',
    'location' => 'commerce:checkout:complete:message',
    'translation' => '<p>Ton numéro de ordre est : [commerce-order:order-number].</p><p>Vous pouvez regarder vorte commande sur: <a href="/user/[commerce-order:uid]/feneko_orders">Ordres en cours</a> sur ton profil.</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p>Je bestellingsnummer is: [commerce-order:order-number].</p>
<p>Je kan je <a href="[commerce-order:url]">bestelling bekijken</a> op je profiel.</p>
<p><a href="/cart/init">Bestel iets anders</a></p>', array(), array('context' => 'checkout:complete:message'));
  $translations['fr:default']['09bc5f9df1cb5ea352fb427ef7a8080a'] = array(
    'source' => 'Plaats bestelling',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Placer la commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Plaats bestelling', array(), array('context' => ''));
  $translations['fr:default']['0b080119cbf1138edfa9132471e1a661'] = array(
    'source' => 'tot',
    'context' => '',
    'location' => '/nl/user/1/feneko_orders',
    'translation' => 'au',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('tot', array(), array('context' => ''));
  $translations['fr:default']['10b9486648b56ba44ab65c59df05dde5'] = array(
    'source' => 'Borstelprofiel VP1200',
    'context' => '',
    'location' => '/nl/vliegenraam-basic/bestel',
    'translation' => 'Profil de Brosse VP1200',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Borstelprofiel VP1200', array(), array('context' => ''));
  $translations['fr:default']['1c5a2314986393f826e7b3cb308731ae'] = array(
    'source' => 'Bereken korting',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Calculer la remise',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bereken korting', array(), array('context' => ''));
  $translations['fr:default']['1d03e968c40b69c6e88fefbe5833f517'] = array(
    'source' => 'Leverdatum',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Date de livraison',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Leverdatum', array(), array('context' => ''));
  $translations['fr:default']['25e3ae7384d662b1039dbd72d4cae42d'] = array(
    'source' => 'Klantennummer',
    'context' => 'field_klantennummer:user:label',
    'location' => '/nl/admin/structure/features/feneko_translations/status',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer', array(), array('context' => 'field_klantennummer:user:label'));
  $translations['fr:default']['2b05b5c27bba6e3b572e41fc7100e765'] = array(
    'source' => 'Opgepast! Meerprijs.',
    'context' => '',
    'location' => '/nl/cart/init?destination=node/426',
    'translation' => 'Attention! Frais supplémentaires.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Opgepast! Meerprijs.', array(), array('context' => ''));
  $translations['fr:default']['2d709a3eeddf7d0b6785b6c2547d3b97'] = array(
    'source' => 'Het midden van de tussenstijl (VP1005) komt op 917mm.<br />
                   Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                   Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.',
    'context' => '',
    'location' => '/nl/admin/feneko_screens/overview',
    'translation' => 'Le milieu de la traverse (VP1005) se trouve à 917mm.<br />
Si vous voulez la traverse sur une autre hauteur, vous remplissez le T1.<br />
Si vous voulez plusieurs traverses vous remplissez le T1,T2,T3.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Het midden van de tussenstijl (VP1005) komt op 917mm.<br />
                   Indien u de hoogte zelf wenst te kiezen vult u T1 in.<br />
                   Indien u meerdere tussenstijlen wenst vult u T1,T2, T3 in.', array(), array('context' => ''));
  $translations['fr:default']['4c5c21ffe644c221c6ff6b508587a4da'] = array(
    'source' => 'Lopende orders',
    'context' => '',
    'location' => '/user',
    'translation' => 'Commandes en cours',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Lopende orders', array(), array('context' => ''));
  $translations['fr:default']['6b0002988bab985c49e64959cd3f39d3'] = array(
    'source' => 'Kleur',
    'context' => 'field_color:commerce_order:label',
    'location' => '/nl/admin/structure/features/feneko_translations/status',
    'translation' => 'Couleur',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Kleur', array(), array('context' => 'field_color:commerce_order:label'));
  $translations['fr:default']['6e419ce654124356fd3bd39fb144557a'] = array(
    'source' => 'Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.',
    'context' => '',
    'location' => '/nl/forms/form13',
    'translation' => 'La largeur du panneau de la porte moustiquaire coulissante.<br />Hauteur de la porte moustiquaire coulissante, rails inclus.<br />Longueurs des rails.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Breedtemaat van het vliegenschuifdeurblad.<br />Totale hoogte inclusief geleiders van de schuifdeur.<br />Lengte van de geleiders.', array(), array('context' => ''));
  $translations['fr:default']['7177fee9c196a572b9e3e1787336ee47'] = array(
    'source' => 'Standaardprofiel',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Profil standard',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Standaardprofiel', array(), array('context' => ''));
  $translations['fr:default']['7fb4910b2b2641a6da46bf06921a2085'] = array(
    'source' => 'Er zijn geen bestellingen in behandeling.',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Il n\'y a pas d\'ordres en cours',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Er zijn geen bestellingen in behandeling.', array(), array('context' => ''));
  $translations['fr:default']['816a78c8472f3f298a3a7bdf8d8013f2'] = array(
    'source' => 'Besteldatum',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Date d\'ordre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Besteldatum', array(), array('context' => ''));
  $translations['fr:default']['8afa46be81acd3d7987f688c0bc3744b'] = array(
    'source' => 'Bereken korting (Stap 1/2)',
    'context' => '',
    'location' => '/nl/cart',
    'translation' => 'Calculer la remise (Étappe 1/2)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bereken korting (Stap 1/2)', array(), array('context' => ''));
  $translations['fr:default']['957d2fa52c19a5aff4ccf5d9a959adab'] = array(
    'source' => 'van',
    'context' => '',
    'location' => '/nl/user/1/feneko_orders',
    'translation' => 'de',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('van', array(), array('context' => ''));
  $translations['fr:default']['9e35cea985142d1f600543586e2e8ede'] = array(
    'source' => 'Klantennummers',
    'context' => '',
    'location' => '/nl/admin/structure/features',
    'translation' => 'Numéros de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummers', array(), array('context' => ''));
  $translations['fr:default']['a9a39524393245a842a5d6694f22ee6f'] = array(
    'source' => 'Leverconditie',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Condition de livraison',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Leverconditie', array(), array('context' => ''));
  $translations['fr:default']['c11e09df1574eed40e1f075f5fdd717f'] = array(
    'source' => 'Schuifvliegendeuren Elegance+',
    'context' => '',
    'location' => '/nl/admin/feneko_screens/overview',
    'translation' => 'Porte Moustiquaire coulissante Élégance+',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Schuifvliegendeuren Elegance+', array(), array('context' => ''));
  $translations['fr:default']['c5ea47e90c480be70ab8fce6259581ac'] = array(
    'source' => 'Klantennummer (field_klantennummer)',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer (field_klantennummer)', array(), array('context' => ''));
  $translations['fr:default']['c981adbb277d46d8e3ed26497b7ee096'] = array(
    'source' => 'Klantennummer',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Numéro de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummer', array(), array('context' => ''));
  $translations['fr:default']['d4d537cf9231306d75c5d2aba0c22b00'] = array(
    'source' => 'Bedrag',
    'context' => '',
    'location' => '/nl/user/1/feneko_screens_orders',
    'translation' => 'Montant',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bedrag', array(), array('context' => ''));
  $translations['fr:default']['dea5d1f08521fb3b04397afb1852595b'] = array(
    'source' => 'Kleur',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'Couleur',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Kleur', array(), array('context' => ''));
  $translations['fr:default']['e2ee5db3726b7f8f02b1b5c3a782874c'] = array(
    'source' => 'Tekens die in de referentie voorkomen',
    'context' => '',
    'location' => '/nl/user/1/feneko_orders',
    'translation' => 'Caractères dans la référence',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tekens die in de referentie voorkomen', array(), array('context' => ''));
  $translations['fr:default']['e5d49efb309c6145571b8e05c7428e68'] = array(
    'source' => 'Orderdatum',
    'context' => '',
    'location' => '/nl/user/124/feneko_screens_orders',
    'translation' => 'Date de commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Orderdatum', array(), array('context' => ''));
  $translations['fr:default']['ed36982788a88ca96078aaeb959f9c29'] = array(
    'source' => 'Screens bestellingen',
    'context' => '',
    'location' => '/nl/user/1',
    'translation' => 'Commandes screens',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Screens bestellingen', array(), array('context' => ''));
  $translations['fr:default']['f72c162cd7524cfcd8df67a5a5ed6d39'] = array(
    'source' => 'Gaatjes',
    'context' => 'field_ophanging:#allowed_values:gaatjes',
    'location' => '/nl/admin/structure/features/feneko_translations',
    'translation' => 'Trous',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes', array(), array('context' => 'field_ophanging:#allowed_values:gaatjes'));
  $translations['fr:field']['0416b5af0fe66004270bbab826dd9727'] = array(
    'source' => 'Gaatjes in rug',
    'context' => 'field_gaatjes_rug:raamtablet:label',
    'location' => 'field:field_gaatjes_rug:raamtablet:label',
    'translation' => 'Trous dans le dos',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes in rug', array(), array('context' => 'field_gaatjes_rug:raamtablet:label'));
  $translations['fr:field']['5fb78386d474916f06fce099e170a82a'] = array(
    'source' => 'Bestelling',
    'context' => 'field_order_type:#allowed_values:order',
    'location' => 'field:field_order_type:#allowed_values:order',
    'translation' => 'Commande',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bestelling', array(), array('context' => 'field_order_type:#allowed_values:order'));
  $translations['fr:field']['667d5390b792b72a634adf0215ae9045'] = array(
    'source' => 'Klantennummers',
    'context' => 'field_klantennummer:user:label',
    'location' => 'field:field_klantennummer:user:label',
    'translation' => 'Numéros de client',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Klantennummers', array(), array('context' => 'field_klantennummer:user:label'));
  $translations['fr:field']['affb9247a339b7a31f3680f2ea1e6a82'] = array(
    'source' => 'Haakjes',
    'context' => 'field_ophanging:#allowed_values:haakjes',
    'location' => 'field:field_ophanging:#allowed_values:haakjes',
    'translation' => 'Crochets',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Haakjes', array(), array('context' => 'field_ophanging:#allowed_values:haakjes'));
  $translations['fr:field']['ca6b5213eae4d8d0d4cd96dda1d4ed58'] = array(
    'source' => 'Z-profiel',
    'context' => 'field_standaardprofiel_type:#allowed_values:Z',
    'location' => 'field:field_standaardprofiel_type:#allowed_values:Z',
    'translation' => 'Profil-Z',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Z-profiel', array(), array('context' => 'field_standaardprofiel_type:#allowed_values:Z'));
  $translations['fr:field']['dec81d11cc6b2d233141e79ddd671bb9'] = array(
    'source' => 'Offerte',
    'context' => 'field_order_type:#allowed_values:offer',
    'location' => 'field:field_order_type:#allowed_values:offer',
    'translation' => 'Offre',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Offerte', array(), array('context' => 'field_order_type:#allowed_values:offer'));
  $translations['fr:field']['f47812f22bf86412bafc09c6bcbd4589'] = array(
    'source' => 'U-profiel',
    'context' => 'field_standaardprofiel_type:#allowed_values:U',
    'location' => 'field:field_standaardprofiel_type:#allowed_values:U',
    'translation' => 'Profil-U',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('U-profiel', array(), array('context' => 'field_standaardprofiel_type:#allowed_values:U'));
  $translations['fr:field']['f72c162cd7524cfcd8df67a5a5ed6d39'] = array(
    'source' => 'Gaatjes',
    'context' => 'field_ophanging:#allowed_values:gaatjes',
    'location' => 'field:field_ophanging:#allowed_values:gaatjes',
    'translation' => 'Trous',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Gaatjes', array(), array('context' => 'field_ophanging:#allowed_values:gaatjes'));
  return $translations;
}
