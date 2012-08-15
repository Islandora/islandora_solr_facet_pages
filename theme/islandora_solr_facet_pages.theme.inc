<?php

/**
 * @file
 * Theme functions
 *
 * Contains all theme related functionality. Theme and preprocess
 * functions.
 */

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

  $total = $variables['pager_data']['total'];
  $from = $variables['pager_data']['offset'] + 1;
  $to = $variables['pager_data']['offset'] + $variables['pager_data']['limit'];
  if ($to > $total) {
    $to = $total;
  }

  $variables['results_count'] = t('Showing @from - @to of @total', array('@from' => $from, '@to' => $to, '@total' => $total));

  // add template suggestion based on path name
  $variables['template_files'][] =  'islandora-solr-facet-pages-wrapper--' . $variables['path'];
}

/**
 * Theme function to render the alphabetical pager
 *
 * @param array $facet_queries
 *   Facet queries returned from Solr. eg: solr_field:A* => 1234
 *   This array is used to check the bucket size. An empty bucket won't be
 *   rendered into a link.
 * @param array $fq_map
 *   Array which maps query filter so prefixes. eg: solr_field:A* => A
 *   Used to render the link values.
 * @param string $prefix
 *   Currently active prefix for this page. Used to set active classes.
 * @param string $path
 *   Currently active path which is set in the admin interface to decide what
 *   solr field to facet on. Used to create URL's eg: url('browse/' . $path)
 * @return string
 *   Return rendered alphabetical pager
 *
 *  @see islandora_solr_facet_pages_theme(), 
 *  @see _islandora_solr_facet_pages_letterer().
 */
function theme_islandora_solr_facet_pages_letterer($facet_queries, $fq_map, $prefix, $path) {

  // ul
  $output = '<ul class="islandora-solr-facet-pages-letterer">';
  // li: ALL
  $output .= '<li class="letter' . ((t('ALL') == $prefix) ? ' active' : '') . '">';
  $output .= '<a href="' . url('browse/' . $path) . '" title="' . t('Browse all') . '">' . t('ALL') . '</a>';
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
      $output .= '<a href="' . url($url) . '" title="' . t('Browse starting with @letter', array('@letter' => $value)) . '">' . $value . '</a>';
    }
    else {
      $output .= $value;
    }
    $output .= '</li>';
  }
  $output .= '</ul>';

  return $output;
}
