------------------------------------------------------------------------------
  User verification module Readme
  http://drupal.org/project/user_verify
  by David Herminghaus (doitDave) www.david-herminghaus.de
------------------------------------------------------------------------------

Contents:
=========
1. ABOUT
2. TECHNICAL
3. REQUIREMENTS
4. INTEGRATION/CUSTOMIZING
5. QUICK REFERENCE
6. MULTILINGUAL SUPPORT
7. KNOWN ISSUES

1. ABOUT
========

Drupal (at least: Drupal 6) makes it relatively easy for spammers to join your
site and annoy your serious users - as long as you do not set the registration
policy to "approve by admin" which either means much work for you or
frustrating waiting times for new users. This is because Drupal sends out
registration/verification mails directly after registration (with the same
server process, that is) which is mainly a consequence of the fact that not
every site owner may have custom cron jobs.

2. TECHNICAL
============

Instead of directly sending out a mail with an initial password it leaves
password choice to the user but generates an additional verification code.
This code may be sent out instantly as well or (recommended) with a
configurable delay. Also, the new user's status will be set to "inactive"
and remain in that state unless the user verifies properly.
Too many verification attempts (you may set a custom limit) will silently
and permanently lock out the applicant until an admin manually releases him.

3. REQUIREMENTS
===============

All 7.x versions after 1.0 will require the variable module to work.
This is due to an internal design change with i18n integration in mind.
So please, before installing or updating to a more recent version, make
sure to have the variable module from http://drupal.org/project/variable
and proberly enable it in order to sustain full functionality.

4. INSTALLATION
===============

* Make sure you have PHP 5 on your server.
* Install and enable the variable module, if not already done.
* Unless already done, configure a standard Drupal cronjob. It should run
  at least once per 24 hours or, if you want delayed verification mails,
  often enough to deliver them within the appropriate time.
  (E.g. for a mail delay of 10 minutes, your cronjob should run every 10
  minutes.)
* Activate the module.
* For multilingual support, please install the variable translation module
  which is part of the i18n module, available at http://drupal.org/project/i18n
  

5. QUICK REFERENCE
==================

* Set up your extended verification parameters and individual verification
  mail template at admin/user/user_verify (note the available variables).
* Recommendedly alter your "Welcome, no approval required" mail template
  at admin/user/settings to inform your new users about their having to
  wait for the verification mail.

6. MULTILINGUAL SUPPORT
=======================

Both the verification mail and the customizable post-registration message
do now support multilingual variables. To translate them, follow these steps:

1) Make sure you have installed and activated
   * i18n module
   * i18n variable translation module.
2) Go to admin/config/regional/i18n/variable
3) Go to the "User verification" section.
4) Select the variables you want to be translatable and save your configuration.
5) Go to admin/config/people/accounts/verification and note the 
   "multilingual variables" switch (normally at the top of the form).
6) Use the language links to have an individual form for each
   supported language and save your translations.
7) Mails and messages will now appear in each user's individually selected
   language.

7. KNOWN ISSUES
===============

1) Accuracy of delayed mailout
------------------------------

Mind the correlation between cron tasks and your individual delays:

* Always consider your configured delays and time frames a minimum value,
* always consider your cron intervals the maximum value.

E.g.: If you set a verification mail delay of 10 minutes but your cronjob is
set up to run every 15 minutes, the effective delay will be somewhere between
10 and 15 minutes.

Thus, if you want delivery and actions à la minute, your cronjob would have to
run every minute, which is not recommended unless you have your own dedicated
and, more important, very performant server.


2) Environment variables in drush (and maybe other environments)
----------------------------------------------------------------

If you run cron from drush, and you do not set the "uri" option in drush, then
the value of $_SERVER['HTTP_HOST'] (used to create the !link variable) may be
something different from the site name. It looks to me as if Drush uses the name
of the site's folder in the public_html/sites directory, e.g. if it is
"default", a !link beginning with "http://default" will come out (which is
likely to be unwanted).

To check the current environment variables, you can run "drush status" from
the command line.

A workaround is to create a drushrc.php file (if it does not already exist) in
the drush directory with the following content:

  <?php
  $options['uri'] = 'http://your.domain.name';

(After https://drupal.org/node/2096455 with thanks to rclemmings.)
