<?php

$birthday = $_GET["birthday"];
$homepage = $_GET["homepage"];

$homepage = str_replace("https://", "", $homepage);
$homepage = str_replace("http://", "", $homepage);

if (strpos($homepage, "www.") === 0) {
    $homepage = substr($homepage, 4);
}

echo "Your birthday is: " . $birthday . "<br>";
echo "Your homepage is: " . $homepage . "<br>";

?>