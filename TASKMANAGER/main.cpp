#include<assert.h>
#include "Window.h"
#include "View.h"
#include "Controller.h"
#include "Exception.h"


void tests()
{
	Repository repo{};
	Controller cont{ repo };
	cont.addTaskCtrl("design interface", "open", 0);
	cont.addTaskCtrl("read from file", "open", 0);
	cont.addTaskCtrl("implement tests", "open", 0);
	cont.addTaskCtrl("finish project", "open", 0);
	assert(cont.getRepo().getTasks().size() == 4);
	cont.addTaskCtrl("playing", "", 0);
	assert(cont.getRepo().getTasks().size() == 5);
	cont.removeTaskCtrl("read from file", "open", 0);
	cont.removeTaskCtrl("design interface", "open", 0);
	Programmer p{ "Paul",1 };
	assert(cont.getRepo().getTasks().size() == 3);
	cont.updateTaskCtrl("playing", p);
	assert(cont.getRepo().getTasks()[2].getStatus() == "in progress");
	assert(cont.getRepo().getTasks()[2].getId() == p.getId());
	bool ok = false;
	try {
		cont.updateTaskCtrl("playing", p);
	}
	catch (Exception& e) {
		ok = true;
	}
	assert(ok == true);
}

int main(int argc, char *argv[])
{
	Repository repo{ "C:/Users/catad/source/repos/TASKMANAGER/programmers.txt", "C:/Users/catad/source/repos/TASKMANAGER/tasks.txt" };
	Controller ctrl{ repo };
	QApplication a(argc, argv);
	TableModel* model = new TableModel(*new Repository((*new std::vector<Task>(ctrl.getRepo().getTasks())), "C:/Users/catad/source/repos/TASKMANAGER/programmers.txt", "C:/Users/catad/source/repos/TASKMANAGER/tasks.txt"));
	//tests();
	std::vector<TableView*> views;
	for (int i = 0; i<ctrl.getRepo().getProgrammers().size(); i++)
	{
		TableView* view = new TableView{ ctrl, ctrl.getRepo().getProgrammers()[i], model};
		views.push_back(view);
		views[i]->show();
	}
	
	//QApplication a(argc, argv);
	/*
	std::vector<Window*> windows;
	for (int i = 0; i<ctrl.getRepo().getProgrammers().size();i++)
	{
		Window* window = new Window{ ctrl, ctrl.getRepo().getProgrammers()[i] };
		windows.push_back(window);
		windows[i]->show();
	}
	*/
	return a.exec();
}
