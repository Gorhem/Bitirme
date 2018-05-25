<?php 
include "connect.php";
ini_set("max_execution_time", 0);
for ($doc = 1; $doc<=6;$doc++){
	for ($k=1; $k < 15; $k++) {
	for ($i=8; $i < 17; $i++) { 
		for ($j=0; $j < 4; $j+=3) { 
			if ($k<10) {
				$regdate="06/0"."$k"."/2018";
			}else{
				$regdate="06/"."$k"."/2018";
			}
			if ($i<10) {
				$regtime="0"."$i".":"."$j"."0";
			}else{
				$regtime="$i".":"."$j"."0";
			}
			/*echo "dentistID: ".$doc."<br>";
			echo "regdate: ".$regdate."<br>";
			echo "regtime: ".$regtime."<br>";
			echo "<br>";*/
			$sql = "INSERT INTO appointement (dentistId, regdate, regtime)
VALUES ('$doc', '$regdate','$regtime' )";
mysqli_query($dbcon, $sql);
			}
		}
	}
}
?>