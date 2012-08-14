<?php

function islandora_solr_facet_pages_admin_settings(&$form_state) {
  
  // include admin css file
  $admin_css = drupal_get_path('module', 'islandora_solr_facet_pages') . '/css/islandora_solr_facet_pages.admin.css';
  drupal_add_css($admin_css);
  
  $form = array();
  
  $form['facet_pages'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  // fields
  $form['facet_pages']['islandora_solr_facet_pages_fields_data'] = array(
    '#type' => 'item',
    '#title' => t('Facet pages'),
    '#description' => t('Configure facet pages. Save settings for additional empty fields.'),
    '#tree' => TRUE,
    '#theme' => 'islandora_solr_facet_pages_admin_table'
  );
  
  // get fields from variable
  $fields_data = variable_get('islandora_solr_facet_pages_fields_data', array());

  // add 3 empty fields
  for ($i = 1; $i <= 3; $i++) {
    $fields_data[] = array('');
  }

  $fields = array();
  foreach ($fields_data as $key => $value) {
    $field = array(
      'solr_field' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['solr_field']) ? $value['solr_field'] : '',
      ),
      'label' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['label']) ? $value['label'] : '',
      ),
      'path' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['path']) ? $value['path'] : '',
      ),
    );
    $fields[] = $field;
  }
  // add fields  
  $form['facet_pages']['islandora_solr_facet_pages_fields_data']['fields'] = $fields;
  
  // limit results per page
  $form['facet_pages']['islandora_solr_facet_pages_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Results per page'),
    '#size' => 5,
    '#default_value' => variable_get('islandora_solr_facet_pages_limit', 25),
    '#description' => t('The amount of values returned per page. Leave empty to return all fields'),
  );

  // submit
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 50,
  );
  // reset
  $form['buttons']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#weight' => 51,
  );

  return $form;
}


function theme_islandora_solr_facet_pages_admin_table($form) {
  // set variable
  $rows = array();
  
  // render islandora_solr_primary_display_table
  foreach ($form['fields'] as $key => $elements) {

    $row = array();
    // check if $key is really the array we need. we shouldn't select the #parent array for example.
    if (is_array($elements) && element_child($key)) {

      $row[] = array('data' => drupal_render($form['fields'][$key]['solr_field']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['label']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['path']));
      $rows[] = $row;
    }
  }

  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Solr field'));
  $header[] = array('data' => t('Label'));
  $header[] = array('data' => t('Path'));
  
  // render table
  $output = theme('table', $header, $rows, array('id' => 'islandora-solr-facet-pages-admin-table'));
  
  return $output;
  
}


function islandora_solr_facet_pages_admin_settings_validate($form, &$form_state) {
  // on save
  if ($form_state['clicked_button']['#value'] == t('Save')) {
    // get limit value
    $limit = $form_state['values']['islandora_solr_facet_pages_limit'];
    $limit = trim($limit);
    // check numeric
    if (!is_numeric($limit)) {
      form_set_error('islandora_solr_facet_pages_limit', t('Exposed results must be numeric.'));
    }
    // check for no decimals
    if (strpos($limit, '.') OR strpos($limit, ',')) {
      form_set_error('islandora_solr_facet_pages_limit', t('Exposed results cannot be decimals.'));
    }
  }
}

function islandora_solr_facet_pages_admin_settings_submit($form, &$form_state) {
  
  // get operation
  $op = $form_state['clicked_button']['#value'];
  
  switch ($op) {
    case t('Save'):
      // set variables
      
      // clean up array
      $fields_data = $form_state['values']['islandora_solr_facet_pages_fields_data']['fields'];
      foreach ($fields_data as $key => $value) {
        if (empty($value['solr_field']) AND empty($value['label']) AND empty($value['path'])) {
          unset($fields_data[$key]);
        }
      }
      variable_set('islandora_solr_facet_pages_fields_data', $fields_data);
      variable_set('islandora_solr_facet_pages_limit', trim($form_state['values']['islandora_solr_facet_pages_limit']));
      
      drupal_set_message(t('The configuration options have been saved.'));
      break;
    case t('Reset to defaults'):
      // empty variables

      drupal_set_message(t('The configuration options have been reset to their default values.'));
      break;
  }
}