<?php
/**
 * @file
 * test_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function test_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'reviews_for_movies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'reviews for movies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'reviews';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: movie (field_movie) */
  $handler->display->display_options['relationships']['field_movie_nid']['id'] = 'field_movie_nid';
  $handler->display->display_options['relationships']['field_movie_nid']['table'] = 'field_data_field_movie';
  $handler->display->display_options['relationships']['field_movie_nid']['field'] = 'field_movie_nid';
  $handler->display->display_options['relationships']['field_movie_nid']['delta'] = '-1';
  /* Field: Content: movie */
  $handler->display->display_options['fields']['field_movie']['id'] = 'field_movie';
  $handler->display->display_options['fields']['field_movie']['table'] = 'field_data_field_movie';
  $handler->display->display_options['fields']['field_movie']['field'] = 'field_movie';
  /* Field: Content: genres */
  $handler->display->display_options['fields']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['table'] = 'field_data_field_genre';
  $handler->display->display_options['fields']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['relationship'] = 'field_movie_nid';
  $handler->display->display_options['fields']['field_genre']['label'] = '';
  $handler->display->display_options['fields']['field_genre']['element_type'] = 'h5';
  $handler->display->display_options['fields']['field_genre']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_genre']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_genre']['delta_offset'] = '0';
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity_1']['bypass_access'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  /* Field: Content: five stars review */
  $handler->display->display_options['fields']['field_five_stars_review']['id'] = 'field_five_stars_review';
  $handler->display->display_options['fields']['field_five_stars_review']['table'] = 'field_data_field_five_stars_review';
  $handler->display->display_options['fields']['field_five_stars_review']['field'] = 'field_five_stars_review';
  $handler->display->display_options['fields']['field_five_stars_review']['label'] = '';
  $handler->display->display_options['fields']['field_five_stars_review']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_five_stars_review']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_five_stars_review']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/fivestar/widgets/basic/basic.css',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'user',
  );
  /* Field: Content: date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'review' => 'review',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';

  /* Display: Reviews Page */
  $handler = $view->new_display('page', 'Reviews Page', 'review_page');
  $handler->display->display_options['use_ajax_flags'] = array(
    'bookmarks' => 'bookmarks',
    'review_node_flag' => 0,
  );
  $handler->display->display_options['path'] = 'reviews';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'reviews';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['reviews_for_movies'] = $view;

  return $export;
}
