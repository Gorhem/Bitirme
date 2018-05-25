<?php
if (!@$dbcon=mysqli_connect("127.0.0.1","root","","dentalclinic")){
    die("Mysql'e bağlantı kurulamadı!".mysqli_error());
}
?>﻿