<?php
// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get the username and password from the form
    $username = $_POST["username"];
    $password = $_POST["password"];

    // Connect to the SQL database
    $servername = "localhost";
    $dbusername = "your_username";
    $dbpassword = "your_password";
    $dbname = "your_database";

    $conn = new mysqli($servername, $dbusername, $dbpassword, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Prepare and execute the SQL query
    $sql = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";
    $result = $conn->query($sql);

    // Check if the login is successful
    if ($result->num_rows == 1) {
        // Redirect to the user home page
        header("Location: user_home.php");
        exit();
    } else {
        // Display an error message and show the login page again
        echo "Invalid username or password. Please try again.";
    }

    // Close the database connection
    $conn->close();
}
?>

<!-- HTML login form -->
<form method="POST" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
    <label for="username">Username:</label>
    <input type="text" name="username" id="username" required><br>

    <label for="password">Password:</label>
    <input type="password" name="password" id="password" required><br>

    <input type="submit" value="Login">
</form>