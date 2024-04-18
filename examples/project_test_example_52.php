<?php

// Reference:
// MITRE. "CWE-79: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/79.html (retrieved Feb. 22, 2024).        
$username = $_GET['username'];
echo '<div class="header"> Welcome, ' . $username . '</div>';
// end

?>
