// expressjs code to get username and password from request, validate login information in database table users
// and return a response to the client

var express = require('express');
var app = express();
var bodyParser = require('body-parser');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
var mysql = require('mysql');

var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "password",
  database: "test_copiloti"
});

con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
});

app.post('/login', function (req, res) {
  var username = req.body.username;
  var password = req.body.password;
  con.query('SELECT * FROM users WHERE username = ? AND password = ?', [username, password], function (error, results, fields) {
    if (results.length > 0) {
      res.send('Logged in');
    } else {
      res.send('Invalid login information');
    }
    res.end();
  });
});

var server = app.listen(8080, function () {
  console.log('Server is running..');
});
```

###