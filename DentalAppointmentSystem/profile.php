<!DOCTYPE html>
<html>
<head>
	<title>Profile</title>
</head>
<body>
<?php include "top.php";
	  echo "<br>";
	  include "connect.php";
	  session_start();
	  $id=$_SESSION["userid"];
	  $sorgu1= mysqli_query($dbcon,"SELECT * FROM signup WHERE userid='$id'"); 
	  $result1=mysqli_fetch_array($sorgu1);
	  echo "<h3>"."Name : ".$result1['name']."<h3>"."\r\n";
	  echo "<h3>"."Tel. Number : ".$result1['phone']."<h3>"."\r\n";
	  echo "<h3>"."Age : ".$result1['age']."<h3>"."\r\n";
	  echo "<h3>"."Address : ".$result1['address']."<h3>"."\r\n";
	  echo "<h3>"."E-Mail : ".$result1['email']."<h3>";

	  ?>
<h2></h2>
</body>
</html>