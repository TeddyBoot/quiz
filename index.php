<?php
	session_start ();
	/*require_once*/
	require 'inlcudes/settings.inc';
?>
<!DOCTYPE HTML>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Create a test/quiz</title>
	</head>
	<body>
<?php 
	if ( isset ( $_SESSION['userName'] ) ) {
		if ( !isset ($_SESSION['userRole'] ) ) {
			include 'includes/cnnctdb.inc';
			$loginName = $_SESSION['userName'];
			$sql_qry = "SELECT role FROM $userNames WHERE loginname='$loginName'";
			$result = mysqli_query( $link, $sql_qry );
			if ( $result ) {
				$_SESSION['userRole'] = mysql_fetch_object($result);
			} else {
				echo mysqli_error( $link );
			}
			mysql_close( $link );
		}
	}
?>
		<header>
<?php include '$templateDir/header.inc'; ?>
		</header>
		<nav>
<?php include '$templateDir/navbar.inc'; ?>
		</nav>
		<article>
<?php include '$templateDir/main.inc'; ?>
		</article>
		<footer>
<?php include '$templateDir/footer.inc'; ?>
		</footer>
	</body>
</html>