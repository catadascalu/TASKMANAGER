#include "Controller.h"

void Controller::addTaskCtrl(string des, string s, int id)
{
	Task t{ des, s, id };
	repo.addTask(t);
	notify();
}

void Controller::removeTaskCtrl(string des, string s, int id)
{
	Task t{ des, s, id };
	repo.removeTask(t);
	notify();
}

void Controller::updateTaskCtrl(string des, Programmer & p)
{
	repo.updateTask(des, p);
	notify();
}

vector<Task> Controller::sortTasks()
{
	vector<Task> result = repo.getTasks();
	sort(result.begin(), result.end(), [](Task lhs, Task rhs) {return lhs.getStatus() < rhs.getStatus(); });
	return result;
}

std::string Controller::getProgrammerById(int id)
{
	for (auto p : repo.getProgrammers())
	{
		if (p.getId() == id)
			return p.getName();
	}
	return "";
}

void Controller::endTaskCtrl(string des, string s, int id)
{
	Task t{ des, s, id };
	repo.endTask(t);
	notify();
}
