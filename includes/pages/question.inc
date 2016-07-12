<?php
switch ($_GET['action']) {
	case "list":
		
		break;
	case "add":
		?>
				<form action="site_admin.php" method="post">
					<table>
						<tr><td>Question:</td><td><input type="text" name="quest"></td></tr>
						<tr><td>Type of question</td><td>
							<select id="select" name="questype" onChange="handleSelection(value)">
							<option SELECTED>Choose your type</option>
							<option value="a1">open question</option>
							<option value="a2">multiple choice question</option>
							<option value="a3">mc or open</td></tr>
						<tr class="hideRow" id="a1"><td>Awnser:</td><td><textarea name="answ1">Correct awnser here please</textarea></td></tr>
						<tr class="hideRow" id="a2"><td class="topAlign">Awnser2:</td><td><div id="dynamicInput">
							<textarea name="myInputs[]">Correct awnser here please</textarea><br />
							</div>
							<input type="button" value="+" onClick="addInput('dynamicInput');">
							</td></tr>
					</table>
				</form>
		<?php 
		break;
	case "rem":
		break;
	default:
		echo "Welcome<br />\n";
		echo "This page will provide you as an admin to manage the questions in this applicaton.<br />\n";
		echo "Creating the test/quiz itself based on the questions you manage here is done under the test/quiz tab.<br />\n";
}
?>