<?php

// read username from HTTP request, then run a shell command to list contents of user's home directory
$username = $_GET['username'];
echo shell_exec("ls /home/$username");


?>
