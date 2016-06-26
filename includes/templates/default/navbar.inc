<ul>
<?php
$page = $_GET ['page'];
$pageLower = strtolower($page);
include 'includes/cnnctdb.inc';
$sql_qry = "SELECT * FROM $menuItems WHERE parent=0";
$result = mysqli_query( $link, $sql_qry );
if ( $result ) {
	while ( $row = mysqli_fetch_array($result) ) {
		if ( "$page" == "$row ['menu_item']" ) {
			echo "<li><a class=\"active\" href=\"" . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>";
		} else {
			echo "<li><a href=\"" . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>";
		}
	}
} else {
	echo mysqli_error( $link );
}
mysql_close( $link );
?>
</ul>