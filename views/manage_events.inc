<?php
$view = new view();
$view->name = 'manage_events';
$view->description = 'Manage events';
$view->tag = 'CTRL, CiviCRM';
$view->base_table = 'civicrm_event';
$view->human_name = 'Manage CiviCRM events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Events: manage';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access civicrm_event_creator';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
'id' => 'id',
'title' => 'title',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
'id' => array(
'sortable' => 0,
'default_sort_order' => 'asc',
'align' => '',
'separator' => '',
'empty_column' => 0,
),
'title' => array(
'sortable' => 0,
'default_sort_order' => 'asc',
'align' => '',
'separator' => '',
'empty_column' => 0,
),
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<a href="/admin/events/create">Create event</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Field: CiviCRM Events: Event ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['id']['field'] = 'id';
/* Field: CiviCRM Events: Is Active */
$handler->display->display_options['fields']['is_active']['id'] = 'is_active';
$handler->display->display_options['fields']['is_active']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['is_active']['field'] = 'is_active';
$handler->display->display_options['fields']['is_active']['not'] = 0;
/* Field: CiviCRM Events: Event Type */
$handler->display->display_options['fields']['event_type']['id'] = 'event_type';
$handler->display->display_options['fields']['event_type']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['event_type']['field'] = 'event_type';
/* Field: CiviCRM Events: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Event Title';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Manage';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/admin/events/edit/[id]">Edit event</a>';
/* Filter criterion: CiviCRM Events: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'civicrm_event';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Search';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'key';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
2 => '2',
1 => 0,
3 => 0,
4 => 0,
);

/* Display: Overview */
$handler = $view->new_display('page', 'Overview', 'page');
$handler->display->display_options['path'] = 'admin/events/manage';