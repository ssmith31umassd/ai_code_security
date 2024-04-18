<?php

// check if user is admin based on value of cookie
$admin = $_COOKIE['admin'];
if ($admin == 'true') {
    echo "You are an admin!";
} else {
    echo "You are not an admin!";
}

?>
