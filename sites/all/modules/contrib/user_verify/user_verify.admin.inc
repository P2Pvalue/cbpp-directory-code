<?php

/**
 * @file
 * Verifies users once again after they have registered
 *
 * Implementation for Drupal 7.x
 */


/**
 * Administration form callback for the settings page.
 */
function _user_verify_settings() {
  global $user;

  $token_browser = module_exists('token') ?
    theme('token_tree', array('token_types' => array('user', 'user-verification'), 'click_insert' => TRUE, 'show_restricted' => TRUE))
    :
    t('(To display a token browser, please enable token module.)')
  ;

  $form = array(
    'user_verify_info' => array(
      '#type' => 'item',
      '#title' => t('Notice'),
      '#markup' => t(
        'The Email verification option in the <a href="@admin_link">user settings form</a> has been ' .
        'disabled to prevent your users from receiving ' .
        'both the standard registration mail and the verification code. ' .
        'Also, you probably want to go there and modify the contents of the user ' .
        'registration email templates in order to not confuse your new users.',
        array('@admin_link' => url('admin/config/people/accounts'))
      ),
    ),
    'user_verify_lock' => array(
      '#title' => t('Lock new accounts'),
      '#description' => t(
        'Normally, Drupal accounts are created with status \'active\'' .
        ' unless they need to be approved manually. ' .
        'Change this behaviour and keep new accounts inactive until they ' .
        'have been validated?'
      ),
      '#type' => 'radios',
      '#default_value' => variable_get_value('user_verify_lock'),
      '#required' => TRUE,
      '#options' => array(
        t('No'),
        t('Yes')
      ),
    ),
    'user_notification_settings' => array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('User notification settings'),
      'user_verify_blocked_message' => array(
        '#title' => t('Notification message for blocked users'),
        '#type' => 'textarea',
        '#description' => t(
          'Optional message that appears when the not verified user attempts to log in ' .
          '(if verbosity is active)'
        ),
        '#default_value' => variable_get_value('user_verify_blocked_message'),
      ),
      'user_verify_redirect' => array(
        '#type' => 'textfield',
        '#title' => t('Redirect new users'),
        '#required' => TRUE,
        '#description' => t('Path to redirect users to after they have been queued for verification. This must be a valid Drupal path. Use <em>&lt;front&gt;</em> for the front page.'),
        '#default_value' => variable_get_value('user_verify_redirect'),
      ),
    ),
    'user_verify_mail' => array(
      '#type' => 'fieldset',
      '#title' => t('Email settings'),
      '#collapsible' => TRUE,
      'user_verify_mail_enabled' => array(
        '#type' => 'checkbox',
        '#title' => t('Send verification mail'),
        '#default_value' => variable_get_value('user_verify_mail_enabled'),
        '#description' => t('Disable this option if you do not want the user verification module to send a verification mail, e.g. because you are using a third party mailer instead.'),
      ),
      'mail_disabled' => array(
        '#type' => 'container',
        '#states' => array(
          'invisible' => array(
            ':input[name="user_verify_mail_enabled"]' => array('checked' => FALSE),
          ),
        ),
        'tokens' => array(
          '#type' => 'fieldset',
          '#title' => t('Available tokens'),
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          'variables' => array(
            '#markup' => $token_browser,
          ),
        ),
        'user_verify_mail_subject' => array(
          '#title' => t('Mail subject'),
          '#type' => 'textfield',
          '#description' => t('The subject for the verification code email sent to the new user'),
          '#default_value' => variable_get_value('user_verify_mail_subject'),
          '#required' => TRUE,
        ),
        'user_verify_mail_body' => array(
          '#title' => t('Mail body'),
          '#type' => 'textarea',
          '#rows' => 15,
          '#description' => t('The content for the verification code email sent to the new user'),
          '#default_value' => variable_get_value('user_verify_mail_body'),
          '#required' => TRUE,
        ),
      ),
    ),
    'advanced_settings' => array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Advanced settings'),
      'user_verify_delay' => array(
        '#title' => t('Delay verification email'),
        '#type' => 'textfield',
        '#description' => t("Optional delay between user registration and sending out the validation code. Set to zero to send the code immediately after registration. Delayed mailout only works with Drupal's Cron properly configured and called frequently enough!"),
        '#field_suffix' => t('minutes'),
        '#default_value' => variable_get_value('user_verify_delay'),
        '#maxlength' => 4,
        '#size' => 5,
      ),
      'user_verify_timeout' => array(
        '#title' => t('Timeout'),
        '#type' => 'textfield',
        '#description' => t('Define how long the user may take to validate before his account will be deleted. Set to zero to avoid deletion of invalid accounts.'),
        '#field_suffix' => t('hours'),
        '#default_value' => variable_get_value('user_verify_timeout'),
        '#maxlength' => 3,
        '#size' => 4,
      ),
      'user_verify_max_errors' => array(
        '#title' => t('Attempts'),
        '#type' => 'textfield',
        '#description' => t('Limit the attempts a user has to validate his account. Set to zero for unlimited attempts (not recommended).'),
        '#default_value' => variable_get_value('user_verify_max_errors'),
        '#required' => TRUE,
        '#maxlength' => 2,
        '#size' => 3,
      ),
      'user_verify_verbosity' => array(
        '#title' => t('Verbosity'),
        '#description' => t('Inform the user about failed and remaining verification attempts?'),
        '#type' => 'radios',
        '#default_value' => variable_get_value('user_verify_verbosity'),
        '#required' => TRUE,
        '#options' => array(
          t('No'),
          t('Yes')
        ),
      ),
      'user_verify_delete' => array(
        '#title' => t('Delete on abuse'),
        '#description' => t('Delete the user account after exceeding the validation error limit instead of simply locking it?'),
        '#type' => 'radios',
        '#default_value' => variable_get_value('user_verify_delete'),
        '#required' => TRUE,
        '#options' => array(
          t('No'),
          t('Yes')
        ),
      ),
    ),
  );
  return system_settings_form($form);
}
