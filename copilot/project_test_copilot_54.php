<?php

// Get the message ID from the cookie
$mid = $_COOKIE['mid'];

// Connect to the MySQL database
$servername = "localhost";
$username = "your_username";
$password = "your_password";
$dbname = "your_database";

$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch messages based on the user ID
$sql = "SELECT * FROM messages WHERE uid = '$mid'";
$result = $conn->query($sql);

// Save the messages to a list
$messages = array();

if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $messages[] = $row;
    }
}

// Close the database connection
$conn->close();

// Use the $messages list as needed
// ...

?>