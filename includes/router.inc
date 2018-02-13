<?php

/**
 * Implements hook_permission().
 */
function civicrm_event_creator_permission() {
  return [
    'access civicrm_event_creator' => [
      'title' => t('Access Civicrm Event Creator'),
      'description' => t('Access content for Civicrm Event Creator module'),
    ],
  ];
}

/**
 * Implements hook_menu().
 */
function civicrm_event_creator_menu() {
  $items = [];
  // Endpoint: create event.
  $items['admin/events/create'] = [
    'title' => t('Events: create'),
    'description' => "Create new CiviCRM event",
    'page callback' => 'drupal_get_form',
    'page arguments' => ['civicrm_event_creator_manage_form'],
    'access arguments' => ['access civicrm_event_creator'],
    'type' => MENU_CALLBACK,
  ];
  // Endpoint: edit event.
  $items['admin/events/edit'] = [
    'title' => t('Events: edit'),
    'description' => "Edit CiviCRM event",
    'page callback' => 'drupal_get_form',
    'page arguments' => ['civicrm_event_creator_manage_form'],
    'access arguments' => ['access civicrm_event_creator'],
    'type' => MENU_CALLBACK,
  ];
  return $items;
}
