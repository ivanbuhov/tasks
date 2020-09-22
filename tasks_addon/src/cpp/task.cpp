#include "include/task.hpp"

namespace tasks {

Task::Task(const string& title, const string& details, bool completed) :
	m_title(title),
	m_details(details),
	m_completed(completed) {
}

const std::string& Task::getTitle() const {
	return m_title;
}

void Task::setTitle(const std::string& title) {
	m_title = title;
}

const std::string& Task::getDetails() const {
	return m_details;
}

void Task::setDetails(const std::string& details) {
	m_details = details;
}

bool Task::isCompleted() const {
	return m_completed;
}

void Task::setIsCompleted(bool isCompleted) {
	m_completed = isCompleted;
}
}