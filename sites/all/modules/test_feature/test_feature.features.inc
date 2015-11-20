<?php
/**
 * @file
 * test_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function test_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function test_feature_node_info() {
  $items = array(
    'review' => array(
      'name' => t('review'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
