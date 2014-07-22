<?php

/**
 * @file
 * Abstract class for processes that run under the control of the Islandora Background
 * Process module.
 */

abstract class IslandoraBackgroundProcess {
  // An array of hooks in the Islandora hook in islandora_background_process.module
  // where the work() method below should be called. All classes that extend
  // IslandoraBackgroundProcess need to declare at least one of the following in their
  // $hooks array:
  // islandora_background_process_islandora_object_ingested,
  // islandora_background_process_islandora_object_modified,
  // islandora_background_process_islandora_object_alter,
  // islandora_background_process_islandora_datastream_ingested,
  // islandora_background_process_islandora_datastream_modified, or
  // islandora_background_process_islandora_datastream_alter.
  public $hooks;

  // Initialize and populate a list of objects that are instances of
  // this class, which we will iterate through in the hooks in 
  // islandora_background_process.module.
  static $instances = array();
  function __construct() {
    IslandoraBackgroundProcess::$instances[] = $this;
  }

  // All classes that extend IslandoraBackgroundProcess run their
  // code in the work() method. 
  abstract public function work($object = NULL, $datastream = NULL);
}

