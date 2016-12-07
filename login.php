<?php
	session_start ();
	/*require_once*/
	require 'includes/settings.inc';
	if (isset($_POST['loginName'])) {
		include 'includes/cnnctdb.inc';
		$setName = $_POST['loginName'];
		/* echo "Validation of user " . $setName . "<br />";*/
		$setPwd = $_POST['passwd'];
		/* echo "passwd set: " . $setPwd . "<br />"; */
		$sql_qry = "SELECT * FROM $g_UserNames WHERE loginname='$setName'";
		/* echo $sql_qry . "<br />"; */
		$result = mysqli_query( $link, $sql_qry );
		if ( $result ) {
			$resUser = mysqli_fetch_array($result);
			$pwdInDb = $resUser['passwd'];
			mysqli_close( $link );
			if ( !isset ($resUser['loginname']) ) {
				$errMsg = "Unknown user";
			} elseif ( $setPwd == $pwdInDb ) {
				/* echo "Login Confirmed"; */
				$_SESSION['userName'] = $setName;
				$_SESSION['role'] = $resUser['role'];
				$_SESSION['fname'] = $resUser['firstname'];
				$_SESSION['lname'] = $resUser['adjective'] . " " . $resUser['lastname'];
				$_SESSION['login'] = $resUser['loginname'];
			} else {
				$errMsg = "Incorrect Password";
			}
			include 'index.php';
		} else {
			echo mysqli_error( $link );
		}
	} elseif (isset($_GET['page'])) {
		if ($_GET['page'] == "logout") {
			/* echo "Logging out " .$_SESSION['userName'] . "<br />"; */
			unset($_SESSION['userName']);
			unset($_SESSION['role']);
			unset($_SESSION['fname']);
			unset($_SESSION['lname']);
			/* echo "Successful!<br />"; */
		}
		include 'index.php';
	}
?>