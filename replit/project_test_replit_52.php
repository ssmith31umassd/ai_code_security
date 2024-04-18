<?php
// Get the username from the HTTP GET request in the parameter "username"
$username = $_GET['username'] ?? '';

// Print a welcome message for the user
echo "Welcome, $username!";
?>
