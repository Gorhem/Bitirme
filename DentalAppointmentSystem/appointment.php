<?php 
include "connect.php";
if ($_POST['date']&& $_POST['doc']) {
	$date = $_POST["date"];
	$doc = $_POST["doc"];
	$sqldoc = mysqli_query($dbcon,"SELECT did FROM dentist WHERE name ='$doc'"); 
	$result1=mysqli_fetch_array($sqldoc);
	$id = $result1['did'];
	$sqlreg =  mysqli_query($dbcon,"SELECT DISTINCT (regdate) , dentistId FROM appointement WHERE dentistId = '$id' AND regdate >= '$date' ");

}else{
	if ($_POST['date']) {
		$date = $_POST["date"];
		$sqlreg =  mysqli_query($dbcon,"SELECT DISTINCT (regdate) ,dentistId FROM appointement WHERE regdate = '$date' ");
		
	}elseif ($_POST['doc']) {
		$doc = $_POST["doc"];
		$sqldoc = mysqli_query($dbcon,"SELECT did FROM dentist WHERE name ='$doc'"); 
		$result1=mysqli_fetch_array($sqldoc);
		$id = $result1['did'];
		$sqlreg =  mysqli_query($dbcon,"SELECT DISTINCT (regdate) ,dentistId FROM appointement WHERE dentistId = '$id'");
		
	}else{
		$sqlreg =  mysqli_query($dbcon,"SELECT DISTINCT (regdate) ,dentistId FROM appointement");
		
}
}
		while($row1 = $sqlreg->fetch_assoc()){
		$docid =$row1['dentistId'];
		$sqldocname = mysqli_query($dbcon,"SELECT name FROM dentist WHERE did ='$docid'"); 
		$resultname=mysqli_fetch_array($sqldocname);
	  	echo $resultname['name'].";".$row1['regdate'].";";
		}
 ?>