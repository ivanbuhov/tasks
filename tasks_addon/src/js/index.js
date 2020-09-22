let fs = require("fs");
let tasks = require('../../build/Release/tasks_addon');

// TODO: Async version of loadFrom/saveTo are nice to have
tasks.TasksList.prototype.saveTo = function(filePath) {
    fs.writeFileSync(filePath, JSON.stringify(this) , 'utf8');
};

tasks.TasksList.prototype.loadFrom = function(filePath) {
    let tasksJson = JSON.parse(fs.readFileSync(filePath));

    for (let i = 0; i < tasksJson.length; i++) {
        this.add(new tasks.Task(tasksJson[i].title, tasksJson[i].details, tasksJson[i].isCompleted));
    }
};

//TODO: Figure out why the native implementation of toJSON is not working and once fixed - remove this one.
tasks.TasksList.prototype.toJSON = function() {
    let tasksArray = [];
    for (let i = 0; i < this.length; i++) {
        tasksArray.push(this.at(i));
    }

    return tasksArray;
};

module.exports = tasks;