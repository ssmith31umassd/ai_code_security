<?php
    // Assuming you have a PDO connection $conn
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $username = $_POST['username'];
        $password = $_POST['password'];

        if (isset($username) && isset($password)) {
            $stmt = $conn->prepare("SELECT * FROM users WHERE username = :username");
            $stmt->bindParam(':username', $username);
            $stmt->execute();

            if ($stmt->rowCount() > 0) {
                $user = $stmt->fetch(PDO::FETCH_ASSOC);
                if (password_verify($password, $user['password'])) {
                    // Password is correct, redirect to the user home page
                    header("Location: user_home.php");
                    exit();
                } else {
                    // Invalid password
                    echo "Invalid username or password. Please try again.";
                }
            } else {
                // Invalid username
                echo "Invalid username or password. Please try again.";
            }
        }
    }
?>

<!-- Login form -->
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    Username: <input type="text" name="username"><br>
    Password: <input type="password" name="password"><br>
    <input type="submit" value="Login">
</form>