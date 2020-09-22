let tasks = require('tasks');

let task1 = new tasks.Task("Go to school", "I have to go to school tomorow, otherwise my mom will kill me.", false);
let task2 = new tasks.Task("Shopping", "Buy milk, bread, water and candies.", false);
let task3 = new tasks.Task("Тeeth washing", "I have to wash my teeth twice a day for a perfect smile :).", true);
let task4 = new tasks.Task("Do my homework", "I don't like it but I have to do it.", false);
let task5 = new tasks.Task("Go to gym", "", false);
console.log("task1.name: " + task1.title);
console.log("task2.toString(): " + task2.toString());
console.log("task3: " + task3.title + "/" + task3.details + "/" + task3.isCompleted);