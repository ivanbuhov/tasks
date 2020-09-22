# tasks
This is native node addon (written in C++ and exposed to JavaScript) for simple todo tasks management.
* Developed and tested only on Windows. No other targets are supported
* The integration between the native code and the JS engine is implemented entirely through the N-API, so no precompilation is required on new Node versions.

# Requirements
* Windows
* Visual Studio Build Tools
* Node.js

# How to build

```
git clone https://github.com/ivanbuhov/tasks.git
cd tasks_addon
npm install
npm run build
```
This will build the native addon. The artefact can be found in `tasks_addon/build/Release/tasks_addon.node`. Now the node module in `/tasks_addon` can be referenced directly as a node module dependency.

# Building and running the tests

The TestsApp project directly references the addon as a node dependency, so no additional step is required.
```
cd tests/TestsApp
npm install
npm test
```

# Building and running the example TasksApp

The TasksApp project directly references the addon as a node dependency, so no additional step is required.
```
cd examples/TasksApp
npm install
node .
```
The TasksApp is a simple console Node application, for storing and editing a list of tasks. The list can be seriilized in a file and deserialized from the same file on app startup.
