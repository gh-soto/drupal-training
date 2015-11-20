<?php
/**
 * @file
 * test_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function test_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|review|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'main',
    'weight' => '46',
    'children' => array(
      0 => 'body',
      1 => 'field_movie',
      2 => 'field_author_link',
      3 => 'title',
      4 => 'field_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main|node|review|form'] = $field_group;

  return $export;
}
