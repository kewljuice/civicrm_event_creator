<?php

/**
 * Implements hook_form().
 */
function civicrm_event_creator_manage_form($form, &$form_state) {
  $default = _civicrm_event_creator_default();
  // Block editing active events.
  $lock = FALSE;
  if ($default['is_active']) {
    drupal_set_message(t("You can't edit an active event."), 'status');
    $lock = TRUE;
  }
  // Help.
  $form['help'] = [
    '#type' => 'fieldset',
    '#title' => t('Help'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];
  $form['help']['text'] = [
    '#markup' => t("Here you can create or edit a CiviCRM event"),
  ];
  // Event.
  $form['event'] = [
    '#type' => 'fieldset',
    '#title' => t('Event'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#disabled' => $lock,
  ];
  // Set tree=true for passing arrays.
  $form['event']['#tree'] = TRUE;
  // Component for ID.
  if (isset($default['id'])) {
    $form['event']['id'] = [
      '#type' => 'textfield',
      '#title' => t('ID'),
      '#default_value' => (isset($default['id']) ? $default['id'] : NULL),
      '#attributes' => ['disabled' => 'disabled',],
    ];
  }
  // Component for event_type_id.
  $form['event']['event_type_id'] = [
    '#type' => 'radios',
    '#title' => t('Event type ID'),
    '#options' => _civicrm_event_creator_option_group('event_type'),
    '#default_value' => (isset($default['event_type_id']) ? $default['event_type_id'] : NULL),
    '#required' => TRUE,
  ];
  // Component for default_role_id.
  $form['event']['default_role_id'] = [
    '#type' => 'radios',
    '#title' => t('Default role ID'),
    '#options' => _civicrm_event_creator_option_group('participant_role'),
    '#default_value' => (isset($default['default_role_id']) ? $default['default_role_id'] : NULL),
    '#required' => TRUE,
  ];
  // Component for title.
  $form['event']['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#attributes' => ['placeholder' => t('Title for your event'),],
    '#default_value' => (isset($default['title']) ? $default['title'] : NULL),
    '#required' => TRUE,
  ];
  // Component for summary.
  $form['event']['summary'] = [
    '#type' => 'textarea',
    '#title' => t('Summary'),
    '#attributes' => ['placeholder' => t('Summary for your event'),],
    '#default_value' => (isset($default['summary']) ? $default['summary'] : NULL),
  ];
  // Component for description.
  $form['event']['description'] = [
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#default_value' => (isset($default['description']) ? $default['description'] : NULL),
    '#format' => 'filtered_html',
  ];
  // Component for start_date.
  $form['event']['start_date'] = [
    '#type' => 'date_popup',
    '#title' => t('Start date'),
    '#default_value' => (isset($default['start_date']) ? $default['start_date'] : NULL),
    '#date_format' => 'Y-m-d H:i',
    '#required' => TRUE,
    '#date_year_range' => 'now:+100',
  ];
  // Component for start_date.
  $form['event']['end_date'] = [
    '#type' => 'date_popup',
    '#title' => t('End date'),
    '#default_value' => (isset($default['end_date']) ? $default['end_date'] : NULL),
    '#date_format' => 'Y-m-d H:i',
    '#required' => TRUE,
    '#date_year_range' => 'now:+100',
  ];
  // Conditional for location.
  $form['location_check'] = [
    '#type' => 'radios',
    '#default_value' => (isset($default['location_check']) ? $default['location_check'] : NULL),
    '#options' => [
      'existing' => t('Use existing location'),
      'new' => t('Create new location'),
    ],
    '#title' => t('Location'),
    '#disabled' => $lock,
  ];
  // Component for existing location.
  $form['location']['loc_block_id'] = [
    '#title' => t('Existing location'),
    '#type' => 'select',
    '#description' => 'Select the desired location.',
    '#states' => [
      'visible' => [
        ':input[name="location_check"]' => ['value' => 'existing'],
      ],
    ],
    '#default_value' => (isset($default['loc_block_id']) ? $default['loc_block_id'] : NULL),
    '#options' => _civicrm_event_loc_blocks(),
    '#required' => TRUE,
    '#disabled' => $lock,
  ];
  // Component for new location.
  $form['location']['new'] = [
    '#type' => 'fieldset',
    '#title' => t('New Location'),
    '#states' => [
      'visible' => [
        ':input[name="location_check"]' => ['value' => 'new'],
      ],
      '#states' => [
        'required' => [
          ':input[name="location_check"]' => ['value' => 'new'],
        ],
      ],
    ],
  ];
  // Set tree=true for passing arrays.
  $form['location']['#tree'] = TRUE;
  // Component for new location: name.
  $form['location']['new']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#attributes' => ['placeholder' => t('Descriptive name'),],
    '#states' => [
      'required' => [
        ':input[name="location_check"]' => ['value' => 'new'],
      ],
    ],
    '#disabled' => $lock,
  ];
  // Component for new location: street_address.
  $form['location']['new']['street_address'] = [
    '#type' => 'textfield',
    '#title' => t('Street + number'),
    '#attributes' => ['placeholder' => t('Street + number'),],
    '#states' => [
      'required' => [
        ':input[name="location_check"]' => ['value' => 'new'],
      ],
    ],
  ];
  // Component for new location: postal_code.
  $form['location']['new']['postal_code'] = [
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#attributes' => ['placeholder' => t('Postal code'),],
    '#states' => [
      'required' => [
        ':input[name="location_check"]' => ['value' => 'new'],
      ],
    ],
  ];
  // Component for new location: city.
  $form['location']['new']['city'] = [
    '#type' => 'textfield',
    '#title' => t('City'),
    '#attributes' => ['placeholder' => t('City'),],
    '#states' => [
      'required' => [
        ':input[name="location_check"]' => ['value' => 'new'],
      ],
    ],
  ];
  // Component for new location: country_id.
  $form['location']['new']['country_id'] = [
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#attributes' => ['placeholder' => t('Country'),],
    '#states' => [
      'required' => [
        ':input[name="location_check"]' => ['value' => 'new'],
      ],
    ],
  ];
  // Add possibility to extend this form.
  drupal_alter('creator_extend_form', $form, $default);
  // Submit.
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Save',
    '#disabled' => $lock,
  ];
  // Return.
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function civicrm_event_creator_manage_form_validate($form, &$form_state) {
  if ($form_state['values']['location_check'] == 'new') {
    if (empty($form_state['values']['location']['new']['name'])
      || empty($form_state['values']['location']['new']['street_address'])
      || empty($form_state['values']['location']['new']['postal_code'])
      || empty($form_state['values']['location']['new']['city'])
      || empty($form_state['values']['location']['new']['country_id'])) {
      // Show error.
      form_set_error('location', t('Please enter all required Location fields.'));
    }
  }
}

/**
 * Implements hook_form_submit().
 */
function civicrm_event_creator_manage_form_submit($form, &$form_state) {
  // Fetch submitted values for 'event'.
  $params = $form_state['values']['event'];
  // Set value for is_active.
  $params['is_active'] = FALSE;
  // Get value from description.
  $params['description'] = $params['description']['value'];
  // Check Location for 'new' address.
  if (isset($form_state['values']['location_check']) && $form_state['values']['location_check'] == 'new') {
    // Fetch submitted values for 'location'.
    $address_params = $form_state['values']['location']['new'];
    $address_params["contact_id"] = "user_contact_id";
    $address_params["location_type_id"] = "Main";
    // Create Address via CiviCRM API.
    try {
      civicrm_initialize();
      $address = civicrm_api3('Address', 'create', $address_params);
    } catch (Exception $e) {
      watchdog('civicrm_event_creator_manage_form_submit', print_r($e, TRUE));
    }
    if (!$address['is_error']) {
      // Create LocBlock via CiviCRM API.
      try {
        civicrm_initialize();
        $locblock = civicrm_api3('LocBlock', 'create', ['address_id' => $address['id'],]);
      } catch (Exception $e) {
        watchdog('civicrm_event_creator_manage_form_submit', print_r($e, TRUE));
      }
      if (!$locblock['is_error']) {
        $params['loc_block_id'] = $locblock['id'];
      }
    }
  }
  // Update Location for 'existing' address.
  if (isset($form_state['values']['location_check']) && $form_state['values']['location_check'] == 'existing') {
    if (isset($form_state['values']['location']['loc_block_id'])) {
      $params['loc_block_id'] = $form_state['values']['location']['loc_block_id'];
    }
  }
  // Create Event via CiviCRM API.
  try {
    civicrm_initialize();
    $result = civicrm_api3('Event', 'create', $params);
  } catch (Exception $e) {
    watchdog('civicrm_event_creator_manage_form_submit', print_r($e, TRUE));
  }
  // Show message.
  drupal_set_message(t('The form has been submitted.'));
}

/**
 * Helper to fetch option group values.
 */
function _civicrm_event_creator_option_group($name) {
  $values = [];
  try {
    civicrm_initialize();
    $result = civicrm_api3('OptionValue', 'get', [
      'option_group_id' => $name,
      'is_active' => 1,
    ]);
  } catch (Exception $e) {
    watchdog('_civicrm_event_creator_fetch_option_group', print_r($e, TRUE));
  }
  if (!$result["is_error"]) {
    foreach ($result['values'] as $value) {
      $values[$value['value']] = $value['label'];
    }
  }
  return $values;
}

/**
 * Helper to set default values.
 */
function _civicrm_event_creator_default() {
  // Check for event_id in url.
  $eid = arg(3);
  if (isset($eid)) {
    $default['id'] = $eid;
    // Fetch 'default' event data.
    try {
      civicrm_initialize();
      $result = civicrm_api3('Event', 'getsingle', ['id' => $eid,]);
      $default = $result;
    } catch (Exception $e) {
      watchdog('_civicrm_event_creator_default', print_r($e, TRUE));
    }
  }
  // Check if location is set.
  $default['location_check'] = NULL;
  if (isset($default['loc_block_id'])) {
    $default['location_check'] = 'existing';
  }
  // Return.
  return $default;
}

/**
 * Helper to set default values.
 */
function _civicrm_event_loc_blocks() {
  // Set defaults.
  $values = [];
  try {
    civicrm_initialize();
    $location = civicrm_api3('LocBlock', 'get', []);
  } catch (Exception $e) {
    watchdog('_civicrm_event_loc_blocks', print_r($e, TRUE));
  }
  if (!$location["is_error"]) {
    foreach ($location['values'] as $loc) {
      if (isset($loc['address_id'])) {
        try {
          civicrm_initialize();
          $address = civicrm_api3('Address', 'getSingle', ['id' => $loc['address_id'],]);
        } catch (Exception $e) {
          watchdog('_civicrm_event_loc_blocks', print_r($e, TRUE));
        }
        $values[$loc['id']] = $address['name'];
      }
    }
  }
  // Return.
  return $values;
}
