#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Programmer.h"
#include "Task.h"
#include "Exception.h"

using namespace std;



class Repository
{
private:
	std::vector<Task> tasks;
	std::vector<Programmer> programmers;
	std::string progFile;
	std::string taskFile;
public:
	Repository() {}
	Repository(std::vector<Task> t, string f1, string f2) : progFile(f1), taskFile(f2), tasks(t) {}
	Repository(string f1, string f2) : progFile(f1), taskFile(f2) { readTasks(); readProgrammers(); }
	~Repository() {}

	std::vector<Task> getTasks() { return this->tasks; }
	Programmer& getProgrammer(int id)
	{
		for (auto p : this->programmers)
			if (p.getId() == id)
				return p;
	}

	std::string getProgrammerById(int id)
	{
		for (auto p : this->programmers)
			if (p.getId() == id)
				return p.getName();

		return "";
	

	}
	int getTask(Task& t)
	{
		for (int i = 0; i < this->tasks.size(); i++)
		{
			if (this->tasks.at(i).getDescription() == t.getDescription())
				return i;
		}
	}
	std::vector<Programmer> getProgrammers() { return this->programmers; }
	void readTasks()
	{
		ifstream file(taskFile);
		if (file.is_open())
		{
			Task t;
			while (file >> t)
				this->addTask(t);

			file.close();
		}
	}
	void readProgrammers()
	{
		ifstream file(progFile);
		if (file.is_open())
		{
			Programmer p;
			while (file >> p)
				this->addProgrammer(p);

			file.close();
		}
	}
	void addTask(Task& t)
	{

		this->tasks.push_back(t);
		tryWrite();
	}

	void removeTask(Task& t)
	{
		auto it = find_if(tasks.begin(), tasks.end(), [t](Task ta) { return (t.getDescription() == ta.getDescription() && t.getStatus() == ta.getStatus() && t.getId() == ta.getId()); });
		if (it == tasks.end())
			return;
		tasks.erase(it);
		tryWrite();
		//this->tasks.erase(std::remove(tasks.begin(), tasks.end(), t));
		//tryWrite();
	}

	void updateTask(std::string des, Programmer& p)
	{
		for(int i=0;i<tasks.size();i++)
			if (tasks[i].getDescription() == des)
			{
				if (tasks[i].getStatus() != "open")
					throw Exception("Task is not open!");
				tasks[i].setStatus("in progress");
				tasks[i].setId(p.getId());
				break;
			}
		tryWrite();
	}

	void endTask(Task& t)
	{
		for (int i = 0; i < tasks.size(); i++) {
			if (tasks[i].getDescription() == t.getDescription() && tasks[i].getStatus() == t.getStatus() && tasks[i].getId() == t.getId()) {
				tasks[i].setStatus("closed");
				break;
			}
		}
		tryWrite();
	}

	void addProgrammer(Programmer p)
	{
		this->programmers.push_back(p);
	}
	void tryWrite()
	{
		if (taskFile != "")
			writeToFile();
	}

	void writeToFile()
	{
		ofstream file(taskFile);
		if (file.is_open())
		{
			for (auto t : this->tasks)
				file << t;

			file.close();
		}
	}
};