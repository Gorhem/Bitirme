<!DOCTYPE html>
<html>
<head>
	<title></title>
<style type="text/css">
	#submit {
    background-color: #C1DAD7;
    color: white;
    padding: 14px;
    font-size: 14px;
    border: none;
    cursor: pointer;
}
input{
	    position: absolute;
	    left: 180px;
}
</style>
</head>
<body>

<?php 
session_start();
include "connect.php"; 
include "topadmin.php"; 
if(isset($_POST['name'])){
	$name = $_POST["name"];
	$phone = $_POST["phone"];
	$age = $_POST["age"];
	$gender = $_POST["gender"];
	$email = $_POST["email"];

	 $sql = "INSERT INTO dentist (did, name, age, sex ,phone,email)
VALUES (' ', '$name', '$age', '$gender','$phone','$email')";
mysqli_query($dbcon, $sql);


$q = "SELECT did FROM dentist WHERE (email='$email' AND name='$name')";
$q1=mysqli_query($dbcon, $q);

$result1=mysqli_fetch_array($q1);
$_SESSION['lastid'] = $result1['did'];
   header('Location: importdoc.php');

}
?>
<br>
<div class="outer">
<div class="wrap">
<h2 class="title">Register Users</h2>
<form action="adddoc.php" method="post" class="form">
<p><label class="label" for="name">Doctor's Name:</label> 
<input id="fname" type="text" name="name" size="30" maxlength="30" 
value="<?php if (isset($_POST['name'])) echo $_POST['name']; ?>"></p>
<p><label class="label" for="phone">Doctor's Phone:</label>
<input id="lname" type="text" name="phone" size="30" maxlength="40" 
value="<?php if (isset($_POST['phone'])) echo $_POST['phone']; ?>"></p>
<p><label class="label" for="age">Doctor's Age:</label>
<input id="lname" type="number" name="age" size="30" maxlength="40" 
value="<?php if (isset($_POST['age'])) echo $_POST['age']; ?>"></p>

<p><label class="label" for="email">Doctor's Email:</label>
<input id="email" type="email" name="email" size="30" maxlength="60" 
value="<?php if (isset($_POST['email'])) echo $_POST['email']; ?>" > </p>
<p><label class="label" for="gender">Doctor's Gender:</label>
<input id="text" type="text" name="gender" size="12" maxlength="12"
value="<?php if (isset($_POST['gender'])) echo $_POST['gender']; ?>" ></p>


<p><input  style="margin-bottom: 2px; width: 200px"  id="submit" type="submit" name="submit" value="Add Doctor"></p>
</form>

</div>
</div>
</body>
</html>