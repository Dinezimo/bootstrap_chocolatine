const express = require('express');
require('dotenv').config();
const mysql = require('mysql2');
const jwt = require('jsonwebtoken');
const my_app = express();
my_app.use(express.json());
const my_bcrypt = require('bcrypt');

const my_pool = mysql.createConnection({
  host: process.env.MYSQL_HOST,
  user: process.env.MYSQL_USER,
  password: process.env.MYSQL_ROOT_PASSWORD,
  database: process.env.MYSQL_DATABASE
});
my_pool.connect((err) => {
    if (err) throw err;
    console.log('connecté aux routes d\' autentification');
  });

  
  my_app.use(express.json());
  
  my_app.post('/register', (req, res, next) => {
      const {email, name, firstname, password} = req.body;
      if (!email || !name || !firstname || !password)
          return res.status(400).json({msg: "Bad parameter"});
      my_pool.query('SELECT * FROM user WHERE email = ?', [email], (err, all_mail) => {
          if (err) return next(err);
          if (all_mail.length > 0)
              return res.status(400).json({msg: "Account already exists"});
          my_bcrypt.hash(password, 10, (err, hashedPassword) => {
            if (err) return next(err);
            my_pool.query('INSERT INTO user (email, name, firstname, password) VALUES (?, ?, ?, ?)', 
            [email, name, firstname, hashedPassword], (err, result) => {
                if (err) return next(err);
                const my_token = jwt.sign({ userId: result.insertId }, process.env.SECRET, { expiresIn: '1h' });
                res.status(201).json({token: my_token});
                console.log("le server ajoute un compte");
              });
          });
      });
  });
  
  my_app.post('/login', (req, res, next) => {
      const {email, password} = req.body;
      if (!email || !password)
          return res.status(400).json({msg: "Bad parameter"});
      my_pool.query('SELECT * FROM user WHERE email = ?', [email], (err, users) => {
          if (err) return next(err);
          if (users.length === 0)
              return res.status(401).json({msg: "Invalid credentials" });
          const user = users[0];
          my_bcrypt.compare(password, user.password, (err, isMatch) => {
              if (err) return next(err);
              if (!isMatch)
                  return res.status(401).json({msg: "Invalid credentials"});
              const my_token = jwt.sign({userId: user.id}, process.env.SECRET, {expiresIn: '72h'});
              res.status(200).json({token: my_token});
          });
      });
  });
  
  module.exports = my_app;
  