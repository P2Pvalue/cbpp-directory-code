<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 * 
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function adaptivetheme_subtheme_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.
  
  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function adaptivetheme_subtheme_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_page(&$vars) {
}
function adaptivetheme_subtheme_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_node(&$vars) {
}
function adaptivetheme_subtheme_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_comment(&$vars) {
}
function adaptivetheme_subtheme_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_block(&$vars) {
}
function adaptivetheme_subtheme_process_block(&$vars) {
}
// */


//function CSS2948_preprocess_user_picture(&$variables) {
//  
//
// $variables['user_picture'] = theme('image_style', array('style_name' => 'user_picture', 'path' => $filepath, 'alt' => $alt, 'title' => $alt));
//
//}

function CSS2948Directory_preprocess_node(&$vars) {

    if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {

        $vars['datetime'] = format_date($vars['created'], 'custom', 'j F, Y'); // PHP 'c' format is not proper ISO8601!
        // Publication date, formatted with time element
        $vars['publication_date'] = '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate"><span class=customTimer>' . $vars['datetime'] . '</span></time>';

        $vars['submitted'] = t('Posted !datetime By  !username', array(
            '!username' => $vars['name'],
            '!datetime' => $vars['publication_date'],
                )
        );
    } else {
        $vars['submitted'] = '';
    }
}



function CSS2948Directory_preprocess_comment(&$vars) {
$vars['datetime'] = format_date($vars['comment']->created, 'custom', 'F j , Y'); // PHP 'c' format is not proper ISO8601!
      
    $vars['submitted'] = t(' !username !datetime', 
    array(
   
    '!username' => $vars['author'], 
    '!datetime' => '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . $vars['datetime'] . '</time>',
  )
  );
    
    
}


function CSS2948Directory_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    // HTML5 placeholder attribute
    $form['search_block_form']['#attributes']['placeholder'] = t('Search...');
  }
}


function CSS2948Directory_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Use CSS to hide titile .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // comment below line to hide current page to breadcrumb
	$breadcrumb[] = drupal_get_title();
    $output .= '<nav class="breadcrumb">' . implode(' » ', $breadcrumb) . '</nav>';
    return $output;
  }
}