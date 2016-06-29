<ul>
<?php
if (isset ($_GET['page'])) {
	$page = $_GET ['page'];
} else {
	$page = "home";
}
include 'includes/cnnctdb.inc';
$sql_qry = "SELECT * FROM $menuItems WHERE parent=0";
$result = mysqli_query( $link, $sql_qry );
if ( $result ) {
	while ( $row = mysqli_fetch_array($result) ) {
		$menuLower = $row['menu_item'];
		if ( "$page" == "$menuLower" ) {
			echo "<li><a class=\"active\" href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>";
		} else {
			echo "<li><a href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>";
		}
	}
} else {
	echo mysqli_error( $link );
}
mysqli_close( $link );
?>
</ul>