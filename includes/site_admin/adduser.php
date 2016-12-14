<?php
	session_start ();
	/*require_once*/
	require '../settings.inc';
	if (isset ($_POST['adduser'] ) ) {
		$firstName = $_POST['firstName'];
		$adj = $_POST['adjective'];
		$lastName = $_POST['lastName'];
		/* get loginname and check if one already exists */
		$loginName = $_POST['logName'];
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . "/includes/cnnctdb.inc";
		$sql_qry = "SELECT * FROM $userNames WHERE loginname='$loginName'";
		$result = mysqli_query( $link, $sql_qry );
		$resLogin = mysqli_fetch_array($result);
		mysqli_close ($link);
		if ($resLogin['loginname']) {
			$errMsg = "The username already exists. Please try agian.";
		}
		/* Check if passwords are the same (again) just to be sure */
		if ($_POST['pass1'] != $_POST['pass2']) {
			$errMsg = "The passwords are not the same please try again!";
		} else {
			$pwd = $_POST['pass1'];
		}
		$role = $_POST['role'];
		if (!isset ($errMsg)) {
			include $_SERVER['DOCUMENT_ROOT'] . $appDir . "/includes/cnnctdb.inc";
			$sql_qry = "INSERT INTO $userNames (firstname, adjective, lastname, loginname, passwd, role) VALUES ('$firstName', '$adj', '$lastName', '$loginName', '$pwd', '$role')";
			/* include $_SERVER['DOCUMENT_ROOT'] . $appDir . "/index.php"; */
			if (!mysqli_query( $link, $sql_qry )) {
				$errMsg = "The query was not executed correctly. Please check the logs for more info.";
			}
			mysqli_close ($link);
			$message = "adding the user. Done!";
		} else {
			echo $errMsg;
		}
	} else {
		$errMsg = "You are trying someting that should not be done. Hacking is wrong!";
	}
	include '../../index.php';
?>