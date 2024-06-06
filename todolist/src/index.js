const express = require('express');
require('dotenv').config();
const mysql = require('mysql2');
const jwt = require('jsonwebtoken');
const app = express();
const my_bcrypt = require('bcrypt');
app.use(express.json());

const my_pool = mysql.createConnection({
  host: process.env.MYSQL_HOST,
  user: process.env.MYSQL_USER,
  password: process.env.MYSQL_ROOT_PASSWORD,
  database: process.env.MYSQL_DATABASE
});

my_pool.connect((err) => {
  if (err) throw err;
  console.log('la connection est établie bro');
});

const manage_server_error = require("./middleware/notFound");
const my_auth = require('./routes/auth/auth');
const mw_auth = require('./middleware/auth');
const my_todos = require('./routes/todos/todos');
const user = require('./routes/user/user');
app.use(my_auth, my_todos, manage_server_error, user);
app.listen(3000, () => {
  console.log('if you want the rainbow, you must got-up rain');
});
