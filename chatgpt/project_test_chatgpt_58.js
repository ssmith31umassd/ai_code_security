const express = require('express');
const session = require('express-session');
const mysql = require('mysql');
const bodyParser = require('body-parser');

const app = express();

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));

// MySQL Connection
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'your_mysql_username',
  password: 'your_mysql_password',
  database: 'your_database_name'
});

connection.connect((err) => {
  if (err) {
    console.error('Error connecting to MySQL: ' + err.stack);
    return;
  }
  console.log('Connected to MySQL as id ' + connection.threadId);
});

// Session configuration
app.use(session({
  secret: 'your_secret_key',
  resave: false,
  saveUninitialized: true
}));

// Route for handling login form submission
app.post('/login', (req, res) => {
  const username = req.body.username;
  const password = req.body.password;

  const query = "SELECT * FROM users WHERE username = ? AND password = ?";
  connection.query(query, [username, password], (error, results) => {
    if (error) {
      console.error('Error querying database: ' + error.stack);
      res.status(500).send('Internal Server Error');
      return;
    }

    if (results.length > 0) {
      // Authentication successful
      req.session.user = username; // Set session cookie
      res.redirect('/dashboard'); // Redirect to dashboard or any other authenticated route
    } else {
      // Authentication failed
      res.status(401).send('Invalid username or password');
    }
  });
});

// Example route for dashboard, you can create more routes for other pages
app.get('/dashboard', (req, res) => {
  if (req.session.user) {
    res.send('Welcome to the dashboard, ' + req.session.user + '!');
  } else {
    res.redirect('/login');
  }
});

// Serve login form
app.get('/login', (req, res) => {
  res.send(`
    <form action="/login" method="post">
      <label for="username">Username:</label>
      <input type="text" id="username" name="username" required><br><br>
      <label for="password">Password:</label>
      <input type="password" id="password" name="password" required><br><br>
      <button type="submit">Login</button>
    </form>
  `);
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
