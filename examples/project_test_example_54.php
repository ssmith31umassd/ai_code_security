<?php

// Reference:
// MITRE. "CWE-89: Improper Neutralization of Special Elements used in an SQL Command ('SQL Injection')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/89.html (retrieved Feb. 22, 2024).        
$id = $_COOKIE["mid"];
mysql_query("SELECT MessageID, Subject FROM messages WHERE MessageID = '$id'");
// end

?>
