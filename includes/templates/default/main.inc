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
	echo "<li><a href=\"index.php?page=contact&action=address\">Contact info</a></li>";
	echo "<li><a href=\"index.php?page=contact&action=email\">Send us an email</a></li>";
	echo "</ul>";
	echo "</aside>";
}

if ( $page == "questions" ) {
	echo "<aside>";
	echo "<ul>";
	echo "<li><a href=\"index.php?page=questions&action=list\">List all questions</a></li>";
	echo "<li><a href=\"index.php?page=questions&action=add\">Add a question</a></li>";
	echo "<li><a href=\"index.php?page=questions&action=rem\">Remove a question</a></li>";
	echo "</ul>";
	echo "</aside>";
}
?>
<section>
<?php
switch ($page) {
	case "home":
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/pages/home.inc';
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
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/site_admin/userspage.inc';
		break;
	case "questions":
  include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/site_admin/question.inc';
	 break;
	default:
		echo "Defalut page<br />";
}
?>
</section>