<?php

function checkCookieForAdminFlag() {
    // Reference:
    // MITRE. "CWE-287: Improper Authentication." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/287.html (retrieved Feb. 22, 2024).        
    $admin = $_COOKIE["isAdmin"];
    return $admin;
    // end
}

?>
