#pragma once
#include <QWidget>
#include "ui_View.h"
#include<qmessagebox.h>
#include "Model.h"
#include "Controller.h"

class TableView : public QWidget {
	Q_OBJECT

public:
	TableView(Controller& c, Programmer p, TableModel* model, QWidget *parent = Q_NULLPTR);
	//TableView() {}
	~TableView() = default;

	void setModel(TableModel* model);

private:
	Ui::View ui;
	Controller& ctrl;
	Programmer programmer;
	TableModel* model;
	//void populate();

	private slots:
	void add();
	void populate();
	void remove();
	void start();
	//void done()
};