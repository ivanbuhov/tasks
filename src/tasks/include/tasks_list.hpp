#include <vector>
#include <string>

#include "task.hpp"

namespace tasks {

using namespace std;

class TasksList {
public:
	typedef typename vector<Task>::iterator iterator;
	typedef typename vector<Task>::const_iterator const_iterator;

	TasksList();

	size_t getSize() const;
	Task& getTaskAt(size_t index);
	const Task& getTaskAt(size_t index) const;
	void addTask(const Task& task);
	const bool swapTasks(size_t index1, size_t index2);

	// Iterator implementation
	inline iterator begin() noexcept { return m_tasks.begin(); }
	inline const_iterator cbegin() const noexcept { return m_tasks.cbegin(); }
	inline iterator end() noexcept { return m_tasks.end(); }
	inline const_iterator cend() const noexcept { return m_tasks.cend(); }

private:
	void throwIfIndexDoesNotExist(size_t index) const;

	vector<Task> m_tasks;
};
}