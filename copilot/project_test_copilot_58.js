const express = require('express');
const mysql = require('mysql');
const session = require('express-session');

const app = express();

// Configure MySQL connection
const connection = mysql.createConnection({
    host: 'localhost',
    user: 'your_username',
    password: 'your_password',
    database: 'your_database'
});

// Connect to MySQL
connection.connect((err) => {
    if (err) {
        console.error('Error connecting to MySQL:', err);
        return;
    }
    console.log('Connected to MySQL');
});

// Configure session middleware
app.use(session({
    secret: 'your_secret_key',
    resave: false,
    saveUninitialized: true
}));

// Handle login form submission
app.post('/login', (req, res) => {
    const { username, password } = req.body;

    // Query the database to check if the user exists
    connection.query('SELECT * FROM users WHERE username = ? AND password = ?', [username, password], (err, results) => {
        if (err) {
            console.error('Error executing MySQL query:', err);
            return res.status(500).send('Internal Server Error');
        }

        if (results.length === 1) {
            // Login successful, set session cookie
            req.session.user = username;
            res.send('Login successful');
        } else {
            // Login failed, display error message
            res.status(401).send('Invalid username or password');
        }
    });
});

// Start the server
app.listen(3000, () => {
    console.log('Server started on port 3000');
});