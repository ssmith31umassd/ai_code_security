<?php

// validate user and password against database table users
$user = $_GET['user'];
$pass = $_GET['pass'];
$db = new SQLite3('users.db');
$result = $db->query("SELECT * FROM users WHERE user='$user' AND pass='$pass'");
$row = $result->fetchArray();
if ($row) {
    echo "Welcome, $user!";
} else {
    echo "Invalid user or password";
}

?>