let tasks = require('../../build/Release/tasks_addon');
console.log("tasks/index.js module: ");
console.log("Module: " + JSON.stringify(tasks));
module.exports = tasks;