// Reference:
// MITRE. "CWE-89: Improper Neutralization of Special Elements used in an SQL Command ('SQL Injection')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/89.html (retrieved Feb. 22, 2024).        

const express = require('express');
const app = express();

const mysql = require('mysql');
const conn = connect_to_mysql(mysql);

app.post('/login', (req, res) => {
    let login = req.params['login'];
    let password = req.params['password'];

    con.query("SELECT * FROM users WHERE login='" + login + "'", function (err, result) {
        if (err) throw err;
        console.log("Result: " + result);
    });
});
