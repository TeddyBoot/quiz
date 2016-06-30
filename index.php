<?php
	session_start ();
	/*require_once*/
	require 'includes/settings.inc';
?>
<!DOCTYPE HTML>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Create a test/quiz</title>
		<link href="<?php echo $_SESSION['stylesheet']; ?>" rel="stylesheet">
	</head>
	<body>
		<header>
<?php include $_SESSION['templateDir'] . "/header.inc"; ?>
		</header>
		<nav>
<?php include $_SESSION['templateDir'] . "/navbar.inc"; ?>
		</nav>
		<article>
<?php include $_SESSION['templateDir'] . "/main.inc"; ?>
		</article>
		<footer>
<?php include $_SESSION['templateDir'] . "/footer.inc"; ?>
		</footer>
	</body>
</html>