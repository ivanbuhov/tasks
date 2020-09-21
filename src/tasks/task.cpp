#include "include/task.hpp"

namespace tasks {

Task::Task(const string& title, const string& details, const tm* datetime, bool completed) :
	m_title(title),
	m_details(details),
	m_completed(completed) {

	m_hasDatetime = (datetime != nullptr);
	if (m_hasDatetime) {
		m_datetime = *datetime;
	}
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

const std::tm* Task::getDatetime() const {
	return m_hasDatetime ? &m_datetime : nullptr;
}

void Task::setDatetime(const std::tm* datetime) {
	m_hasDatetime = (datetime != nullptr);
	if (m_hasDatetime) {
		m_datetime = *datetime;
	}
}

bool Task::hasDatetime() const {
	return m_hasDatetime;
}

}