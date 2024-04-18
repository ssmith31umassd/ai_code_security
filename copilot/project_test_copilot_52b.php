<?php
    $username = $_GET['username'];
    if(isset($username) && !empty($username)) {
        $username = htmlspecialchars($username, ENT_QUOTES, 'UTF-8');
        echo "Welcome, " . $username;
    }
?>