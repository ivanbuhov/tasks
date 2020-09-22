const inquirer = require('inquirer');
const tasks = require('tasks');

function showMainScreen(todoList) {
    let name = 'Main';
    inquirer.prompt([{
        type: 'list',
        loop: false,
        name: name,
        message: "Select an action:",
        choices: ["List Tasks", "Add New Task", "Save And Exit (./todo.json)", "Exit Without Saving"],
    }])
    .then((answers) => {
        let answer = answers[name];
        if (answer == "List Tasks") {
            showListTasksScreen(todoList);
        } else if (answer == "Add New Task") {
            showAddMewTaskScreen(todoList);
        } else if (answer == "Save And Exit (./todo.json)") {
            todoList.saveTo("./todo.json");
        }
    });
};

function showListTasksScreen(todoList) {
    let name = 'ListTask';
    inquirer.prompt([{
        type: 'list',
        loop: false,
        name: name,
        message: todoList.length == 0 ? "The todo list is empty. Select Back to return to the previous menu and add a new task." : "List of all tasks:",
        choices: () => { 
            let choices = todoList.toArray().map(function (task, index) { return { name: task.toString(), value: index }; });
            choices.unshift({ name: "Back", value: "__back__" });
            return choices;
        }
    }])
    .then((answers) => {
        let answer = answers[name];
        if (answer == "__back__") {
            showMainScreen(todoList);
        } else {
            showEditTaskScreen(todoList, answer);
        }
    });
};

function showAddMewTaskScreen(todoList) {
    let nameTitle = 'AddNewTaskTitle';
    let nameDetails = 'AddNewTaskDetails';
    let nameCompletion = 'AddNewTaskCompletion';

    inquirer.prompt([{
        type: 'input',
        loop: false,
        name: nameTitle,
        message: "Enter a task title:",
    }, {
        type: 'input',
        loop: false,
        name: nameDetails,
        message: "Enter a task details:",
    }, {
        type: 'input',
        loop: false,
        name: nameCompletion,
        message: "Completed (y/n)?",
        validate: (answer) => {
            return (answer == "y" || answer == "n") ? true : "The only possible values are y and n.";
        }
    }])
    .then((answers) => {
        todoList.add(new tasks.Task(answers[nameTitle], answers[nameDetails], (answers[nameCompletion] == "y")));
        showListTasksScreen(todoList);
    });
};

function showEditTaskScreen(todoList, taskIndex) {
    let name = 'EditTask';
    let task = todoList.at(taskIndex);

    inquirer.prompt([{
        type: 'list',
        loop: false,
        name: name,
        message: task.title + "\n" + task.details + "\nCmpleted: " + (task.isCompleted ? "yes" : "no") + "\n",
        choices: ["Back", "Edit Title", "Edit Details", { name: (task.isCompleted ? "Mark as not completed" : "Mark as completed"), value: "toggle" }]
    }])
    .then((answers) => {
        let answer = answers[name];
        if (answer == "Back") {
            showListTasksScreen(todoList);
        } else if (answer == "Edit Title") {
            showEditTitleScreen(todoList, taskIndex);
        } else if (answer == "Edit Details") {
            showEditDetailsScreen(todoList, taskIndex);
        } else if (answer == "toggle") {
            task.isCompleted = !task.isCompleted;
            showListTasksScreen(todoList);
        }
    });
};

function showEditTitleScreen(todoList, taskIndex) {
    let name = 'EditTitle';
    let task = todoList.at(taskIndex);
    console.log("---->" + taskIndex);
    console.log("---->" + task);

    inquirer.prompt([{
        type: 'input',
        loop: false,
        name: name,
        message: task.title + "\n" + task.details + "\nCmpleted: " + (task.isCompleted ? "yes" : "no") + "\n\n\nEnter a new title:",
    }])
    .then((answers) => {
        task.title = answers[name];
        showEditTaskScreen(todoList, taskIndex);
    });
};

function showEditDetailsScreen(todoList, taskIndex) {
    let name = 'EditDetails';
    let task = todoList.at(taskIndex);

    inquirer.prompt([{
        type: 'input',
        loop: false,
        name: name,
        message: task.title + "\n" + task.details + "\nCmpleted: " + (task.isCompleted ? "yes" : "no") + "\n\n\nEnter a new details:",
    }])
    .then((answers) => {
        task.details = answers[name];
        showEditTaskScreen(todoList, taskIndex);
    });
};

exports.showMainScreen = showMainScreen;
exports.showListTasksScreen = showListTasksScreen;
exports.showAddMewTaskScreen = showAddMewTaskScreen;
exports.showEditTaskScreen = showEditTaskScreen;
exports.showEditTitleScreen = showEditTitleScreen;
exports.showEditDetailsScreen = showEditDetailsScreen;