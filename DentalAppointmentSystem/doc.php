<?php 
include "connect.php";

if($_POST["doc"]){
$doc = $_POST["doc"];

$sqldoc = mysqli_query($dbcon,"SELECT did,name FROM dentist WHERE name ='$doc'"); 
	  $result1=mysqli_fetch_array($sqldoc);
	  $id = $result1['did'];

	  $sqlreg =  mysqli_query($dbcon,"SELECT  regdate,regtime,userid  FROM appointement WHERE dentistId = '$id' AND userid != 0");
	  // $res=mysqli_fetch_array($sqlreg);

 while($row1 = $sqlreg->fetch_assoc()){
	  $uid =$row1['userid'];
	 
  $sqlreg2 =  mysqli_query($dbcon,"SELECT  name  FROM signup WHERE userid = '$uid'");
	   $res2=mysqli_fetch_array($sqlreg2);
	  $name = $res2['name'];
	  	echo $name.";".$row1['regdate'].";".$row1['regtime'].";".$result1['name'].";";

	  }
	}else{

$sqldoc = mysqli_query($dbcon,"SELECT did,name FROM dentist"); 
	   while($row2 = $sqldoc->fetch_assoc()){
	  $id = $row2['did'];

	  $sqlreg =  mysqli_query($dbcon,"SELECT  regdate,regtime,userid  FROM appointement WHERE dentistId = '$id' AND userid != 0");
	  // $res=mysqli_fetch_array($sqlreg);

 while($row1 = $sqlreg->fetch_assoc()){
	  $uid =$row1['userid'];
	 
  $sqlreg2 =  mysqli_query($dbcon,"SELECT  name  FROM signup WHERE userid = '$uid'");
	   $res2=mysqli_fetch_array($sqlreg2);
	  $name = $res2['name'];
	  	echo $name.";".$row1['regdate'].";".$row1['regtime'].";".$row2['name'].";";

	  }
}





	}





	 
 ?>