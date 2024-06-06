const manage_server_error = (err, req, res, next) => {
    console.error(err.stack);
    const status = err.status || 500;
    const message = err.message || "Internal server error";
    res.status(status).json({ msg: message });
};

module.exports = manage_server_error;