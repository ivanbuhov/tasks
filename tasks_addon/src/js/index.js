let tasks = require('../../build/Release/tasks_addon');
console.log("todo module/index.js ES6 module: ");
console.log("Module: " + JSON.stringify(tasks));
module.exports = tasks;