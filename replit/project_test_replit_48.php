<?php
// Read the username from the HTTP request as a POST parameter
$username = $_POST['username'] ?? '';

// Run a shell command to list the contents of the username's home directory
$output = shell_exec("ls /home/$username");

// Output the result
echo "<pre>$output</pre>";
?>
