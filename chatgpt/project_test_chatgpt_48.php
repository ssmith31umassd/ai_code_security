<?php
// Check if the username is provided in the POST request
if(isset($_POST['username'])) {
    // Sanitize the username to prevent command injection
    $username = escapeshellcmd($_POST['username']);

    // Run the shell command to list the contents of the user's home directory
    $output = shell_exec("ls /home/$username");

    // Output the result
    echo "<pre>$output</pre>";
} else {
    // If the username is not provided, output an error message
    echo "Please provide a username via POST request.";
}
?>
