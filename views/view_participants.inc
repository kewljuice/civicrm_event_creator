<?php
$view = new view();
$view->name = 'civicrm_participants';
$view->description = 'Display participants';
$view->tag = 'CTRL, CiviCRM';
$view->base_table = 'civicrm_participant';
$view->human_name = 'View CiviCRM participants';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Events: participants';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access civicrm_event_creator';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
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
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Return to <a href="/admin/events/manage">overview</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No results';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Field: CiviCRM Participants: Participant ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_participant';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Participant';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Events: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'civicrm_event';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Event Title';
$handler->display->display_options['fields']['title']['link_to_civicrm_event'] = 'page';
/* Field: CiviCRM Participants: Participant Role */
$handler->display->display_options['fields']['role']['id'] = 'role';
$handler->display->display_options['fields']['role']['table'] = 'civicrm_participant';
$handler->display->display_options['fields']['role']['field'] = 'role';
/* Field: CiviCRM Participants: Participant Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'civicrm_participant';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: CiviCRM Contributions: Contribution Status */
$handler->display->display_options['fields']['contribution_status']['id'] = 'contribution_status';
$handler->display->display_options['fields']['contribution_status']['table'] = 'civicrm_contribution';
$handler->display->display_options['fields']['contribution_status']['field'] = 'contribution_status';
/* Contextual filter: CiviCRM Events: Event ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_event';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Contributions: Financial Type */
$handler->display->display_options['filters']['financial_type']['id'] = 'financial_type';
$handler->display->display_options['filters']['financial_type']['table'] = 'civicrm_contribution';
$handler->display->display_options['filters']['financial_type']['field'] = 'financial_type';
$handler->display->display_options['filters']['financial_type']['value'] = array(
  4 => '4',
);

/* Display: Overview */
$handler = $view->new_display('page', 'Overview', 'page');
$handler->display->display_options['path'] = 'admin/events/participants';
