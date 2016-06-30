<article>
<?php
switch ($page) {
	case "home":
		echo "Home page";
		break;
	case "login":
		echo "Login page\n";
		if (isset($_SESSION['userName'])) {
			echo "You are already logged in " . $_SESSION['userName'] . "!";
		} else {
			if (isset($_POST['loginName'])) {
				include 'includes/cnnctdb.inc';
				$setName = $_POST['loginName'];
				echo "Validation of user " . $setName . "<br />";
				$setPwd = $_POST['passwd'];
				echo "passwd set: " . $setPwd . "<br />";
				$sql_qry = "SELECT * FROM $userNames WHERE loginname='$setName'";
				echo $sql_qry . "<br />";
				$result = mysqli_query( $link, $sql_qry );
				if ( $result ) {
					$resUser = mysqli_fetch_array($result);
					$pwdInDb = $resUser['passwd'];
					if ( $setPwd == $pwdInDb ) {
						echo "Login Confirmed";
						$_SESSION['userName'] = $setName;
						$_SESSION['role'] = $resUser['role'];
						$_SESSION['fname'] = $resUser['firstname'];
						$_SESSION['lname'] = $resUser['adjective'] . " " . $resUser['lastname'];
					} else {
						echo "Incorrect Password";
					}
					mysqli_close( $link );
				} else {
					echo "Unknown user";
				}
			} else {
?>
	<form action="index.php" method="post">
		<input type="text" name="loginName"><br />
		<input type="password" name="passwd"><br />
		<input type="submit" value="Login">
	</form>
<?php
			}
		}
		break;
	case "contact":
		echo "Contact page";
		break;
	case "logout":
		echo "Logging out";
		unset($_SESSION['userName']);
		unset($_SESSION['role']);
		unset($_SESSION['fname']);
		unset($_SESSION['lname']);
	default:
		echo"Defalut page";
}
?>
</article>