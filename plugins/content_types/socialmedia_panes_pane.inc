<?php

/**
 * @file
 * Custom panel pane for social feed.
 */

$plugin = array(
  // Just do this one, it is needed.
  'single' => TRUE,
  // Title to show up on the pane screen.
  'title' => t('Social Media Panes'),
  // Description to show up on the pane screen.
  'description' => t('Fetches feeds from facebook/twitter app and displays it.'),
  // A category to put this under.
  'category' => t('Social Media'),
  // A function that will return the settings form for the pane.
  'edit form' => 'socialmedia_panes_pane_edit_form',
  // A function that will return the renderable content.
  'render callback' => 'socialmedia_panes_pane_render',
  // A function that will return the information displayed on
  // the admin screen (optional).
  'admin info' => 'socialmedia_panes_pane_admin_info',
  // Array of defaults for the settings form.
  'defaults' => array(
    'text' => '',
  ),
  // This is NEEDED to be able to use substitution strings in your pane.
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function socialmedia_panes_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Panel Text'),
    '#description' => t('Text to display, it may use substitution strings'),
    '#default_value' => $conf['text'],
  );

  return $form;
}

/**
 * Submit function, anything in the formstate[conf] automatically gets saved.
 */
function socialmedia_panes_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function socialmedia_panes_pane_render($subtype, $conf, $args, $contexts) {
  $data['facebook']['class'] = '';
  $data['facebook']['icon'] = 'f';
  $data['facebook']['data'] = array();

  $data['twitter']['class'] = '';
  $data['twitter']['icon'] = 't';
  $data['twitter']['data'] = array();

  ob_start();
  try {
    $data['facebook']['data'] = socialmedia_panes_facebook_feeds(variable_get('socialfeed_facebook_page_name'));
  }
  catch (Exception $e) {
    ob_end_clean();
    unset($data['facebook']);
    drupal_set_message("Can't fetch facebook feeds", 'error');
  }

  ob_start();
  try {
    $data['twitter']['data'] = socialmedia_panes_twitter_posts();
  }
  catch (Exception $e) {
    ob_end_clean();
    unset($data['twitter']);
    drupal_set_message("Can't fetch twitter feeds", 'error');
  }


  $content = theme('socialmedia_panes', array('social_feeds' => $data));

  $block = new stdClass();

  $block->title = t('Juke Newsroom Social Feed');
  $block->content = $content;

  return $block;
}

/**
 * The 'admin info' callback for panel pane.
 */
function socialmedia_panes_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $conf['text'];
    return $block;
  }
}
