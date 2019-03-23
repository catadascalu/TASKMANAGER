#pragma once
#include "Repository.h"
#include "Observer.h"

class Controller :public Observable
{
private:
	Repository repo;
public:
	Controller(Repository& r) : repo(r) {}
	~Controller() {}

	Repository& getRepo() { return this->repo; }

	void addTaskCtrl(string des, string s, int id);
	void removeTaskCtrl(string des, string s, int id);

	void updateTaskCtrl(string des, Programmer& p);
	
	vector<Task> sortTasks();

	std::string getProgrammerById(int id);

	void endTaskCtrl(string des, string s, int id);

};