<!DOCTYPE html>
 <html>
 <head>
 	<title>Shedule</title>
 <link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
  <link rel="stylesheet" href="/resources/demos/style.css">
  <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
  <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>

<style>
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
#datepicker {
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
#datepicker:focus {outline: 3px solid #ddd;}
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
tr#row:hover{
background:#CAE8EA;
color:#fff;
}
 td#cell:hover{
background:#CAE8EA;
color:#fff;
}
</style>




 	 <script>
  $( function() {
    $( "#datepicker" ).datepicker();
  } );



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
      input.value=text.trim(); };
	//Event.observe(a,'click',ss(a));

	  div = document.getElementById("myDropdown");
	  div.appendChild(a);

        	}
}


function myFunction() {
    	document.getElementById("myDropdown").classList.toggle("show");
}

function filterFunction() {
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
}

function tableCreate() {
  
       
	var divwrite = document.getElementById("tab");
        	
    var doc=document.getElementById("myInput").value;
	var dat=document.getElementById("datepicker").value;
     var input='doc='+doc+'&date='+dat; 
    
      $.ajax({ 
          type:'POST',  
          url:'appointment.php',  
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
    	var date = row.insertCell(0);
    	var doktor = row.insertCell(0);
    	doktor.innerHTML = "<b>Doctor Name</b>";
    	date.innerHTML = "<b>Date</b>";


        for(var j=0; j<arrStr.length-1; j+=2){
     
            var row = document.createElement("tr");
            row.id="row";
           
						            	row.onclick = function () { 
                            var rid =this.id;
                            text=this.innerHTML; var n=this.cells[0].innerHTML; var d =this.cells[1].innerHTML;
						            		 var input='doc='+n +'&date='+ d;

												  			$.ajax({ 
												          type:'POST',  
												          url:'link.php',  
												          data:input,  
												          success: 
												        function(cevap){ 
												          // document.getElementById("write").innerHTML=rid;
												//document.getElementById("dom-day").innerHTML=cevap;

												             dayCreate(cevap,n,d,rid); 
												        } 
												      });
												            	$(window).scrollTop(0);};

						            
              
             var cell = document.createElement("td");    
                  var cellText = document.createTextNode(arrStr[j]); 

                cell.appendChild(cellText);
                row.appendChild(cell);
            
            var cell2 = document.createElement("td");    
                  var cellText2 = document.createTextNode(arrStr[j+1]); 

                cell2.appendChild(cellText2);
                row.appendChild(cell2);

      
            tblBody.appendChild(row);
        									}

    
        tbl.appendChild(tblBody);

        divwrite.appendChild(tbl);
        
        tbl.setAttribute("border", "2");
        } 
      });


    
}

function clearsearch(){
 	document.getElementById("myInput").value="";
  	document.getElementById("datepicker").value="";
  	  var delday =document.getElementById("newday");
        var delhour =document.getElementById("newhour");
        if (typeof(delday) != 'undefined'){
        if( delday != null){
        	 
        	delday.parentNode.removeChild(delday);
        	delhour.parentNode.removeChild(delhour);
        
        }}
}



function dayCreate(a,dname,ddate,rid){
var div = document.getElementById("day");
//var data = document.getElementById("dom-day");
//document.getElementById("dom-day").innerHTML="08:00";
        
  //  var names = data.textContent;
    var arrStr = a.split(/[;]/);

 



        var delhour =document.getElementById("newhour");
        if (typeof(delhour) != 'undefined'){
        if( delhour != null){
        	 
        	
        	delhour.parentNode.removeChild(delhour);
        
        }}
        var tbl     = document.createElement("table");
        tbl.id="newhour";
        var tblBody = document.createElement("tbody");
       	var header = tbl.createTHead();
    	var row = header.insertRow(0);
    	var hours = row.insertCell(0);
    	hours.innerHTML = "<b>Hours</b>";
   

        for(var j=0; j<8;j++){
    
            var row = document.createElement("tr");
            	

      
             var cell = document.createElement("td");    
                
               
                  	
                 
                  if(j+8<10){
                  var str = "0"+(j+8)+":00";

               }
                  else{
                  	var str = (j+8)+":00";
                  }
                   if(j+9<10){
                  var str1 = "0"+(j+9)+":00";}
                  else{
                  	var str1 = (j+9)+":00";
                  }

   var cellText = document.createTextNode(str); 
                  cell.setAttribute("style","background-color: #C1DAD7;");
                  // document.getElementById("myInput").value=data.textContent;
               
                cell.appendChild(cellText);
                row.appendChild(cell);
for(var i=0; i<arrStr.length;i+=2){

            if(arrStr[i]>=str){
            	if(arrStr[i]<str1){
           

            var cell2 = document.createElement("td");  
cell2.id="cell";
                  var cellText2 = document.createTextNode(arrStr[i]); 
                  	if(arrStr[i+1]==0){  
cell2.onclick= function(){

var r = confirm("Are you sure you want to make an appointment for this date?");
    if (r == true) {
    	var send ='hour='+this.innerHTML+'&doc='+dname+'&date='+ddate;
       			$.ajax({ 
												          type:'POST',  
												          url:'saat.php',  
												          data:send,  
												          success: 
												        function(cevap){ 
												           
												alert("Appointment date was successfully received.");

                    document.getElementById(rid).click();


												        } 
												      });


    }};

    
    	
    }
    else{
cell2.onclick= function(){

alert("This date is unavailable. Please select another date!");};
    	cell2.setAttribute("style","background-color: red;");
      cellText2 = document.createTextNode("Taken!");
    }
                cell2.appendChild(cellText2);
                row.appendChild(cell2);
               
}}



}

          
            tblBody.appendChild(row);
        									}

       
        tbl.appendChild(tblBody);
      
        div.appendChild(tbl);
      
        tbl.setAttribute("border", "2");
}


  </script>



 </head>
 <body  onload="linkkoy()">
<?php include "top.php" ?>

<div id="dom-day" ></div>

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




<div class="dropdown">
	<input type="text" placeholder="Doctor Name:" id="myInput" onkeyup="filterFunction()">
<input type="text" placeholder="Date:" id="datepicker" >
 
<button id="list" onclick="myFunction()" class="dropbtn">  &or;</button>
  <div id="myDropdown" class="dropdown-content"></div>
</div>

<button class="dropbtn" onclick="tableCreate()">Search</button>
<button class="dropbtn" onclick="clearsearch()">Clear</button>
<div>
	<div id="tab" class="float" ></div>

<div id="day"></div>
<div id="write"></div>
</div>



 </body>
 </html>