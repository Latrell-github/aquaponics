<?php
    header("Access-Control-Allow-Origin: *");
    // $conn = mysqli_connect("localhost","id19155376_aquaponics","SmartAquaponicsV.1","id19155376_smartaquaponics");
    $conn = mysqli_connect("localhost","root","","design_project");



    $sql_command1 = "SELECT ph_level FROM phlevel_data WHERE id = (SELECT MAX(id) FROM phlevel_data)";
    $sql_command2 = "SELECT soil_moisture FROM soil_data WHERE id = (SELECT MAX(id) FROM soil_data)";
    $sql_command3 = "SELECT water_level FROM waterlevel_data WHERE id = (SELECT MAX(id) FROM waterlevel_data)";
    $sql_command4 = "SELECT * FROM relay_status";

    
    $result1 = $conn->query($sql_command1);
    $result2 = $conn->query($sql_command2);
    $result3 = $conn->query($sql_command3);
    $result4 = $conn->query($sql_command4);

    $final_array = array();
    if($result1->num_rows > 0){
        while($row = $result1->fetch_assoc()){
            $final_array["ph_level"] = $row["ph_level"];
        }

    }
    else{
        $final_array["ph_level"] = "0";
    }

   

    

    if($result2->num_rows > 0){
        while($row = $result2->fetch_assoc()){
            $final_array["soil_moisture"] = $row["soil_moisture"];
        }

    }
    else{
        $final_array["soil_moisture"] = "0";
    }

    

    

    if($result3->num_rows > 0){
        while($row = $result3->fetch_assoc()){
            $final_array["water_level"] = $row["water_level"];
        }

    }
    else{
        $final_array["water_level"] = "0";
    }
    if($result4->num_rows > 0){
        while($row = $result4->fetch_assoc()){
            $final_array["soil_relay_status"] = $row["soil_relay_status"];
            $final_array["water_relay_status"] = $row["water_relay_status"];
            $final_array["ph_relay_status"] = $row["ph_relay_status"];
        }

    }
    else{
        $final_array["soil_relay_status"] = "0";
        $final_array["water_relay_status"] = "0";
        $final_array["ph_relay_status"] = "0";
    }

    echo json_encode($final_array);

?>