const assert = require('assert');
const tasks = require('tasks');

describe('TasksList', function () {
  describe('#add()', function () {

    it('should return have length of 0 when nothing is added', function () {
      assert.strictEqual((new tasks.TasksList()).length, 0);
    });

    it('should throw if called with no arguments', function () {
      let tasksList = new tasks.TasksList();
      assert.throws(() =>tasksList.add(), TypeError);
    });

    it('should throw if called with a string value', function () {
      let tasksList = new tasks.TasksList();
      assert.throws(() =>tasksList.add("string value"), TypeError);
    });

    it('should throw if called with an object which is not an instance of Task', function () {
      let tasksList = new tasks.TasksList();
      assert.throws(() =>tasksList.add({ title: "Title", details: "Details", isCompleted: true }), TypeError);
    });
    
    it('should have 3 tasks when 3 tasks are added', function () {
      let tasksList = new tasks.TasksList();
      tasksList.add(new tasks.Task("Title", "Details", true));
      tasksList.add(new tasks.Task("Title", "Details", true));
      tasksList.add(new tasks.Task("Title", "Details", true));
      assert.strictEqual(tasksList.length, 3);
    });

  });

  describe('#swap()', function () {
    it('should throw error when called with 3 arguments', function () {
      let tasksList = new tasks.TasksList();
      tasksList.add(new tasks.Task("Title", "Details", true));
      tasksList.add(new tasks.Task("Title", "Details", true));
      tasksList.add(new tasks.Task("Title", "Details", true));
      assert.throws(() => tasksList.swap(1, 2, 3), TypeError);
    });

    it('should throw error when indices are out of range', function () {
      let tasksList = new tasks.TasksList();
      tasksList.add(new tasks.Task("Title", "Details", true));
      tasksList.add(new tasks.Task("Title", "Details", true));
      tasksList.add(new tasks.Task("Title", "Details", true));
      assert.throws(() => tasksList.swap(2, 3), TypeError);
    });

    it('should swap successfully', function () {
      let tasksList = new tasks.TasksList();
      tasksList.add(new tasks.Task("Title0", "Details0", true));
      tasksList.add(new tasks.Task("Title1", "Details1", true));
      tasksList.add(new tasks.Task("Title2", "Details2", true));
      tasksList.swap(0, 2);
      assert.strictEqual(tasksList.at(0).title, "Title2");
      assert.strictEqual(tasksList.at(2).title, "Title0");
    });
  });
});

describe('Task', function () {
  describe('#Native setters', function () {

    it('should change the title of a task successfully', function () {
      let task = new tasks.Task("Title", "Details", true);
      assert.strictEqual(task.title, "Title");
      task.title = "Changed Title";
      assert.strictEqual(task.title, "Changed Title");
    });

    it('should change the details of a task successfully', function () {
      let task = new tasks.Task("Title", "Details", true);
      assert.strictEqual(task.details, "Details");
      task.details = "Changed Details";
      assert.strictEqual(task.details, "Changed Details");
    });

    it('should change the completion of a task successfully', function () {
      let task = new tasks.Task("Title", "Details", true);
      assert.strictEqual(task.isCompleted, true);
      task.isCompleted = false;
      assert.strictEqual(task.isCompleted, false);
    });
  });
});