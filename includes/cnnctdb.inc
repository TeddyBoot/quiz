<?php
	$link = mysqli_connect ('$sqlServer', '$dbUser', '$dbUserPwd', '$dbName');
	if ( ! $link ) {
		die("Connetion failed: " . mysqli_error ());
	}
?>