#include <napi.h>

#include "include/task_wrapper.hpp"
#include "include/tasks_list_wrapper.hpp"

namespace tasks_addon {

Napi::Object init(Napi::Env env, Napi::Object exports) {
	exports.Set("Task", TaskWrapper::buildConstructor(env));
	exports.Set("TasksList", TasksListWrapper::buildConstructor(env));
	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init)
}
