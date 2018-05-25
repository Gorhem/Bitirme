<?php
        include "connect.php";
 if(isset($_POST['app'])){
            $app = $_POST['app'];
            $sql = "UPDATE appointement SET userid = 0 WHERE appid = '$app'" ;
    if (mysqli_query($dbcon, $sql)) {
   header('Location: history.php');
}
else {
   echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}
 }
             ?>