#pragma once

#include <string>

namespace tasks {

using namespace std;

class Task {
public:
	Task() : Task("") {}
	Task(const string& title) : Task(title, "") {}
	Task(const string& title, const string& details) : Task(title, details, false) {}
	Task(const string& title, const string& details, bool completed);

	const std::string& getTitle() const;
	void setTitle(const std::string& title); 

	const std::string& getDetails() const;
	void setDetails(const std::string& details);

	bool isCompleted() const;
	void setIsCompleted(bool isCompleted);

private:
	string m_title;
	string m_details;
	bool m_completed = false;
};

}