<?php
/**
 * @file
 * level2_ex6.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function level2_ex6_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_4c6d373f-51b2-493d-9aa0-48e6d065b6e9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Movies',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'movie' => 'movie',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => array(),
      'center' => array(),
      'middle' => array(
        'style' => '$',
        'settings' => array(
          'name' => '_temporary',
          'style_base' => 'region_rounded_shadow',
          'palette' => array(
            'background' => '#f1aaaa',
            'text' => '#000000',
          ),
          'font' => array(
            'font' => '',
            'size' => '',
            'letter_spacing' => '',
            'word_spacing' => '',
            'decoration' => '',
            'weight' => '',
            'style' => '',
            'variant' => '',
            'case' => '',
            'alignment' => '',
          ),
          'padding' => array(
            'top' => '',
            'right' => '',
            'bottom' => '',
            'left' => '',
          ),
        ),
      ),
    ),
    'style' => 'stylizer',
    'center' => array(
      'style' => 'stylizer',
    ),
    'middle' => array(
      'style' => 'stylizer',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '5a158fb9-1916-4041-8c34-3a54c515e721';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3c8480a-57db-4540-8d0a-d37de276449f';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'teaser',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd3c8480a-57db-4540-8d0a-d37de276449f';
    $display->content['new-d3c8480a-57db-4540-8d0a-d37de276449f'] = $pane;
    $display->panels['middle'][0] = 'new-d3c8480a-57db-4540-8d0a-d37de276449f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_4c6d373f-51b2-493d-9aa0-48e6d065b6e9'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function level2_ex6_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test_panel';
  $page->task = 'page';
  $page->admin_title = 'test-panel';
  $page->admin_description = '';
  $page->path = 'test-panel';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'test-panel',
    'weight' => '0',
    'name' => 'main-menu',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test_panel__panel_context_64eca65a-9062-4caa-990f-be3666f3dbc9';
  $handler->task = 'page';
  $handler->subtask = 'test_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'test-panel';
  $display->uuid = '107b8225-36bf-48c2-b300-a047cf8b4a5e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-219a7738-b2f1-4cff-9ecc-150e318334e7';
    $pane->panel = 'bottom';
    $pane->type = 'views';
    $pane->subtype = 'film';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'films_page',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '219a7738-b2f1-4cff-9ecc-150e318334e7';
    $display->content['new-219a7738-b2f1-4cff-9ecc-150e318334e7'] = $pane;
    $display->panels['bottom'][0] = 'new-219a7738-b2f1-4cff-9ecc-150e318334e7';
    $pane = new stdClass();
    $pane->pid = 'new-b1172a3a-1bf3-43dd-a5a9-9bcb30724f6f';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => 'nodequeue (reviews)',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b1172a3a-1bf3-43dd-a5a9-9bcb30724f6f';
    $display->content['new-b1172a3a-1bf3-43dd-a5a9-9bcb30724f6f'] = $pane;
    $display->panels['right'][0] = 'new-b1172a3a-1bf3-43dd-a5a9-9bcb30724f6f';
    $pane = new stdClass();
    $pane->pid = 'new-f96cd4a9-41c6-4346-bdce-568f1f077345';
    $pane->panel = 'top';
    $pane->type = 'views';
    $pane->subtype = 'ex3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '25',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 1,
      'override_title_text' => 'movie`s genres',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f96cd4a9-41c6-4346-bdce-568f1f077345';
    $display->content['new-f96cd4a9-41c6-4346-bdce-568f1f077345'] = $pane;
    $display->panels['top'][0] = 'new-f96cd4a9-41c6-4346-bdce-568f1f077345';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-219a7738-b2f1-4cff-9ecc-150e318334e7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test_panel'] = $page;

  return $pages;

}
