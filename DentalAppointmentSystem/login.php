
<!doctype html>
<html lang=en>
<head>
<title>The Login page</title>
<meta charset=utf-8>
<link rel="stylesheet" type="text/css" href="top.css">
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
		<div class="top">
		<img src="download.png" width="40" height="40" class="logo">
		<p class="logotext">Dental Appointment System</p>
		</div>
		
		<header class="register">
			<a href="login.php" class="log">Login</a>
			<a href="signup.php" class="log">Sign Up</a>
		</header>

<div id="container">

<div id="content">

<?php
		if ($_SERVER['REQUEST_METHOD'] == 'POST') {
			
				require ('connect.php'); 
		
				if (!empty($_POST['email'])) {
				$e = mysqli_real_escape_string($dbcon, $_POST['email']);
				} else {
				$e = FALSE;
				echo '<p class="error">You forgot to enter your email address.</p>';
				}
			
				if (!empty($_POST['password'])) {
				$p = mysqli_real_escape_string($dbcon, $_POST['password']);
				} else {
				$p = FALSE;
				echo '<p class="error">You forgot to enter your password.</p>';
				}


				if ($e && $p)
				{
							$q = "SELECT userid, user_level FROM signup WHERE (email='$e' AND password='$p')";
						
							$result = @mysqli_query ($dbcon, $q);
						

                             

							if (@mysqli_num_rows($result) == 1) 
							{      
									session_start(); 
									$_SESSION = mysqli_fetch_array ($result, MYSQLI_ASSOC);
						
									$_SESSION['user_level'] = (int) $_SESSION['user_level'];
									$_SESSION['userid'];
						
									
									$url = ($_SESSION['user_level'] === 1) ? 'mainadmin.php' : 'main.php';
									header('Location: ' . $url); 
									exit(); 
									mysqli_free_result($result);
									mysqli_close($dbcon);
							} 

							else { 
									echo '<p class="error">The e-mail address and password entered do not match our records 
									<br>Perhaps you need to register, just click the Register button on the header menu</p>';
							       }

				} 
				else { 
				        echo '<p class="error">Please try again.</p>';
				       }
				mysqli_close($dbcon);
		} 
?>


<div id="loginfields">

<div class="outer">
<div class="wrap">
<h2 class="title">Login</h2>
<form action="?" method="post" class="form">
<p><label class="label" for="email">Email Address:</label>
<input id="email" type="text" name="email" size="30" maxlength="60" 
value="<?php if (isset($_POST['email'])) echo $_POST['email']; ?>" > </p>

<p><label class="label" for="password">Password:</label>
<input id="psword" type="password" name="password" size="12" maxlength="12" 
value="<?php if (isset($_POST['password'])) echo $_POST['password']; ?>" > 

<p><input  style="margin-bottom: 2px; width: 200px"  id="submit" type="submit" name="submit" value="Login"></p>
</form>
</div>
</div>
</div><br>
</div>
</div>

</body>
</html>