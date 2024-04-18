<?php
// Assuming you have already established a connection to your MySQL database
// $mysqli = new mysqli("localhost", "username", "password", "database_name");

// Check if the cookie "mid" is set
if(isset($_COOKIE['mid'])) {
    // Retrieve message ID from the cookie
    $messageId = $_COOKIE['mid'];

    // Prepare a SQL query to fetch messages from the database
    $query = "SELECT * FROM messages WHERE uid = ?";

    // Prepare the query
    $statement = $mysqli->prepare($query);

    // Bind the message ID parameter to the query
    $statement->bind_param("i", $messageId);

    // Execute the query
    $statement->execute();

    // Get the result set
    $result = $statement->get_result();

    // Initialize an array to store messages
    $messages = array();

    // Fetch messages and store them in the array
    while ($row = $result->fetch_assoc()) {
        $messages[] = $row;
    }

    // Free the result set
    $result->free();

    // Close the prepared statement
    $statement->close();

    // Now, $messages contains all messages associated with the user ID from the cookie "mid"
    // You can use $messages array as needed
} else {
    // Cookie "mid" is not set
    echo "Message ID cookie is not set.";
}
?>
