<article>
<?php
switch ($page) {
	case "home":
		echo "Home page";
		break;
	case "login":
		echo "Login page\n";
?>
<form action="index.php?page=login">
	<input type="text" name="loginName">
	<input type="password" name="passwd">
	<input type="submit" value="Login">
</form>
<?php
		break;
	case "contact":
		echo "Contact page";
		break;
	default:
		echo"Defalut page";
}
?>
</article>