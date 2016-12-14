function handleSelection(choice,variable1,variable2) {
	if(choice==variable1) {
		document.getElementById(variable1).style.display='table-row';
		document.getElementById(variable2).style.display='none';
	}
	else {
		document.getElementById(variable2).style.display='table-row';
		document.getElementById(variable1).style.display='none';
	}
}

var counter = 1;
var limit = 5;
function addInput(divName){
     if (counter == limit)  {
          alert("You have reached the limit of adding " + counter + " inputs");
     }
     else {
          var newdiv = document.createElement('div');
          newdiv.innerHTML = "<textarea name='myInputs["+counter+"]' placeholder=\"Incorrect awnser here\"></textarea><br />";
          document.getElementById(divName).appendChild(newdiv);
          counter++;
     }
}

function checkFromEntries(){
	// check if the correct answer is filled
	var selectForm = document.getElementById("select");
	if (selectForm[selectForm.selectedIndex].value == "a1") {
		var ans1 = document.getElementById("answer1");
		if (ans1.value.length < 1) {
			alert("Awnser has not been filled");
			return false;
		}
	} else if (selectForm[selectForm.selectedIndex].value == "a2") {
		// check if the correct answer is filled
		alert("The value is = "+selectForm[selectForm.selectedIndex].value);
		var ans2 = document.addquest.elements["myInputs[0]"];
		var ans3 = document.addquest.elements["myInputs[1]"];
		if (ans2.value == "") {
			alert("The correct answer has not been filled");
			return false;
		} else if (ans3 == undefined) {
			// check if at least one wrong answer has been filled
			alert("At least one wrong answer has to be filled!");
			return false;
		} else if (ans3.value == "") {
			// check if at least one wrong answer has been filled
			alert("At least one wrong answer has to be filled");
			return false;
		}
	}
	// check if at least one school level has been selected
	var nonScholar = document.addquest.nonScholar.value;
	if (nonScholar == "school1") {
		var tmpX = 0;
		for (var i = 0; i < 15; i++) {
		    var x = "lv["+i+"]";
		    var y = document.addquest.elements[x];
		    if (y.checked == true) {
		    	tmpX++;
		    }
		}
		if (tmpX < 1) {
			alert("no school level selected");
			return false;
		}
	}
}