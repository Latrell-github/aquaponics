<?php

header("Access-Control-Allow-Origin: *");
date_default_timezone_set("Asia/Manila");
$timestamp = date("Y-m-d H:i:s");

// $conn = mysqli_connect("localhost","id19155376_aquaponics","SmartAquaponicsV.1","id19155376_smartaquaponics");
$conn = mysqli_connect("localhost","root","","design_project");

$sql_command1 = "INSERT INTO soil_data (soil_moisture, timestamp) VALUES ('".$_GET["soil_value"]."', '".$timestamp."')";

$conn->query($sql_command1);

$sql_command2 = "INSERT INTO phlevel_data (ph_level, timestamp) VALUES ('".$_GET["ph_value"]."', '".$timestamp."')";

$conn->query($sql_command2);

$sql_command3 = "INSERT INTO waterlevel_data (water_level, timestamp) VALUES ('".$_GET["water_value"]."', '".$timestamp."')";

$conn->query($sql_command3);

echo "Success";

?>