<?php
header("Access-Control-Allow-Origin: *");

// $conn = mysqli_connect("localhost","id19155376_aquaponics","SmartAquaponicsV.1","id19155376_smartaquaponics");
$conn = mysqli_connect("localhost","root","","design_project");
$sql_command1 = "UPDATE wifi_ip SET ip_address = '".$_GET["ip_add"]."'";

$conn->query($sql_command1);


?>