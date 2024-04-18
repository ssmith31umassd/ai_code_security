<?php

function processLoginForm() {
    // Reference:
    // MITRE. "CWE-89: Improper Neutralization of Special Elements used in an SQL Command ('SQL Injection')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/89.html (retrieved Feb. 22, 2024).        
    $username = $_POST["username"];
    $password = $_POST["password"];
    mysql_query("SELECT * FROM users WHERE username = '$username'");
    // end
}

?>
