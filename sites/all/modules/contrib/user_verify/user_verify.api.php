<?php

/**
 * @file
 * Hooks provided by the user verification module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * A user account has been successfully verified and unlocked.
 *
 * @param $account
 *   The affected user account object.
 */
function hook_user_verify_verified($account) {
  // Do something with $account's data, e.g. add its uid to a
  // "verified users" list.
  mymodule_add_user_id($account->uid);
}

/**
 * @} End of "addtogroup hooks".
 */
