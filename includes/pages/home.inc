<?php
echo "Home page<br />\n";
if ( isset ( $errMsg ) ) {
	echo $errMsg . "<br />\n";
} elseif ( isset ($message) ) {
	echo $message . "<br />\n";
} else {
	echo "Welcome<br />\n";
	echo "This page will provide tests or quizes to use either directly on this webpage or to print out and use as a test in the classroom. Regular users will only be able to fill out the tests. Super users will be able to create a test/quiz and add questions to the database. The admin users are also able to add users to login with one of these roles.<br />\n";
	echo "This page is still under construction so not everything works as it should.<br />\n";
}
?>
