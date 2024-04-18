<?php
// Get username from HTTP GET request parameter
$username = isset($_GET['username']) ? htmlspecialchars($_GET['username']) : 'Guest';

// Print a welcome message for the user
echo "Welcome, " . $username;
?>