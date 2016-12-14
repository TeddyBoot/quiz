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
				echo "\t\t\t\t\t<li>" . $row_questTitles['title'] . " (" . $row_questTitles['questions'] . ")</li>\n";
			}
			echo "\t\t\t\t</ul>\n";
			break;
		case "add":
			?>
					<form name="addquest" id="addquest" action="index.php?page=questions&action=add2" method="post" onSubmit="return checkFromEntries();">
						<table>
							<tr><td>Question:</td><td><input type="text" name="quest" required></td></tr>
							<tr><td>Type of question:</td><td>
								<select id="select" name="questype" onChange="handleSelection(value,'a1','a2')" required>
									<option value="">Choose your type</option>
									<option value="a1">open question</option>
									<option value="a2">multiple choice question</option>
									<option value="a3">mc or open</option></select></td></tr>
							<tr class="hideRow" id="a1"><td>Awnser:</td><td><textarea id="answer1" name="answ1" placeholder="Correct awnser here please"></textarea></td></tr>
							<tr class="hideRow" id="a2"><td class="topAlign">Awnser2:</td><td><div id="dynamicInput">
								<textarea class="answer2" name="myInputs[0]" placeholder="Correct awnser here please"></textarea><br />
								</div>
								<input type="button" value="+" onClick="addInput('dynamicInput');">
								</td></tr>
							<tr><td>Topic:</td><td>
								new<input type="radio" name="topicChoice" value="t1" onChange="handleSelection(value,'t1','t2')" required>
								list<input type="radio" name="topicChoice" value="t2" onChange="handleSelection(value,'t1','t2')"></td></tr>
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
							<tr><td>Difficulty:</td><td>
								<select name="diff" required>
									<option value=""></option>
<?php 
for ($x = 1; $x <= 5; $x++) {
	echo "\t\t\t\t\t\t\t\t\t<option value=\"" . $x . "\">" . $x . "</option>\n";
}
?>
								</select></td></tr>
							<tr><td>For School:</td><td>
								yes<input type="radio" name="nonScholar" value="school1" onChange="handleSelection(value,'school1','school2')" required>
								no<input type="radio" name="nonScholar" value="school2" onChange="handleSelection(value,'school1','school2')"></td></tr>
							<tr class="hideRow" id="school1"><td valign="top">School level:</td><td>
								Vmbo 1<input type="checkbox" name="lv[0]" value ="1">
								Vmbo 2<input type="checkbox" name="lv[1]" value ="2">
								Vmbo 3<input type="checkbox" name="lv[2]" value ="3">
								Vmbo 4<input type="checkbox" name="lv[3]" value ="4"><br />
								Havo 1<input type="checkbox" name="lv[4]" value ="5">
								Havo 2<input type="checkbox" name="lv[5]" value ="6">
								Havo 3<input type="checkbox" name="lv[6]" value ="7">
								Havo 4<input type="checkbox" name="lv[7]" value ="8">
								Havo 5<input type="checkbox" name="lv[8]" value ="9"><br />
								Vwo 1<input type="checkbox" name="lv[9]" value ="10">
								Vwo 2<input type="checkbox" name="lv[10]" value ="11">
								Vwo 3<input type="checkbox" name="lv[11]" value ="12">
								Vwo 4<input type="checkbox" name="lv[12]" value ="13">
								Vwo 5<input type="checkbox" name="lv[13]" value ="14">
								Vwo 6<input type="checkbox" name="lv[14]" value ="15"></td></tr>
							<tr class="hideRow" id="school2"><td></td><td></td></tr>
							<tr><td colspan="2" align="center"><input type="submit" value="Continue"></td></tr>
						</table>
					</form>
<?php 
			break;
		case "add2":
			$_SESSION['setQuest'] = $_POST['quest'];
			$_SESSION['setQuestType'] = $_POST['questype'];
			$_SESSION['setDiff'] = $_POST['diff'];
			if ( $_POST['nonScholar'] == "school1") {
				$_SESSION['setLevel'] = implode(",", $_POST['lv']);
			} else {
				$_SESSION['setLevel'] = "0";
			}
			include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/cnnctdb.inc';			
			if ( $_POST['topicChoice'] == "t1" ) {
				$setTopic = $_POST['topic1'];
				$sqlQuery1 = "select * from $g_QuizTopics where name='$setTopic'";
				$result1 = mysqli_query( $link, $sqlQuery1 );
				if ( null != (mysqli_fetch_array($result1)) ) {
					echo "! This Topic already exists, using the existing one!";
					$setTopicTmp = mysqli_fetch_array($result1);
					$_SESSION['setTopic'] = $setTopicTmp['id'];
					$_SESSION['setTopicName'] = $setTopicTmp['name'];
				} else {
					$sqlQuery2 = "insert into $g_QuizTopics (id,name) values ('','$setTopic')";
					$result2 = mysqli_query( $link, $sqlQuery2 );
					$sqlQuery3 = "select * from $g_QuizTopics where name='$setTopic'";
					$result3 = mysqli_query( $link, $sqlQuery3 );
					$setTopicTmp = mysqli_fetch_array($result3);
					$_SESSION['setTopic'] = $setTopicTmp['id'];
					$_SESSION['setTopicName'] = $setTopicTmp['name'];
				}
			} else {
				$_SESSION['setTopic'] = $_POST['topic2'];
				$sqlQuery4 = "select * from $g_QuizTopics where name='" . $_SESSION['setTopic'] . "'";
				$result4 = mysqli_query( $link, $sqlQuery4 );
				$setTopicTmp = mysqli_fetch_array($result4);
				$_SESSION['setTopicName'] = $setTopicTmp['name'];
			}
			mysqli_close ($link);
			echo "<pre>";
			print_r($_SESSION);
			print_r($_POST);
			echo "</pre>";
?>
					<form action="index.php?page=questions&action=add3" method="post">
						<table>
							<tr><td valign="top">
								Question:</td><td>
								<input type="hidden" name="quest" value="<?php echo $_SESSION['setQuest']; ?>"><?php echo $_SESSION['setQuest']; ?></td></tr>
							<tr><td valign="top">
								Type of question:</td><td>
								<input type="hidden" name="questype" value="<?php
switch ($_SESSION['setQuestType'] ) {
	case "a1":
		echo "1";
		$typeName = "Open question";
		break;
	case "a2":
		echo "2";
		$typeName = "Multiple choice question";
		break;
	case "a3":
		echo "3";
		$typeName = "Multiple choice and/or open question";
		break;
}
?>"><?php echo $typeName; ?></td></tr>
							<tr><td>Subject:</td><td>
								new<input type="radio" name="subjectChoice" value="s1" onChange="handleSelection(value,'s1','s2')">
								list<input type="radio" name="subjectChoice" value="s2" onChange="handleSelection(value,'s1','s2')"></td></tr>
							<tr class="hideRow" id="s1"><td>Subject:</td><td><input type="text" name="subject1"></td></tr>
							<tr class="hideRow" id="s2"><td>Subject:</td><td>
								<select name="subject2">
<?php 
include $_SERVER['DOCUMENT_ROOT'] . $appDir . '/includes/cnnctdb.inc';
$sqlQuery = "SELECT * FROM $g_QuizSubjects where parent='" . $_SESSION['setTopic'] . "'";
$result = mysqli_query( $link, $sqlQuery );
mysqli_close ($link);
while ($row_quizSubjects = mysqli_fetch_array($result)) {
	echo "\t\t\t\t\t\t\t\t\t<option value=\"" . $row_quizSubjects['id'] . "\">" . $row_quizSubjects['name'] . "</option>\n";
}
?>
								</select></td></tr>
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