<?php
function my_module_menu() {
  $items['my_module/form'] = array(
    'title' => t('My form'),
    'page callback' => 'my_module_form',
    'access arguments' => array('access content'),
    'description' => t('My form'),
    'type' => MENU_CALLBACK,
  );
  return $items;
}
function my_module_form() {
  return drupal_get_form('my_module_my_form');
}
// Adds logic to our form builder to give it two pages. It checks a
// value in $form_state['storage'] to determine if it should display page 2.
function my_module_my_form($form, $form_state) {
  // Display page 2 if $form_state['storage']['page_two'] is set
  if (isset($form_state['storage']['page_two'])) {
    return my_module_my_form_page_two();
  }
  // Page 1 is displayed if $form_state['storage']['page_two'] is not set
  $form['name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['name']['first'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    //  '#default_value' => $form_state['values']['first'], // changed  // replaced
    '#default_value' => (isset($form_state['values']['first'])) ? $form_state['values']['first'] : 'First Name',  // replacement
    '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['name']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    //  '#default_value' => $form_state['values']['last'], // changed  // replaced
    '#default_value' => (isset($form_state['values']['last'])) ? $form_state['values']['last'] : 'Last Name',  // replacement
  );
  $form['year_of_birth'] = array(
    '#type' => 'textfield',
    '#title' => "Year of birth",
    '#description' => 'Format is "YYYY"',
    //  '#default_value' => $form_state['values']['year_of_birth'], // changed  // replaced
    '#default_value' => (isset($form_state['values']['year_of_birth'])) ? $form_state['values']['year_of_birth'] : 'Year of Birth',  // replacement
  );
  // Add new elements to the form
  if (!empty($form_state['storage']['another_name'])) {
    $form['name2'] = array(
      '#type' => 'fieldset',
      '#title' => t('Name #2'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['name2']['first2'] = array(
      '#type' => 'textfield',
      '#title' => t('First name'),
      '#description' => "Please enter your first name.",
      '#size' => 20,
      '#maxlength' => 20,
      //  '#default_value' => $form_state['values']['first2'], // changed  // replaced
      '#default_value' => (isset($form_state['values']['first2'])) ? $form_state['values']['first2'] : 'First Name',  // replacement
    );
    $form['name2']['last2'] = array(
      '#type' => 'textfield',
      '#title' => t('Last name'),
      //  '#default_value' => $form_state['values']['last'], // changed  // replaced
      '#default_value' => (isset($form_state['values']['last2'])) ? $form_state['values']['last2'] : 'Last Name',  // replacement
    );
    $form['year_of_birth2'] = array(
      '#type' => 'textfield',
      '#title' => "Year of birth",
      '#description' => 'Format is "YYYY"',
      //  '#default_value' => $form_state['values']['year_of_birth2'], // changed  // replaced
      '#default_value' => (isset($form_state['values']['year_of_birth2'])) ? $form_state['values']['year_of_birth2'] : 'Year of Birth',  // replacement
    );
  }
  $form['clear'] = array(
    '#type' => 'submit',
    '#value' => 'Reset form',
    '#validate' => array('my_module_my_form_clear'),
  );
  if (empty($form_state['storage']['another_name'])) {
    $form['another_name'] = array(
      '#type' => 'submit',
      '#value' => 'Add another name',
      '#validate' => array('my_module_my_form_another_name'),
    );
  }
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => 'Next >>',
  );
  return $form;
}
// New function created to help make the code more manageable
function my_module_my_form_page_two() {
  $form['color'] = array(
    '#type' => 'textfield',
    '#title' => 'Favorite color',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}
function my_module_my_form_another_name($form, &$form_state) {
  $form_state['storage']['another_name'] = TRUE;
  $form_state['rebuild'] = TRUE; // Will cause the default submit function
  // to be skipped.
}
function my_module_my_form_clear($form, $form_state) {  // changed because
  // second parameter
  // causes fault
  // when by value, even
  // though it seems more
  // correct
  unset ($form_state['values']);  // ensures fields are blank after reset
  // button is clicked
  unset ($form_state['storage']); // ensures the reset button removes the
  // another_name part
  $form_state['rebuild'] = TRUE;
}
// Modifies function so it can validate page 2
function my_module_my_form_validate($form, &$form_state) {
  // Validate page 2 here
  if (isset($form_state['storage']['page_two'])) {
    $color = $form_state['values']['color'];
    if (!$color) {
      form_set_error('color', 'Please enter a color.');
    }
    return;
  }
  $year_of_birth = $form_state['values']['year_of_birth'];
  $first_name = $form_state['values']['first'];
  $last_name = $form_state['values']['last'];
  if (!$first_name) {
    form_set_error('first', 'Please enter your first name.');
  }
  if (!$last_name) {
    form_set_error('last', 'Please enter your last name.');
  }
  if ($year_of_birth && ($year_of_birth < 1900 || $year_of_birth > 2000)) {
    form_set_error('year_of_birth', 'Enter a year between 1900 and 2000.');
  }
  if (isset($form_state['storage']['another_name'])) { // This value is set after
    // "Add another name" button
    // is clicked.    // added
    if ($form_state['storage']['another_name']) {
      $year_of_birth = $form_state['values']['year_of_birth2'];
      $first_name = $form_state['values']['first2'];
      $last_name = $form_state['values']['last2'];
      if (!$first_name) {
        form_set_error('first2', 'Please enter your first name.');
      }
      if (!$last_name) {
        form_set_error('last2', 'Please enter your last name.');
      }
      if ($year_of_birth && ($year_of_birth < 1900 || $year_of_birth > 2000)) {
        form_set_error('year_of_birth2', 'Enter a year between 1900 and 2000.');
      }
    }
  }
}
// Modifies this function so that it will respond appropriately based on
// which page was submitted. If the first page is being submitted,
// values in the 'storage' array are saved and the form gets
// automatically reloaded.
// If page 2 was submitted, we display a message and redirect the
// user to another page.
function my_module_my_form_submit($form, &$form_state) {
  // Handle page 1 submissions
  if ($form_state['clicked_button']['#id'] == 'edit-next') {
    $form_state['storage']['page_two'] = TRUE; // We set this to determine
    // which elements to display
    // when the page reloads.
    // Values below in the $form_state['storage'] array are saved
    // to carry forward to subsequent pages in the form.
    $form_state['storage']['page_one_values'] = $form_state['values'];
    $form_state["rebuild"] = TRUE;   // Added
  }
  // Handle page 2 submissions
  else {
    /*
     Normally, some code would go here to alter the database with the data
     collected from the form. Sets a message with drupal_set_message()
     to validate working code.
     */
    drupal_set_message('Your form has been submitted');
    unset ($form_state['storage']); // This value must be unset for
    // redirection! This is because
    // $form_state['rebuild'] gets set to TRUE
    // when 'storage' is set. See code sample
    // #9 for more on this.
    $form_state['redirect'] = 'node'; // Redirects the user.
  }
}
?>