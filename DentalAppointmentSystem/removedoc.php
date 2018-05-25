<?php
        include "connect.php";
 if(isset($_POST['app'])){
            $app = $_POST['app'];
            $sql = "DELETE FROM dentist WHERE did = '$app'" ;
            $sql1="DELETE FROM appointement WHERE dentistId ='$app'";
            mysqli_query($dbcon, $sql);
            mysqli_query($dbcon, $sql1);
   header('Location: adminpage.php');

   echo "Error: " . $sql . "<br>" . mysqli_error($conn);
 }
?>