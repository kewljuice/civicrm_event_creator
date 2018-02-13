# About

This is a simple Drupal module to create/edit non active CiviCRM events as a Drupal user. It also provides the 'creator_extend_form_alter' hook to extend the event form.

# Installation
This module and sub-module(s) are installed as any other Drupal module.

- with drush:
```drush pm-enable -y civicrm_event_creator```

# Usage

- Overview (admin/events/manage)

- Create event (admin/events/create)

- Alter existing event (admin/events/edit/X)

# Permission

Provided in the module is a simple permission "Access Civicrm Event Creator" to access content for this module.

# Extend

- Create new module, in the .module file 

```
<?php
/**
 * Implements creator_extend_form_alter().
 */
function my_module_creator_extend_form_alter(&$form, $default) {
  // Add custom 'events' fields.
  $form['event']['custom_1'] = [
    '#type' => 'textfield',
    '#title' => t('Custom 1'),
    '#attributes' => ['placeholder' => t('Custom 1'),],
    '#required' => TRUE,
    '#default_value' => (isset($default['custom_1']) ? $default['custom_1'] : NULL),
  ];
}

/**
 * Implements creator_extend_form_submit_alter().
 */
function my_module_creator_extend_form_alter(&$form_state, $params) {
    $params['custom_1'] = strtoupper($params['custom_1']);
}
```