<?php

/**
 * @file
 * Make the country as an optional value.
 * If this plugin is active, then the user can submit a really empty address
 * without any data storing into the database. The default value of the country
 * is also set to empty instead of site_default_country.
 */

$plugin = array(
  'title' => t('Make country optional'),
  'format callback' => 'addressfield_format_address_optional_country',
  'type' => 'address',
  'weight' => -80,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_address_optional_country(&$format, &$address, $context = array()) {
  $format['country']['#required'] = FALSE;
  $format['country']['#empty_value'] = '';
}
