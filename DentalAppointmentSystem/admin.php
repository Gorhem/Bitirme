 <!DOCTYPE html>
 <html>
 <head>
 	<title>View Appointments</title>
 <link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
  <link rel="stylesheet" href="/resources/demos/style.css">
  <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
  <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
<style>
button {
    background-color: #C1DAD7;
    color: white;
    padding: 14px;
    font-size: 14px;
    border: none;
    cursor: pointer;
}

.dropbtn {
    background-color: #C1DAD7;
    color: white;
    padding: 14px;
    font-size: 14px;
    border: none;
    cursor: pointer;
}

.dropbtn:hover, .dropbtn:focus {
    background-color: #C1DAD7;
}

#myInput {
    border-box: box-sizing;
    background-image: url('searchicon.png');
    background-position: 14px 12px;
    background-repeat: no-repeat;
    font-size: 16px;
    padding: 14px 20px 12px 45px;
    border: none;
    border-bottom: 1px solid #ddd;
    float: left;
}

#myInput:focus {outline: 3px solid #ddd;}

.dropdown {
    position: relative;
    display: inline-block;
    
}

.dropdown-content {
    display: none;
    position: absolute;
    background-color: #f6f6f6;
    min-width: 230px;
    overflow: auto;
    border: 1px solid #ddd;
    z-index: 1;
}

.dropdown-content a {
    color: black;
    padding: 12px 16px;
    text-decoration: none;
    display: block;
}


.dropdown a:hover {background-color: #ddd}

.show {display:block;}
.hide {display:none;}
.day {display:none;}
.float{float: left;}


table{
width: 50%;
font: bold 1.25em "Trebuchet MS", Verdana, Arial, Helvetica,
sans-serif;
border: 20px solid #C1DAD7;
letter-spacing: 2px;
text-transform: uppercase;
text-align: left;
padding: 6px 6px 6px 12px;
background: #C1DAD7;
border-collapse: collapse;
}
 
th{
color: #54737A;
padding: 6px 6px 6px 12px;
 
}
 
 td{
padding: 6px 6px 6px 12px;
font-family: 'Montserrat', sans-serif;
font-weight: 300;
}
 tr{
color: #6D929B;
background: #fff;
}
 tr:hover{
background:#CAE8EA;
color:#fff;
}
</style>

<script type="text/javascript">
	
function linkkoy(){

	var div = document.getElementById("dom-target");
    var names = div.textContent;
    var arrStr = names.split(/[;]/);



        	for(var i=0; i<arrStr.length-1; i++){
	var a = document.createElement('a');
	a.innerHTML=arrStr[i];
	a.href="javascript:void(0);";
	//a.onclick=ss(a);
	a.onclick = function () { text=this.innerHTML; input=document.getElementById("myInput");
      input.value=text.trim();
      };
	//Event.observe(a,'click',ss(a));

	  div = document.getElementById("myDropdown");
	  div.appendChild(a);

        	}
}

/*function filterFunction() {
	document.getElementById("myDropdown").classList.toggle("show");

	
    var input, filter, ul, li, a, i;
    input = document.getElementById("myInput");
    filter = input.value.toUpperCase();
    div = document.getElementById("myDropdown");
    a = div.getElementsByTagName("a");
    for (i = 0; i < a.length; i++) {
        if (a[i].innerHTML.toUpperCase().indexOf(filter) > -1) {
            a[i].style.display = "";
        } else {
            a[i].style.display = "none";
        }
    }
}*/


function myFunction() {
    	document.getElementById("myDropdown").classList.toggle("show");
}

function tableCreate() {
  
       
	var divwrite = document.getElementById("tab");
        	
    var doc=document.getElementById("myInput").value;
	
     var input='doc='+doc; 
    
      $.ajax({ 
          type:'POST',  
          url:'doc.php',  
          data:input,  
          success: 
        function(cevap){ 
           
//document.getElementById("dom-day").innerHTML=cevap;

           var arrStr = cevap.split(/[;]/);


        var body = document.getElementsByTagName("body")[0];



       
        var delday =document.getElementById("newday");
        var delhour =document.getElementById("newhour");
        if (typeof(delday) != 'undefined'){
        if( delday != null){
        	 
        	delday.parentNode.removeChild(delday);
        	delhour.parentNode.removeChild(delhour);
        
        }
    }
        //document.getElementById("dom-day").innerHTML="del.id";
        var tbl     = document.createElement("table");
        tbl.id="newday";
        

        var tblBody = document.createElement("tbody");
       	var header = tbl.createTHead();
    	var row = header.insertRow(0);
    	var hasta = row.insertCell(0);
    	var gun = row.insertCell(0);
    	var saat = row.insertCell(0);
        var doctorname = row.insertCell(3);
        doctorname.innerHTML = "<b>Doctor Name</b>";
    	hasta.innerHTML = "<b>Hour</b>";
    	gun.innerHTML = "<b>Date</b>";
    	saat.innerHTML = "<b>Patient Name</b>";
    	


        for(var j=0; j<arrStr.length-1; j+=4){
     
            var row = document.createElement("tr");
						            	row.onclick = function () { 


						            		var r = confirm("Are you sure about deleting this appointment?");
    if (r == true) {
        var doc1 = this.cells[3].innerHTML;
						            	var h = this.cells[2].innerHTML;	var d = this.cells[1].innerHTML; var input='doc='+doc1 +'&date='+d+'&hour='+h; 

												  			$.ajax({ 
												          type:'POST',  
												          url:'del.php',  
												          data:input,  
												          success: 
												        function(cevap){ 
												           
												//document.getElementById("dom-day").innerHTML=cevap;

												           alert("Deleted!")
												          tableCreate();
												         tableCreate();
												        } 
												      });

												  		}else{

												  		}
												            	};

						            
              
             var cell = document.createElement("td");    
                  var cellText = document.createTextNode(arrStr[j]); 

                cell.appendChild(cellText);
                row.appendChild(cell);
            
            var cell2 = document.createElement("td");    
                  var cellText2 = document.createTextNode(arrStr[j+1]); 

                cell2.appendChild(cellText2);
                row.appendChild(cell2);
        	
        	var cell3 = document.createElement("td");    
                  var cellText3 = document.createTextNode(arrStr[j+2]); 

                cell3.appendChild(cellText3);
                row.appendChild(cell3);

                var cell4 = document.createElement("td");    
                  var cellText4 = document.createTextNode(arrStr[j+3]); 

                cell4.appendChild(cellText4);
                row.appendChild(cell4);
      
            tblBody.appendChild(row);
        									}

    
        tbl.appendChild(tblBody);

        divwrite.appendChild(tbl);
        
        tbl.setAttribute("border", "2");

        } 
      });


    
}
</script>


</head>
 <body onload="linkkoy()">
<?php include "topadmin.php" ?>
<div id="dom-target" style="display: none;"><!--Doctor name -->
 	
 	<?php 
    


if (!@$conn=mysqli_connect("127.0.0.1","root","","dentalclinic")){
    die("Mysql'e bağlantı kurulamadı!".mysqli_error());
}


$sql = "SELECT name FROM dentist";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {

echo $row['name'].";";

    }
} else {
    echo "0 results";
}

$conn->close();


    ?>
 </div>
 <br>
<br>
<div class="dropdown">
	<input type="text" placeholder="Doctor Name:" id="myInput" readonly="readonly">

 
<button id="list" onclick="myFunction()" class="dropbtn">  &or;</button>
  <div id="myDropdown" class="dropdown-content"></div>
</div>
<button style="margin-bottom: 2px; width: 200px"  onclick="tableCreate()">Gönder</button>

 <br>
<br>
<div id="tab" class="" ></div>



 </body>
 </html>