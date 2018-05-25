<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css"  href="top.css" >
	<style type="text/css">
		button {
    background-color: #C1DAD7;
    color: white;
    padding: 14px;
    font-size: 14px;
    border: none;
    cursor: pointer;
}
	</style>
</head>
<body>
	<?php include "top.php" ?>

	<!--<img src="this.jpg" class="img" height="500" width="900" >-->
	<br>
	<h1>My Appointments</h1>
	<?php 
	  echo "<br>";
	  include "connect.php";
	  session_start();
	  $id=$_SESSION["userid"];
	  $sorgu1= mysqli_query($dbcon,"SELECT * FROM appointement WHERE userid='$id'"); 

	  
	  
	  //$docid = $result1['did'];

	  while($row = $sorgu1->fetch_assoc()) : 
	  		$docid=$row['dentistId'];
	  		$sqldoc = mysqli_query($dbcon,"SELECT name FROM dentist WHERE did ='$docid'"); 
	  		$resultdoc=mysqli_fetch_array($sqldoc);
           echo "<h3>"."Doctor Name : ".$resultdoc['name']."<h3>"."\r\n";
	 	   echo "<h3>"."Appointment Date : ".$row['regdate']."<h3>"."\r\n";
	       echo "<h3>"."Appointment Time : ".$row['regtime']."<h3>"."\r\n";
	       if ($row['regdate']>date("m/d/Y")) {
	          	echo "Active";
	          }
	          else{
	          	echo "Date Passed";
	          }   
?>
              <form action="removeapp.php" method="post" >          
            <button  style="margin-bottom: 2px; width: 200px" type="submit" name = "app"  value = <?php echo '"'.$row['appid'].'"' ?> > X </button>
            </form>
            <?php endwhile;

   ?>
</body>
</html>