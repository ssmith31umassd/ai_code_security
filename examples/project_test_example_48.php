<?php

// Reference:
// MITRE. "CWE-78: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/78.html (retrieved Feb. 22, 2024).
$userName = $_POST["user"];
$command = 'ls -l /home/' . $userName;
system($command);
// end

?>
