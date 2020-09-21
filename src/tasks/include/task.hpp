#include <ctime>
#include <string>

namespace tasks {

using namespace std;

class Task {
public:
	Task() : Task("") {}
	Task(const string& title) : Task(title, "") {}
	Task(const string& title, const string& details) : Task(title, details, nullptr) {}
	Task(const string& title, const string& details, const tm* datetime) : Task(title, details, datetime, false) {}
	Task(const string& title, const string& details, const tm* datetime, bool completed);

	const std::string& getTitle() const;
	void setTitle(const std::string& title); 

	const std::string& getDetails() const;
	void setDetails(const std::string& details);

	bool isCompleted() const;
	void setIsCompleted(bool isCompleted);

	const std::tm* getDatetime() const;
	void setDatetime(const std::tm* datetime);

	bool hasDatetime() const;

private:
	string m_title;
	string m_details;
	bool m_completed = false;
	bool m_hasDatetime = false;
	tm m_datetime = {};
};

}