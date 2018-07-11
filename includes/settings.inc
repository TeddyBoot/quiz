<?php
/* The first part file contains the changable variables used in this tool

Database variables */
$sqlServer = "mysql:3306";
$dbUser = "quiz";
$dbUserPwd = "Mar1aD8";
$dbName = "quiz";
$tablePrefix = "quiz_";

/* Directory for the application to reside in on the webserver */
$appDir = "";

/* This part of the file should not be touched. It will retrieve the required variables from
the database and set them so they can be use in this tool
DO NOT CHANGE ANYTHING AFTER THIS LINE
Database tables */
$g_TableSettings = $tablePrefix . "settings";
$g_MenuItems = $tablePrefix . "menu";
$g_UserNames = $tablePrefix . "users";
$g_QuizTopics = $tablePrefix . "topics";
$g_QuizSubjects = $tablePrefix . "subjects";
$g_QuestTitles = $tablePrefix . "questTitles";

include $_SERVER['DOCUMENT_ROOT'] . $appDir  . '/includes/cnnctdb.inc';
$sql_qry = "SELECT * FROM $g_TableSettings";
$result = mysqli_query( $link, $sql_qry );
if ( $result ) {
	while ( $row = mysqli_fetch_array($result) ) {
		$_SESSION[$row['name']] = $row['value'];
	}
} else {
	echo mysqli_error( $link );
}
mysqli_close( $link );

/* Directory setup */
$_SESSION['templateDir'] = "includes/templates/" . $_SESSION['G_template'];
$_SESSION['stylesheet'] = "/" . $_SESSION['G_dir'] . $_SESSION['templateDir'] . "/default.css";
$_SESSION['validator'] = "/" . $_SESSION['G_dir'] . "includes/scripts/validator.js";
$_SESSION['form'] = "/" . $_SESSION['G_dir'] . "includes/scripts/form.js";
?>
