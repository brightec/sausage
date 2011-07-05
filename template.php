<?php


function sausage_preprocess_html(&$variables) {
  // add a panels or not-panels class to the body
  if (module_exists('panels') && function_exists('panels_get_current_page_display')) {
    $variables['classes_array'][] = panels_get_current_page_display() ? 'panels' : 'not-panels';
  }
}


function sausage_preprocess_page(&$variables) {

  // if there is a page_title panel present, then don't show
  // the title in content-top
  if (function_exists('panels_get_current_page_display')) {
    $pd = panels_get_current_page_display();
    if ($pd) {
      foreach ($pd->content as $pane) {
        if ($pane->type == 'page_title' && $pane->shown) {
          $variables['title'] = '';
        }
      }
    }
  }
  
}

