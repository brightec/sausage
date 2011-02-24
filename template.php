<?php


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

