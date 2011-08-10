<?php


$plugin = array(
  'title' => t('Grid Element'),
  'description' => 'An element within a sausage theme grid',
  'render pane' => 'sausage_grid_style_render_pane',
  'pane settings form' => 'sausage_grid_style_settings_form',
);


function theme_sausage_grid_style_render_pane($vars) {
  
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];
  
  $settings = $pane->style['settings'];
  
  $attributes = array();
  if ($settings['width']) {
    $attributes['class'][] = 'grid_' . check_plain($settings['width']);
  }
  if ($settings['alpha']) {
    $attributes['class'][] = 'alpha';
  }
  if ($settings['omega']) {
    $attributes['class'][] = 'omega';
  }
  if ($settings['prefix']) {
    $attributes['class'][] = 'prefix_' . check_plain($settings['prefix']);
  }
  if ($settings['suffix']) {
    $attributes['class'][] = 'suffix_' . check_plain($settings['suffix']);
  }
  if ($settings['push']) {
    $attributes['class'][] = 'push_' . check_plain($settings['push']);
  }
  if ($settings['pull']) {
    $attributes['class'][] = 'pull_' . check_plain($settings['pull']);
  }
  if ($settings['debug']) {
    $attributes['class'][] = 'p';
  }
  
  $output = '';
  $output .= '<div' . drupal_attributes($attributes) . '>';
  $output .= theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));
  $output .= '</div>';
  return $output;
}


/**
 * Settings form callback.
 */
function sausage_grid_style_settings_form($conf, $display, $pid, $type, &$form_state) {
  
  $pane = $display->content[$pid];
  $settings = $pane->style['settings'];
  
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => isset($form_state['conf']['width']) ? $form_state['conf']['width'] : '',
  );
  $form['prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix'),
    '#default_value' => isset($form_state['conf']['prefix']) ? $form_state['conf']['prefix'] : '',
  );
    $form['suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Suffix'),
    '#default_value' => isset($form_state['conf']['suffix']) ? $form_state['conf']['suffix'] : '',
  );
    $form['push'] = array(
    '#type' => 'textfield',
    '#title' => t('Push'),
    '#default_value' => isset($form_state['conf']['push']) ? $form_state['conf']['push'] : '',
  );
    $form['pull'] = array(
    '#type' => 'textfield',
    '#title' => t('Pull'),
    '#default_value' => isset($form_state['conf']['pull']) ? $form_state['conf']['pull'] : '',
  );
  $form['alpha'] = array(
    '#type' => 'checkbox',
  	'#title' => t('Alpha'),
    '#description' => t('Is this the first item within a nested grid?'),
    '#default_value' => isset($form_state['conf']['alpha']) ? $form_state['conf']['alpha'] : '',
  );
  $form['omega'] = array(
    '#type' => 'checkbox',
  	'#title' => t('Omega'),
    '#description' => t('Is this the first item within a nested grid?'),
    '#default_value' => isset($form_state['conf']['omega']) ? $form_state['conf']['omega'] : '',
  );
  $form['debug'] = array(
    '#type' => 'checkbox',
  	'#title' => t('Border for debugging'),
    '#description' => t('Under certain themes, includes a border around the pane'),
    '#default_value' => isset($form_state['conf']['debug']) ? $form_state['conf']['debug'] : '',
  );
  
  return $form;
}

