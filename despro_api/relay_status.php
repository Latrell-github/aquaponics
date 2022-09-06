<?php

header("Access-Control-Allow-Origin: *");
//$conn = mysqli_connect("localhost","id19155376_aquaponics","SmartAquaponicsV.1","id19155376_smartaquaponics");
$conn = mysqli_connect("localhost","root","","design_project");
$sql_command = "";


if($_GET["type"] == "soil"){
    $sql_command = "UPDATE relay_status SET soil_relay_status = '".$_GET["status"]."'";
}
if($_GET["type"] == "water"){
    $sql_command = "UPDATE relay_status SET water_relay_status = '".$_GET["status"]."'";
}
if($_GET["type"] == "ph"){
    $sql_command = "UPDATE relay_status SET ph_relay_status = '".$_GET["status"]."'";
}
$result1 = $conn->query($sql_command);
echo $result1;

?>