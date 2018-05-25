<?php 
include "connect.php";
$doc= $_POST['doc'];
$date= $_POST['date'];
		$sqldoc = mysqli_query($dbcon,"SELECT did FROM dentist WHERE name ='$doc'"); 
		$result1=mysqli_fetch_array($sqldoc);
		$docid = $result1['did'];
		$sqlreg =  mysqli_query($dbcon,"SELECT regtime , userid FROM appointement WHERE dentistId = '$docid' AND regdate = '$date'  ");
	    while($row1 = $sqlreg->fetch_assoc()){
	  	echo $row1['regtime'].";".$row1['userid'].";";
	  }
 ?>