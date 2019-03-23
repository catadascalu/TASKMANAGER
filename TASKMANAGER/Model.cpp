#include "Model.h"
#include<qmessagebox.h>
#include <QFont>
#include <QBrush>

TableModel::TableModel(Repository& r, QObject* parent) : QAbstractTableModel{ parent }, repo{ r } {}

TableModel::~TableModel() {}

int TableModel::rowCount(const QModelIndex& parent) const
{
	int tasksN = this->repo.getTasks().size();

	return tasksN + 1;
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	return 3;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();

	//get the tasks
	std::vector<Task> tasks = this->repo.getTasks();

	//allow adding in the table
	if (row == tasks.size())
	{
		return QVariant();
	}

	//get task from current row
	Task t = tasks[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(t.getDescription());
		case 1:
			return QString::fromStdString(t.getStatus());
		case 2:
			return QString::fromStdString(repo.getProgrammerById(t.getId()));
		default:
			break;
		}
	}

	if (role == Qt::FontRole)
	{
		QFont font("Times", 10, 5, true);
		font.setItalic(false);
		return font;
	}

	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{ Qt::magenta } };
		}
	}

	return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "DESCRIPTION" };
			case 1:
				return QString{ "STATUS" };
			case 2:
				return QString{ "PROGRAMMER" };
			default:
				break;
			}
		}
	}

	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}

	return QVariant{};
}

void TableModel::add(Task& t)
{
	beginInsertRows(QModelIndex(), repo.getTasks().size(), repo.getTasks().size());
	repo.addTask(t);
	endInsertRows();
	
	std::vector<Task> tasks = this->repo.getTasks();
	int size = tasks.size();
	QModelIndex top = createIndex(size-1, 0, (void*)nullptr);
	QModelIndex bottom = createIndex(size-1, 1, (void*)nullptr);

	emit dataChanged(QModelIndex(), QModelIndex());
}

void TableModel::remove(Task& t)
{
	beginRemoveRows(QModelIndex(), this->repo.getTask(t), this->repo.getTask(t));
	repo.removeTask(t);
	endRemoveRows();
	emit dataChanged(QModelIndex(), QModelIndex());
}


void TableModel::update(string des, Programmer& p)
{
	Task t{ des, "", 0 };
	int row = repo.getTask(t);
	repo.updateTask(des, p);
	//int column = 2;
	//int role = Qt::DisplayRole;
	//if(role == Qt::DisplayRole)
		//if(column == 2)
			//return QString::fromStdString(repo.getProgrammers()[repo.getTasks()[row].getId()].getName());
			
	emit dataChanged(QModelIndex(), QModelIndex());
	
}
bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
if (!index.isValid() || role != Qt::EditRole)
return false;

int taskIndex = index.row();

std::vector<Task> tasks = this->repo.getTasks();

if (taskIndex == tasks.size())
{
this->beginInsertRows(QModelIndex{}, taskIndex, taskIndex);
switch (index.column())
{
case 0:
this->repo.addTask(Task{ value.toString().toStdString(), "open", 0 });
break;
default:
break;
}
this->endInsertRows();
return true;
}

Task& currentTask = tasks[taskIndex];
switch (index.column())
{
case 2:
currentTask.setId(value.toInt());
break;
case 1:
currentTask.setStatus(value.toString().toStdString());
}

this->repo.updateTask(currentTask.getDescription(), this->repo.getProgrammer(currentTask.getId()));

emit dataChanged(index, index);

return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{
return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

