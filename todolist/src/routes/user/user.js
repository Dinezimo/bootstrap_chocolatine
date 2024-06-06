const express = require('express');
require('dotenv').config();
const mysql = require('mysql2');
const jwt = require('jsonwebtoken');
const my_app = express();
const my_bcrypt = require('bcrypt');
my_app.use(express.json());

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

const mw = require('../../middleware/auth');

my_app.get('/user', mw, async (req, res, next) => {
    const userId = req.user.userId;
    my_pool.query('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [userId], (err, user) => {
    if (err) return next(err);
    if (user.length === 0) return res.status(404).json({msg: "Not found"});
    res.status(200).json(user[0]);
});
});

my_app.get('/user/todos', mw, async(req, res, next) => {
    const userId = req.user.userId;
    my_pool.query('SELECT * FROM todo WHERE user_id = ?', [userId], (err, todos) => {
      if (err) return next(err);
      if (todos.length === 0) return res.status(404).json({msg: "Not found"});
      res.status(200).json(todos);
});
});
  
my_app.get('/users/:id', mw, async(req, res, next) => {
    const userId = req.params.id;
    my_pool.query('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [userId], (err, user) => {
      if (err) return next(err);
      if (user.length === 0) return res.status(404).json({msg: "Not found"});
      res.status(200).json(user[0]);
});
});

my_app.get('/users/email/:email', mw, async(req, res, next) => {
    const usermail = req.params.email;
    my_pool.query('SELECT id, email, password, created_at, firstname, name FROM user WHERE email = ?', [usermail], (err, user) => {
      if (err) return next(err);
      if (user.length === 0) return res.status(404).json({msg: "Not found"});
      res.status(200).json(user[0]);
});
});

my_app.put('/users/:id', mw, async(req, res, next) => {
    const userId = req.params.id;
    const {email, password, firstname, name} = req.body;
    const secured_pass = bcrypt.hash(password, 10);
    my_pool.query('UPDATE user SET email = ?, password = ?, firstname = ?, name = ? WHERE id = ?', [email, secured_pass, firstname, name, userId], (err, modif) => {
        if (err) return next(err);
        if (modif.affectedRows === 0) return res.status(404).json({msg: "Not found"});
        my_pool.query('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [userId], (err, user) => {
          if (err) return next(err);
          res.status(200).json(user[0]);
    });
});
});

my_app.delete('/users/:id', mw, async(req, res, next) => {
    const userId = req.params.id;
    my_pool.query('DELETE FROM user WHERE id = ?', [userId], (err, result) => {
      if (err) return next(err);
      if (result.affectedRows === 0) return res.status(404).json({ msg: "Not found" });
      res.status(200).json({msg: `Successfully deleted record number: ${userId}`});
});
});

module.exports = my_app;
