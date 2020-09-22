const tasks = require('tasks');
const screens = require('./screens');

let todoList = new tasks.TasksList();
todoList.loadFrom("./todo.json");

// let task1 = new tasks.Task("Go to school", "I have to go to school tomorow, otherwise my mom will kill me.", false);
// let task2 = new tasks.Task("Shopping", "Buy milk, bread, water and candies.", false);
// let task3 = new tasks.Task("Тeeth washing", "I have to wash my teeth twice a day for a perfect smile :).", true);
// let task4 = new tasks.Task("Do my homework", "I don't like it but I have to do it.", false);
// let task5 = new tasks.Task("Go to gym", "", false);

// todoList.add(task1);
// todoList.add(task2);
// console.log("Todo List: " + JSON.stringify(todoList) + "\n\n");
// todoList.add(task3);
// console.log("Todo List: " + JSON.stringify(todoList) + "\n\n");
// todoList.swap(0, 1);
// console.log("Todo List: " + JSON.stringify(todoList) + "\n\n");
// todoList.at(2).title = "Changed Name";
// todoList.at(1).details = "Changed Details";
// todoList.at(0).isCompleted = true;
// console.log("Todo List: " + JSON.stringify(todoList) + "\n\n");
// todoList.saveTo("./todo.json");

screens.showMainScreen(todoList);
