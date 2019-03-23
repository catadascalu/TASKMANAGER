#include "View.h"

TableView::TableView(Controller& c, Programmer p, TableModel* m, QWidget *parent) : QWidget(parent), model{ m }, ctrl{ c }, programmer{ p } {
	ui.setupUi(this);
	ui.taskTableModel->setModel(this->model);

	this->setWindowTitle(QString::fromStdString(p.getName()));
	this->populate();

	connect(ui.addB, SIGNAL(clicked()), this, SLOT(add()));
	connect(ui.removeB, SIGNAL(clicked()), this, SLOT(remove()));
	connect(ui.startB, SIGNAL(clicked()), this, SLOT(start()));
	//connect(ui.endButton, SIGNAL(clicked()), this, SLOT(done()));
	connect(ui.taskTableModel, SIGNAL(dataChanged()), this, SLOT(populate()));
}

void TableView::setModel(TableModel* model) {
	ui.setupUi(this);
	ui.taskTableModel->setModel(model);
}

void TableView::populate()
{
	//this->model = new TableModel(*new Repository((*new std::vector<Task>(this->model->getRepo().getTasks())), "C:/Users/catad/source/repos/TASKMANAGER/programmers.txt", "C:/Users/catad/source/repos/TASKMANAGER/tasks.txt"));
	//TableModel* dogModel = new TableModel(*new Repository((*new std::vector<Task>(this->ctrl.getRepo().getTasks())), "C:/Users/catad/source/repos/TASKMANAGER/programmers.txt", "C:/Users/catad/source/repos/TASKMANAGER/tasks.txt"));
	//TableView* view = new TableView{};
	ui.taskTableModel->setModel(model);
	
}

void TableView::add()
{
	QString des = ui.dBox->text();
	string descr = des.toStdString();
	Task t{ descr, "open", 0 };
	this->model->add(t);
	this->populate();
}

void TableView::remove()
{
	QString des = ui.dBox->text();
	QString status = ui.sBox->text();
	QString id = ui.iBox->text();
	model->remove(Task{ des.toStdString(), status.toStdString(), id.toInt() });
	this->populate();
}

void TableView::start()
{
	QModelIndexList list = ui.taskTableModel->selectionModel()->selectedRows();
	QModelIndex item = list.at(0);
	int row = item.row();

	Task t = this->model->getRepo().getTasks()[row];

	try
	{
		this->model->update(t.getDescription(), this->programmer);
		//this->model->update(t, this->programmer);
		this->populate();
		//ui.taskTableModel->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(this->programmer.getName())));
		
	}
	catch (Exception& e)
	{
		QMessageBox::critical(this, "Warning", e.what());
	}
}