<article>
<?php
if ( $page == "users" ) {
	echo "<aside>";
	echo "<ul>";
	echo "<li><a href=\"index.php?page=users&action=list\">List users</a></li>";
	echo "<li><a href=\"index.php?page=users&action=add\">Add user</a></li>";
	echo "<li><a href=\"index.php?page=users&action=rem\">Remove user</a></li>";
	echo "</ul>";
	echo "</aside>";
}

if ( $page == "contact" ) {
	echo "<aside>";
	echo "<ul>";
	echo "<li><a href=\"index.php?page=contact&action=address\">List users</a></li>";
	echo "<li><a href=\"index.php?page=contact&action=email\">Add user</a></li>";
	echo "</ul>";
	echo "</aside>";
}

?>
<section>
<?php
switch ($page) {
	case "home":
		echo "Home page<br />";
		if ( isset ( $errMsg ) ) {
			echo $errMsg . "<br />";
		} else {
			echo "Welcome<br />";
			echo "This page will provide tests or quizes to use either directly on this webpage or to print out and use as a test in the classroom. Regular users will only be able to fill out the tests. Super users will be able to create a test/quiz and add questions to the database. The admin users are also able to add users to login with one of these roles.<br />";
			echo "This page is still under construction so not everything works as it should.<br />";
		}
		break;
	case "login":
		echo "Login page<br />";
?>
	<form action="login.php" method="post">
		<input type="text" name="loginName"><br />
		<input type="password" name="passwd"><br />
		<input type="submit" value="Login">
	</form>
<?php
		break;
	case "contact":
		echo "Contact page<br />";
		break;
	case "users":
		echo "User Management page<br />";
		switch ($_GET['action']) {
			case "list":
				include 'includes/cnnctdb.inc';
				$sqlQuery = "SELECT * FROM $userNames";
				$result = mysqli_query( $link, $sqlQuery );
				mysqli_close ($link);
				while ($row_users = mysqli_fetch_array($result)) {
					echo "<li>" . $row_users['firstname'] . " " . $row_users['adjective'] . " " . $row_users['lastname'] . " : " . $row_users['loginname'] . " : " . $row_users['role'] . "</li>";
				}
				break;
			case "add":
?>
	<form action="adduser.php" method="post">
		Firstname: <input type="text" name="firstName" required><br />
		Adjective: <input type="text" name="adjective"><br />
		Lastname: <input type="text" name="lastName" required><br />
		Loginname: <input type="text" name="logName" required><br />
		Password: <input type="password" name="pwd1" required><br />
		Repeat password: <input type="password" name="pwd2" required><br />
		<select name="role">
			<option value="1">Admin</option>
			<option value="2">Super user</option>
			<option value="3">User</option>
		</select><br />
		<input type="submit" value="Login">
	</form>
<?php
				break;
			default:
				echo "Defalut user page!!";
			}
		break;
	default:
		echo "Defalut page<br />";
}
?>
</section>
</article>