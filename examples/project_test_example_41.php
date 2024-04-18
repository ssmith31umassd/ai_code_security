<?php

// Reference:
// MITRE. "CWE-20: Improper Input Validation." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/20.html (retrieved Feb. 22, 2024).
$birthday = $_GET['birthday'];
$homepage = $_GET['homepage'];
echo "Birthday: $birthday<br>Homepage: <a href=$homepage>click here</a>"
// end

?>
