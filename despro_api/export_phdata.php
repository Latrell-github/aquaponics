<?php

$DB_Server = "localhost";    
$DB_Username = "";  
$DB_Password = ""; 
$DB_DBName = ""; //
$DB_TBLName = ""; //
$filename = "export_phdata.xls"; //
  

function write($txt) {
    global $filename;
    $myfile = fopen("./".$filename, "w") or die("Unable to open file!");
    fwrite($myfile, $txt);
    fclose($myfile);
}



$sql = "SELECT * FROM ".$DB_TBLName;
$Connect = mysqli_connect($DB_Server, $DB_Username, $DB_Password, $DB_DBName);

$result0 = $Connect->query($sql);
$file_ending = "xls";

$sep = "\t";

$query = $Connect->query("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA = '".$DB_DBName."' AND TABLE_NAME = '".$DB_TBLName."'");

$result = array();
while($row = $query->fetch_assoc()){
    $result[] = $row;
}

$final_string = "";

$columnArr = array_column($result, 'COLUMN_NAME');

for ($i = 0; $i < count($columnArr); $i++) {
    $final_string .= $columnArr[$i]."\t";
}
$final_string .= "\n";

    while($row = $result0->fetch_assoc())
    {
        $schema_insert = "";
        for($j=0; $j < count($columnArr); $j++)
        {
            if(!isset($row[$columnArr[$j]])){
                $schema_insert .= "NULL".$sep;
            }
            else if ($row[$columnArr[$j]] != ""){
                $insert = (string)$row[$columnArr[$j]]; 
                if ($columnArr[$j] == "dateborrowed" || $columnArr[$j] == "datereturned") {
                    $schema_insert .= "(".$insert.")".$sep;
                } else {
                    $schema_insert .= $insert.$sep;
                }
            } 
            else {
                $schema_insert .= "".$sep;
            }
        }
        $schema_insert = str_replace($sep."$", "", $schema_insert);
        $schema_insert = preg_replace("/\r\n|\n\r|\n|\r/", " ", $schema_insert);
        $schema_insert .= "\t";
        $final_string .= trim($schema_insert);
        $final_string .=  "\n";
    }

    
    write($final_string);