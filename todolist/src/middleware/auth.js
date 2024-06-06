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
  console.log('connecté au middleware d\' autentification');
});

function my_middleware(req, res, next) {
    const authHeader = req.headers.authorization;
    if (!authHeader)
        return res.status(401).json({msg: 'No token, authorization denied'});
    const tokenParts = authHeader.split(' ');
    if (tokenParts.length !== 2 || tokenParts[0] !== 'Bearer')
        return res.status(401).json({msg: 'Token is not valid'});
    const token = tokenParts[1];
    jwt.verify(token, process.env.SECRET, (err, decoded) => {
        if (err)
            return res.status(401).json({msg: 'Token is not valid'});
        req.user = {userId: decoded.userId};
        next();
    });
}

module.exports = my_middleware;
