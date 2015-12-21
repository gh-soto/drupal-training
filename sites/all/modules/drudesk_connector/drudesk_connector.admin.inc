<?php

/**
 * @file
 * Provide all the administration pages
 */

/**
 * Builds the drudesk_connector_configure settings form.
 */
function drudesk_connector_configure($form, &$form_state) {
  $form = array();
  $form['drudesk_connector_uniq_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Unique key'),
    '#required' => TRUE,
    '#disabled' => TRUE,
    '#default_value' => !empty($form_state['input']['drudesk_connector_uniq_key']) ? $form_state['input']['drudesk_connector_uniq_key'] : variable_get('drudesk_connector_uniq_key', ''),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate key'),
    '#submit' => array('drudesk_connector_configure_form_submit'),
  );
  return ($form);
}

/**
 * Submit callback for drudesk_connector_page_settings().
 */
function drudesk_connector_configure_form_submit($form, &$form_state) {
  $site_name = variable_get('site_name', "drudesk");

  if (!preg_match("/^[\w ]+$/i", $site_name)) {
    $site_name = 'drudesk';
    } 

  $site_name = substr($site_name, 0, 7);
  $unique_key = uniqid($site_name, true);
  variable_set('drudesk_connector_uniq_key', $unique_key);
  drupal_set_message(t('Your configuration has been saved.'));
}
