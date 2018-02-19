<?php

/**
 * Implements hook_form().
 */
function civicrm_event_creator_template_form($form, &$form_state) {
  $default = _civicrm_event_creator_default();
  // Help.
  $form['help'] = [
    '#type' => 'fieldset',
    '#title' => t('Help'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];
  $form['help']['text'] = [
    '#markup' => t("Here you can create or edit a CiviCRM event, or return to <a href='/admin/events/manage'>overview</a>"),
  ];
  // Event.
  $form['event'] = [
    '#type' => 'fieldset',
    '#title' => t('Event'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];
  // Set tree=true for passing arrays.
  $form['event']['#tree'] = TRUE;
  // Component for title.
  $form['event']['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#attributes' => ['placeholder' => t('Title for your event'),],
    '#default_value' => (isset($default['title']) ? $default['title'] : NULL),
    '#required' => TRUE,
  ];
  // Component for template.
  $form['event']['template_id'] = [
    '#type' => 'select',
    '#title' => t('Event template'),
    '#options' => _civicrm_event_creator_event_templates(),
    '#required' => TRUE,
  ];
  // Component for start_date.
  $form['event']['start_date'] = [
    '#type' => 'date_popup',
    '#title' => t('Start date'),
    '#default_value' => date('Y-m-d H:i'),
    '#date_format' => 'Y-m-d H:i',
    '#required' => TRUE,
    '#date_year_range' => 'now:+100',
  ];
  // Component for end_date.
  $form['event']['end_date'] = [
    '#type' => 'date_popup',
    '#title' => t('End date'),
    '#default_value' => date('Y-m-d H:i'),
    '#date_format' => 'Y-m-d H:i',
    '#required' => TRUE,
    '#date_year_range' => 'now:+100',
  ];
  // Submit.
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Save',
  ];
  // Return.
  return $form;
}

/**
 * Implements hook_form_submit().
 */
function civicrm_event_creator_template_form_submit($form, &$form_state) {
  // Fetch submitted values for 'event'.
  $params = $form_state['values']['event'];
  // Set value for is_active.
  $params['is_active'] = FALSE;
  // Create Event via CiviCRM API.
  try {
    civicrm_initialize();
    $result = civicrm_api3('Event', 'create', $params);
  } catch (Exception $e) {
    watchdog('civicrm_event_creator_template_form_submit', print_r($e, TRUE));
  }
  // Show message.
  drupal_set_message(t('The form has been submitted.'));
  // Redirect to overview.
  drupal_goto('/admin/events/manage');
}

/**
 * Helper to fetch option group values.
 */
function _civicrm_event_creator_event_templates() {
  $values = [];
  try {
    civicrm_initialize();
    $result = civicrm_api3('Event', 'get', [
      'is_template' => 1,
    ]);
  } catch (Exception $e) {
    watchdog('_civicrm_event_creator_event_templates', print_r($e, TRUE));
  }
  if (!$result["is_error"]) {
    foreach ($result['values'] as $value) {
      $values[$value['id']] = $value['title'];
    }
  }
  return $values;
}
