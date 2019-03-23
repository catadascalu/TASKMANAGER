#pragma once

#include<QAbstractTableModel>
#include "Repository.h"

class TableModel : public QAbstractTableModel
{
private:
	Repository & repo;
public:
	TableModel(Repository& r, QObject* parent = NULL);
	~TableModel();

	Repository& getRepo() { return this->repo; }
	//number of rows
	int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

	//number of columns
	int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

	//value at a given position
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	//add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	//called when a cell is edited
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

	void add(Task& t);
	void remove(Task& t);
    void update(string des, Programmer& p);
	//set properties of a cell
	Qt::ItemFlags flags(const QModelIndex& index) const override;
};
