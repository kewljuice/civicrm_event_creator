<?php

/**
 * Implements hook_views_api().
 */
function civicrm_event_creator_views_api() {
  return ['api' => 3.0];
}

/**
 * Implements hook_views_default_views().
 */
function civicrm_event_creator_views_default_views() {
  // Check for all view file in views directory.
  $files = file_scan_directory(drupal_get_path('module', 'civicrm_event_creator') . '/views', '/.*\.inc$/');
  // Add view to list of views.
  $views = [];
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  // At the end, return default views.
  return $views;
}
