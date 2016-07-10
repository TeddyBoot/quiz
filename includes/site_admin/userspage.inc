<?php
echo "User Management page<br />";
switch ($_GET['action']) {
	case "list":
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/cnnctdb.inc';
		$sqlQuery = "SELECT * FROM $userNames";
		$result = mysqli_query( $link, $sqlQuery );
		mysqli_close ($link);
		while ($row_users = mysqli_fetch_array($result)) {
			echo "<li>" . $row_users['firstname'] . " " . $row_users['adjective'] . " " . $row_users['lastname'] . " : " . $row_users['loginname'] . " : " . $row_users['role'] . "</li>";
		}
		break;
	case "add":
		?>
	<form action="includes/site_admin/adduser.php" method="post">
		<table cellpadding=1 cellspacing=1 border=0>
		<tr><td>Firstname</td><td><input type="text" name="firstName" required></td></tr>
		<tr><td>Adjective</td><td><input type="text" name="adjective"></td></tr>
		<tr><td>Lastname</td><td><input type="text" name="lastName" required></td></tr>
		<tr><td>Loginname</td><td><input type="text" name="logName" required></td></tr>
		<tr><td>Password</td><td><input type="password" name="pass1" id="pass1" required placeholder="Enter password" onkeyup="checkPass(); return false;"></td></tr>
		<tr><td>Repeat password</td><td><input type="password" name="pass2" id="pass2" required placeholder="Confirm password" onkeyup="checkPass(); return false;"><span id="confirmMessage" class="confirmMessage"></span></td></tr>
		<tr><td>Role</td><td><select name="role">
			<option value="1">Admin</option>
			<option value="2">Super user</option>
			<option value="3">User</option>
		</select></td></tr>
		<tr><td colspan=2 align=right><input name="adduser" type="submit" value="Add user"></td></tr>
		</table>
	</form>
<?php
		break;
	case "rem":
		echo "Removing user";
?>
	<form action="includes/site_admin/remuser.php" method="post" onSubmit="return confirm('Are you sure you wish to delete? It can NOT be undone');">
		<select name="userName">
<?php
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/cnnctdb.inc';
		$sqlQuery = "SELECT * FROM $userNames ORDER BY lastname";
		$result = mysqli_query( $link, $sqlQuery );
		mysqli_close ($link);
		while ($row_users = mysqli_fetch_array($result)) {
			echo "<option value=\"" . $row_users['id'] . "\">" . $row_users['firstname'] . " " . $row_users['adjective'] . " " . $row_users['lastname'] . " (" . $row_users['loginname'] . ")</option>";
		}
?>
		</select>
		<input type="submit" name="removeUser" value="Remove User"> 
	</form>
<?php
		break;
	case "curusr":
		echo "The current user is " . $_SESSION['login'];
		break;
	default:
		echo "Defalut user page!!";
}
?>