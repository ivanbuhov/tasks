#include "include/tasks_list.hpp"

namespace tasks {

TasksList::TasksList() {
}

size_t TasksList::getSize() const {
	return m_tasks.size();
}

Task& TasksList::getTaskAt(size_t index) {
	throwIfIndexDoesNotExist(index);
	return m_tasks.at(index);
}

const Task& TasksList::getTaskAt(size_t index) const {
	throwIfIndexDoesNotExist(index);
	return m_tasks.at(index);
}

void TasksList::addTask(const Task& task) {
	m_tasks.push_back(task);
}

const bool TasksList::swapTasks(size_t index1, size_t index2) {
	throwIfIndexDoesNotExist(index1);
	throwIfIndexDoesNotExist(index2);

	if (index1 == index2) {
		return false;
	}

	Task temp = getTaskAt(index1);
	m_tasks[index1] = m_tasks[index2];
	m_tasks[index2] = m_tasks[index1];
	return true;
}

void TasksList::throwIfIndexDoesNotExist(size_t index) const {
	if (index >= getSize()) {
		string message = string("Invalid task index ") + to_string(index);
		throw exception(message.c_str());
	}
}

}