<?php 
include "connect.php";
session_start();
$docname = $_POST['doc'];
$date = $_POST['date'];
$hour = $_POST['hour'];
$id=$_SESSION["userid"];
		$sqldoc = mysqli_query($dbcon,"SELECT did FROM dentist WHERE name ='$docname'"); 
		$result1=mysqli_fetch_array($sqldoc);
		$docid = $result1['did'];
$sql= "UPDATE appointement SET userid = '$id' WHERE dentistId='$docid' and regdate='$date'and regtime = '$hour'";
mysqli_query($dbcon,$sql);
?>