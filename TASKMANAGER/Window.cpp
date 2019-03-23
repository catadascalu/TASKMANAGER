#include "Window.h"

Window::Window(Controller& c, Programmer p, QWidget* parent) : ctrl(c), programmer(p), QWidget(parent)
{
	ui.setupUi(this);

	this->ctrl.addObserver(this);

	this->setWindowTitle(QString::fromStdString(p.getName()));
	this->currentTasks = this->ctrl.sortTasks();
	this->populateRepo();

	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(add()));
	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(remove()));
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(start()));
	connect(ui.endButton, SIGNAL(clicked()), this, SLOT(done()));
}


void Window::update()
{
	this->populateRepo();
}

void Window::populateRepo()
{
	int index = 0;
	//ui.taskTable->setRowCount(this->currentTasks.size());
	ui.taskTable->clear();
	this->currentTasks = this->ctrl.sortTasks();
	ui.taskTable->setRowCount(this->currentTasks.size());
	for (auto t : this->currentTasks)
	{
		ui.taskTable->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(t.getDescription())));
		ui.taskTable->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(t.getStatus())));
		if(t.getId() != 0)
			ui.taskTable->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(this->ctrl.getProgrammerById(t.getId()))));
		index++;
	}
}
void Window::add()
{
	QString des = ui.descriptionBox->text();
	//QString status = ui.statusBox->text();
	//QString id = ui.idBox->text();
	string descr = des.toStdString();
	//Task t{ des.toStdString(), "", 0 };
	this->ctrl.addTaskCtrl(descr, "open", 0);
	this->populateRepo();
}

void Window::remove()
{
	QString des = ui.descriptionBox->text();
	QString status = ui.statusBox->text();
	QString id = ui.idBox->text();
	this->ctrl.removeTaskCtrl(des.toStdString(), status.toStdString(), id.toInt());
	this->populateRepo();
}

void Window::start()
{
	QList<QTableWidgetItem*> l = ui.taskTable->selectedItems();
	QTableWidgetItem* item = l.at(0);

	int row = item->row();
	int column = item->column();

	item = ui.taskTable->item(row, 0);
	QString s = item->text();
	string ss = s.toStdString();
	string des;
	int index = -1;
	for(int i=0;i<this->currentTasks.size();i++)
		if (this->currentTasks[i].getDescription() == ss)
		{
			//QString name = QString::fromStdString(this->programmer.getName());
			des = ss;
			index = i;
			break;
		}

	try
	{
		this->ctrl.updateTaskCtrl(des, this->programmer);
		this->populateRepo();
		ui.taskTable->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(this->programmer.getName())));
		this->ctrl.notify();
	}
	catch (Exception& e)
	{
		QMessageBox::critical(this, "Warning", e.what());
	}
}

void Window::done()
{
	QList<QTableWidgetItem*> l = ui.taskTable->selectedItems();
	QTableWidgetItem* item = l.at(0);

	int row = item->row();
	int column = item->column();

	item = ui.taskTable->item(row, 0);
	QString s = item->text();
	string des = s.toStdString();
	QTableWidgetItem* item2 = ui.taskTable->item(row, 1);
	QString ss = item2->text();
	//QTableWidgetItem* item3 = ui.taskTable->item(row, 2);
	//QString n = item3->text();
	string status = ss.toStdString();
	//string name = n.toStdString();
	
	for (auto t : this->ctrl.getRepo().getTasks())
	{
		if (t.getDescription() == des)
		{
			//QString name = QString::fromStdString(this->programmer.getName());
			if(t.getStatus() == "open")
				QMessageBox::critical(this, "Error", "Task not started!");
			else if (t.getStatus() == "in progress")
			{
				QTableWidgetItem* item3 = ui.taskTable->item(row, 2);
				QString n = item3->text();
				string name = n.toStdString();
				if (name == this->programmer.getName())
				{
					this->ctrl.endTaskCtrl(des, status, this->programmer.getId());
					this->populateRepo();
				}
				else
				{
					QMessageBox::critical(this, "Error", "Task not owned!");
				}
			}
			else
			{
				QMessageBox::critical(this, "Error", "Task closed!");
			}
		}
	}
}

