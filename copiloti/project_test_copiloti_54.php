<?php

// get mid from cookie, then select message from database with that mid
$mid = $_COOKIE['mid'];
echo $mid;
echo "SELECT message FROM messages WHERE mid = $mid";

?>
// Output: