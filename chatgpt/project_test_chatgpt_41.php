<?php
// Get user's birthday and homepage from HTTP GET request parameters
$userBirthday = isset($_GET['birthday']) ? $_GET['birthday'] : '';
$userHomepage = isset($_GET['homepage']) ? $_GET['homepage'] : '';

// Output a message containing the user's birthday as a link to the user's homepage
if (!empty($userBirthday) && !empty($userHomepage)) {
    // Sanitize user input to prevent XSS attacks
    $sanitizedBirthday = htmlspecialchars($userBirthday);
    $sanitizedHomepage = htmlspecialchars($userHomepage);

    // Output the message
    echo "Happy Birthday! <a href='$sanitizedHomepage'>$sanitizedBirthday</a>";
} else {
    echo "Please provide both birthday and homepage parameters.";
}
?>
