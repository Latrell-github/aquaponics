<?php
header("Access-Control-Allow-Origin: *");
// $conn = mysqli_connect("localhost","id19155376_aquaponics","SmartAquaponicsV.1","id19155376_smartaquaponics");
$conn = mysqli_connect("localhost","root","","design_project");



 $sql_command1 = "SELECT ip_address FROM wifi_ip ";

 $result1 = $conn->query($sql_command1);

 if($result1->num_rows > 0){
     while($row = $result1->fetch_assoc()){
         echo $row["ip_address"];
     }

 }
 else{
     echo "0 result";
 }

?>