<?php
session_start ();
/*require_once*/
require '../settings.inc';
if (isset($_POST['userName'])) {
	if (isset ($_POST['removeUser'] ) ) {
		if ($_POST['userName'] == '1'){
			$errMsg = "The admin user cannot be removed!";
		} else {
			$delUsr = $_POST['userName'];
			include $_SERVER['DOCUMENT_ROOT'] . $appDir . "/includes/cnnctdb.inc";
			$sql_qry = "DELETE FROM $userNames WHERE id='$delUsr'";
			echo $sql_qry;
			if (!mysqli_query( $link, $sql_qry )) {
				$errMsg = "The query was not executed correctly. Please check the logs for more info.";
			}
			mysqli_close ($link);
		}
	}
	$message = "Deleting the user. Done!";
} else {
	$errMsg = "You are not here by the correct way, either you are trying to hack this system or your are a bot";
}
include '../../index.php';
?>