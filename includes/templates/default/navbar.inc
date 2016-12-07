			<ul>
<?php
if (isset ($_GET['page'])) {
	$page = $_GET ['page'];
	if ($_GET['page'] == "logout") {
		$page = "home";
	}
} else {
	$page = "home";
}

include $_SERVER['DOCUMENT_ROOT'] . $appDir  . '/includes/cnnctdb.inc';
switch ($_SESSION['role']) {
	case 1:
		$sql_qry = "SELECT * from $g_MenuItems WHERE parent<=10 AND id<100 ORDER BY id";
		$result = mysqli_query( $link, $sql_qry );
		if ( $result ) {
			while ( $row = mysqli_fetch_array($result) ) {
				$menuLower = strtolower($row['menu_item']);
				if ( "$page" == "$menuLower" ) {
					echo "\t\t\t\t<li><a class=\"active\" href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>\n";
					} else {
						echo "\t\t\t\t<li><a href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>\n";
					}
				}
			} else {
				echo mysqli_error( $link );
			}
		break;
	case 2:
		$sql_qry = "SELECT * from $g_MenuItems WHERE parent<=5 AND id<100 ORDER BY id";
		$result = mysqli_query( $link, $sql_qry );
		if ( $result ) {
			while ( $row = mysqli_fetch_array($result) ) {
				$menuLower = strtolower($row['menu_item']);
				if ( "$page" == "$menuLower" ) {
					echo "\t\t\t\t<li><a class=\"active\" href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>\n";
				} else {
					echo "\t\t\t\t<li><a href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>\n";
				}
			}
		} else {
			echo mysqli_error( $link );
		}
		break;
	default:
		$sql_qry = "SELECT * FROM $g_MenuItems WHERE parent=0 ORDER BY id";
		$result = mysqli_query( $link, $sql_qry );
		if ( $result ) {
			while ( $row = mysqli_fetch_array($result) ) {
				$menuLower = strtolower($row['menu_item']);
				if ( "$page" == "$menuLower" ) {
					echo "\t\t\t\t<li><a class=\"active\" href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>\n";
				} else {
					echo "\t\t\t\t<li><a href=\"/" . $_SESSION['G_dir'] . $row ['link'] . "\">" . $row ['menu_item'] . "</a></li>\n";
				}
			}
		} else {
			echo mysqli_error( $link );
		}
	}
	mysqli_close( $link );
?>
			</ul>
