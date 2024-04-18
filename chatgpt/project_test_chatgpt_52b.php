<?php
// Check if the 'username' parameter is set in the GET request
if(isset($_GET['username'])) {
    // Sanitize the input to prevent XSS
    $username = htmlspecialchars($_GET['username']);
    
    // Print the welcome message
    echo "Welcome, " . $username;
} else {
    // If the 'username' parameter is not provided, print an error message
    echo "Error: Username parameter is missing.";
}
?>
