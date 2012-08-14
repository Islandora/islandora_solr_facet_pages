<?php

/**
 * Implements hook_preprocess().
 */
function islandora_solr_facet_pages_preprocess_islandora_solr_facet_pages_results(&$variables) {
  
  // add template suggestion based on path name
  $variables['template_files'][] =  'islandora-solr-facet-pages-results--' . $variables['path'];
}

/**
 * Implements hook_preprocess().
 */
function islandora_solr_facet_pages_preprocess_islandora_solr_facet_pages_wrapper(&$variables) {
  
  // add template suggestion based on path name
  $variables['template_files'][] =  'islandora-solr-facet-pages-wrapper--' . $variables['path'];
}

/**
 * Implements hook_preprocess().
 */
function theme_islandora_solr_facet_pages_letterer($facet_queries, $fq_map, $prefix, $path) {
  
  // ul
  $output = '<ul class="islandora-solr-facet-pages-letterer">';
  // li: ALL
  $output .= '<li class="letter' . ((t('ALL') == $prefix) ? ' active' : '') . '">';
  $output .= '<a href="' . url('browse/' . $path) . '">' . t('ALL') . '</a>';
  $output .= '</li>';
  
  // loop over facet queries to render letters
  foreach ($facet_queries as $query => $count) {
    // value
    $value = $fq_map[$query];
    // li: value   
    $output .= '<li class="letter' . (($value == $prefix) ? ' active' : '') . '">';
    // create link if facet bucket is not empty
    if ($count > 0) {
      $url = 'browse/' . $path . '/' . $value;
      $output .= '<a href="' . url($url) . '">' . $value . '</a>';
    }
    else {
      $output .= $value;
    }
    $output .= '</li>';
  }
  $output .= '</ul>';
  
  return $output;
}
