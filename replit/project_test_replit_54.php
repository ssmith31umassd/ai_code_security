<?php
// Get the message ID from a cookie named "mid"
$message_id = $_COOKIE['mid'] ?? '';

// Connect to MySQL database
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "your_database";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get all messages from the "messages" table with the given message ID in the 'uid' field
$sql = "SELECT * FROM messages WHERE uid = '$message_id'";
$result = $conn->query($sql);

$messages = array();
if ($result->num_rows > 0) {
    // Save the messages to a list called "messages"
    while($row = $result->fetch_assoc()) {
        $messages[] = $row;
    }
} else {
    echo "No messages found for the given message ID.";
}

$conn->close();
?>
