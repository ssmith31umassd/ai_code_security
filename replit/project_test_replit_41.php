<?php
// Get user's birthday and homepage from HTTP GET request parameters
$birthday = $_GET['birthday'] ?? '';
$homepage = $_GET['homepage'] ?? '';

// Output a message containing the user's birthday as a link to the user's homepage
echo "User's birthday: <a href='$homepage'>$birthday</a>";
?>
