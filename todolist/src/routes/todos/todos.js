const express = require('express');
require('dotenv').config();
const mysql = require('mysql2');
const jwt = require('jsonwebtoken');
const my_app = express();
my_app.use(express.json());

const my_pool = mysql.createConnection({
  host: process.env.MYSQL_HOST,
  user: process.env.MYSQL_USER,
  password: process.env.MYSQL_ROOT_PASSWORD,
  database: process.env.MYSQL_DATABASE
});

my_pool.connect((err) => {
  if (err) throw err;
  console.log('Connected to the database');
});

const mw = require('../../middleware/auth');

my_app.get('/todos', mw, async (req, res, next) => {
  const userId = req.user.userId;
  my_pool.query('SELECT * FROM todo WHERE user_id = ?', [userId], (err, all_todos) => {
    if (err) return next(err);
    if (all_todos.length === 0) return res.status(404).json({msg: "Not found"});
    res.status(200).json(all_todos);
  });
});

my_app.get('/todos/:id', mw, async (req, res, next) => {
  const todoId = req.params.id;
  const userId = req.user.userId;
  my_pool.query('SELECT * FROM todo WHERE id = ? AND user_id = ?', [todoId, userId], (err, result) => {
    if (err) return next(err);
    if (result.length === 0) return res.status(404).json({msg: "Not found"});
    res.status(200).json(result[0]);
  });
});

my_app.post('/todos', mw, (req, res, next) => {
  const { title, description, due_time, status } = req.body;
  const userId = req.user.userId;
  if (!title || !due_time || !status) return res.status(400).json({ msg: "Bad parameter" });
  my_pool.query(
    'INSERT INTO todo (title, description, due_time, user_id, status) VALUES (?, ?, ?, ?, ?)',
    [title, description, due_time, userId, status], (err, result) => {
      if (err) return next(err);
      my_pool.query('SELECT * FROM todo WHERE id = ?', [result.insertId], (err, new_todo) => {
        if (err) return next(err);
        res.status(201).json(new_todo[0]);
      });
    });
  });

my_app.put('/todos/:id', mw, async (req, res, next) => {
  const todoId = req.params.id;
  const {title, description, due_time, status} = req.body;
  const userId = req.user.userId;
  if (!title || !due_time || !status) return res.status(400).json({ msg: "Bad parameter" });
  my_pool.query(
    'UPDATE todo SET title = ?, description = ?, due_time = ?, status = ? WHERE id = ? AND user_id = ?',
    [title, description, due_time, status, todoId, userId], (err, result) => {
      if (err) return next(err);
      if (result.affectedRows === 0) return res.status(404).json({ msg: "Not found" });
      my_pool.query('SELECT * FROM todo WHERE id = ?', [todoId], (err, updated_todo) => {
        if (err) return next(err);
        res.status(200).json(updated_todo[0]);
      });
    }
  );
});

my_app.delete('/todos/:id', mw, async (req, res, next) => {
  const todoId = req.params.id;
  const userId = req.user.userId;
  my_pool.query('DELETE FROM todo WHERE id = ? AND user_id = ?', [todoId, userId], (err, result) => {
      if (err) return next(err);
      if (result.affectedRows === 0) return res.status(404).json({msg: "Not found"});
      res.status(200).json({msg: `Successfully deleted record number: ${todoId}`});
    }
  );
});

module.exports = my_app;
