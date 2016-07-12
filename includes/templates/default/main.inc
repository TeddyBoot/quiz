<?php
if ( $page == "users" ) {
	echo "\t\t\t<aside>\n";
	echo "\t\t\t\t<ul>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=users&action=list\">List users</a></li>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=users&action=add\">Add user</a></li>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=users&action=rem\">Remove user</a></li>\n";
	echo "\t\t\t\t</ul>\n";
	echo "\t\t\t</aside>\n";
}

if ( $page == "contact" ) {
	echo "\t\t\t<aside>\n";
	echo "\t\t\t\t<ul>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=contact&action=address\">Contact info</a></li>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=contact&action=email\">Send us an email</a></li>\n";
	echo "\t\t\t\t</ul>\n";
	echo "\t\t\t</aside>\n";
}

if ( $page == "questions" ) {
	echo "\t\t\t<aside>\n";
	echo "\t\t\t\t<ul>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=questions&action=list\">List all questions</a></li>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=questions&action=add\">Add a question</a></li>\n";
	echo "\t\t\t\t\t<li><a href=\"index.php?page=questions&action=rem\">Remove a question</a></li>\n";
	echo "\t\t\t\t</ul>\n";
	echo "\t\t\t</aside>\n";
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
	case "questions":
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/pages/question.inc';
		break;
	case "users":
		include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/site_admin/userspage.inc';
		break;
	default:
		echo "Defalut page<br />";
}
?>
			</section>
