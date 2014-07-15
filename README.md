## Introduction

Proof of concept module illustrating the use of the [Background Process](https://www.drupal.org/project/background_process) contrib module to execute long-running tasks such as derivative creation.

See https://github.com/Islandora/Islandora-Preservation-Interest-Group/tree/master/background_services_discussion_paper for background.

## Dependencies

Islandora and the Background Process module.

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

None. This module only provides a framework and does not have a user interface or optional configuration settings. 

## Customizing / extending this module

This module provides an abstract class, IslandoraBackgroundProcess, that can be extended by modules that manage an external service. All child objects must implement a public $hook property (see the top of includes/IslandoraBackgroundProcess.inc for a list of allowed values) and a public work() method that integrates with the external service. See the [Islandora Background Process OCR Service integration module](https://github.com/mjordan/islandora_bprocess_ocr) for an example. The $hook property and the work() method are called within the Islandora hooks implemented by this module. Modules that extend IslandoraBackgroundProcess should autoload the extending classes using the normal Drupal method of registering the class file(s) in the module .info file.

The .module file will need to instantiate the object that manages the background process and provide an admin settings form if any configuration settingsare required by the integration code. See the Islandora Background Process OCR Service integration .module file for an example.


