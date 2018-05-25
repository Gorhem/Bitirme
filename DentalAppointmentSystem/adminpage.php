<!DOCTYPE html>
<html>
<head>
	<title>Profile</title>
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
	<?php include "topadmin.php";
		  include "connect.php";
	  $sorgu1= mysqli_query($dbcon,"SELECT * FROM dentist"); 
	  while($row = $sorgu1->fetch_assoc()) : 

	 	   echo "<h3>"."Doctor Name : ".$row['name']."<h3>"."\r\n";
 
?>
            <form action="removedoc.php" method="post" >          
            <button style="margin-bottom: 2px; width: 200px"  type="submit" name = "app"  value = <?php echo '"'.$row['did'].'"' ?> > Delete Doctor </button>
            </form>
            <?php endwhile;
	  ?>
<h2></h2>
</body>
</html>