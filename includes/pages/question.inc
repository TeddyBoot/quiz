<?php
if (isset($_GET['action'])){
	switch ($_GET['action']) {
		case "list":
			echo "\t\t\t\t<ul>\n";
			include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/cnnctdb.inc';
			$sqlQuery = "SELECT * FROM $g_QuestTitles";
			$result = mysqli_query( $link, $sqlQuery );
			mysqli_close ($link);
			while ($row_questTitles = mysqli_fetch_array($result)) {
				echo "\t\t\t\t\t<li>" . $row_questTitles['title'] . "</li>\n";
			}
			echo "\t\t\t\t</ul>\n";
			break;
		case "add":
			?>
					<form action="index.php?page=questions&action=add2" method="post">
						<table>
							<tr><td>Question:</td><td><input type="text" name="quest"></td></tr>
							<tr><td>Type of question:</td><td>
								<select id="select" name="questype" onChange="handleSelection(value,'a1','a2')">
									<option SELECTED>Choose your type</option>
									<option value="a1">open question</option>
									<option value="a2">multiple choice question</option>
									<option value="a3">mc or open</option></select></td></tr>
							<tr class="hideRow" id="a1"><td>Awnser:</td><td><textarea name="answ1">Correct awnser here please</textarea></td></tr>
							<tr class="hideRow" id="a2"><td class="topAlign">Awnser2:</td><td><div id="dynamicInput">
								<textarea name="myInputs[]">Correct awnser here please</textarea><br />
								</div>
								<input type="button" value="+" onClick="addInput('dynamicInput');">
								</td></tr>
							<tr><td>Topic:</td><td>new<input type="radio" name="topicChoice" value="t1" onChange="handleSelection(value,'t1','t2')">list<input type="radio" name="topicChoice" value="t2" onChange="handleSelection(value,'t1','t2')"></td></tr>
							<tr class="hideRow" id="t1"><td>Short name:</td><td><input type="text" name="topic1"></td></tr>
							<tr class="hideRow" id="t2"><td>Select one:</td><td>
								<select name="topic2">
<?php 
include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/cnnctdb.inc';
$sqlQuery = "SELECT * FROM $g_QuizTopics";
$result = mysqli_query( $link, $sqlQuery );
mysqli_close ($link);
while ($row_quizTopics = mysqli_fetch_array($result)) {
	echo "\t\t\t\t\t\t\t\t\t<option value=\"" . $row_quizTopics['id'] . "\">" . $row_quizTopics['name'] . "</option>\n";
}
?>
								</select></td></tr>
							<tr><td>For School:</td><td>yes<input type="radio" name="nonScholar" value="school1" onChange="handleSelection(value,'school1','school2')">no<input type="radio" name="nonScholar" value="school2" onChange="handleSelection(value,'school1','school2')"></td></tr>
							<tr class="hideRow" id="school1"><td valign="top">School level:</td><td>
								Vmbo 1<input type="checkbox" name="vm1">
								Vmbo 2<input type="checkbox" name="vm2">
								Vmbo 3<input type="checkbox" name="vm3">
								Vmbo 4<input type="checkbox" name="vm4"><br />
								Havo 1<input type="checkbox" name="h1">
								Havo 2<input type="checkbox" name="h2">
								Havo 3<input type="checkbox" name="h3">
								Havo 4<input type="checkbox" name="h4">
								Havo 5<input type="checkbox" name="h5"><br />
								Vwo 1<input type="checkbox" name="v1">
								Vwo 2<input type="checkbox" name="v2">
								Vwo 3<input type="checkbox" name="v3">
								Vwo 4<input type="checkbox" name="v4">
								Vwo 5<input type="checkbox" name="v5">
								Vwo 6<input type="checkbox" name="v6"></td></tr>
							<tr class="hideRow" id="school2"><td></td><td></td></tr>
							<tr><td colspan="2" align="center"><input type="submit" value="Invoeren"></td></tr>
						</table>
					</form>
<?php 
			break;
		case "add2":
?>
					<form action="includes/page/addquest.php" method="post">
						<table>
							<tr><td>Question:</td><td><input type="text" name="quest"></td></tr>
							<tr><td>Type of question:</td><td>
								<select id="select" name="questype" onChange="handleSelection(value,'a1','a2')">
									<option SELECTED>Choose your type</option>
									<option value="a1">open question</option>
									<option value="a2">multiple choice question</option>
									<option value="a3">mc or open</option></select></td></tr>
							<tr class="hideRow" id="a1"><td>Awnser:</td><td><textarea name="answ1">Correct awnser here please</textarea></td></tr>
							<tr class="hideRow" id="a2"><td class="topAlign">Awnser2:</td><td><div id="dynamicInput">
								<textarea name="myInputs[]">Correct awnser here please</textarea><br />
								</div>
								<input type="button" value="+" onClick="addInput('dynamicInput');">
								</td></tr>
							<tr><td>Subject:</td><td>new<input type="radio" name="subjectChoice" value="s1" onChange="handleSelection(value,'s1','s2')">list<input type="radio" name="subjectChoice" value="s2" onChange="handleSelection(value,'s1','s2')"></td></tr>
							<tr class="hideRow" id="s1"><td>Subject:</td><td><input type="text" name="subject1"></td></tr>
							<tr class="hideRow" id="s2"><td>Subject:</td><td>
								<select name="subject2">
<?php 

?>
								</td></tr>
							<tr><td colspan="2" align="center"><input type="submit" value="Invoeren"></td></tr>
						</table>
					</form>
			<?php 
			break;
		case "rem":
			break;
		default:
			echo "\t\t\t\tWelcome<br />\n";
			echo "\t\t\t\tThis page will provide you as an admin to manage the questions in this applicaton.<br />\n";
			echo "\t\t\t\tCreating the test/quiz itself based on the questions you manage here is done under the test/quiz tab.<br />\n";
	}
} else {
	echo "\t\t\t\tWelcome<br />\n";
	echo "\t\t\t\tThis page will provide you as an admin to manage the questions in this applicaton.<br />\n";
	echo "\t\t\t\tCreating the test/quiz itself based on the questions you manage here is done under the test/quiz tab.<br />\n";
}
?>