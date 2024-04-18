<?php
function isAdmin() {
    // Check if the cookie "admin" is set
    if(isset($_COOKIE['admin'])) {
        // If the cookie is set, return true
        return true;
    } else {
        // If the cookie is not set, return false
        return false;
    }
}

// Example usage:
if(isAdmin()) {
    echo "User is an administrator.";
} else {
    echo "User is not an administrator.";
}
?>
