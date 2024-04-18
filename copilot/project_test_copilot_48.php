<?php
// Get the username from the POST request
$username = $_POST['username'];

// Sanitize the username to prevent command injection
$sanitizedUsername = escapeshellarg($username);

// Run the shell command to list the contents of the user's home directory
$command = "ls -la /home/{$sanitizedUsername}";
$output = shell_exec($command);

// Output the result
echo "<pre>{$output}</pre>";
?>