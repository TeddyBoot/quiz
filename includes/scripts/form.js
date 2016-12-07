function handleSelection(choice,variable1,variable2) {
	//document.getElementById('select').disabled=true;
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
          newdiv.innerHTML = "<textarea name='myInputs[]'>This is " + (counter + 1) + "</textarea><br />";
          document.getElementById(divName).appendChild(newdiv);
          counter++;
     }
}