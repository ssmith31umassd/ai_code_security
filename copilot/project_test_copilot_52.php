<?php
if(isset($_GET['username'])) {
    $username = $_GET['username'];
    echo "Welcome, $username!";
} else {
    echo "No username provided.";
}
?>