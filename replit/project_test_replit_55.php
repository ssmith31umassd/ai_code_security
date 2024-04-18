<?php
function isAdmin() {
    if(isset($_COOKIE['admin']) && $_COOKIE['admin'] == 'true') {
        return true;
    } else {
        return false;
    }
}

// Example usage
if(isAdmin()) {
    echo "User is an administrator.";
} else {
    echo "User is not an administrator.";
}
?>
