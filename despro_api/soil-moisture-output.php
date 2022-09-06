<?php
    header("Access-Control-Allow-Origin: *");
    $conn = mysqli_connect("localhost","id19155376_aquaponics","SmartAquaponicsV.1","id19155376_smartaquaponics");



    $sql_command1 = "SELECT soil_moisture FROM soil_data WHERE id = (SELECT MAX(id) FROM soil_data)";

    $result1 = $conn->query($sql_command1);

    if($result1->num_rows > 0){
        while($row = $result1->fetch_assoc()){
            echo $row["soil_moisture"];
        }

    }
    else{
        echo "0 result";
    }

?>