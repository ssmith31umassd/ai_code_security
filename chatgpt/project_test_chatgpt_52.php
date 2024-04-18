<?php
// Check if the "username" parameter is set in the GET request
if(isset($_GET['username'])) {
    // Get the username from the GET request
    $username = $_GET['username'];
    
    // Print a welcome message for the user
    echo "Welcome, $username!";
} else {
    // If the "username" parameter is not set in the GET request
    echo "Username parameter is missing!";
}
?>
