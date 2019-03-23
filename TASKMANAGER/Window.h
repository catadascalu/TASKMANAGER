#pragma once
#include <QWidget>
#include<qtablewidget.h>
#include<qmessagebox.h>
#include "ui_Window.h"
#include "Observer.h"
#include "Controller.h"

class Window : public QWidget, public Observer
{
	Q_OBJECT

public:
	Window(Controller& ctrl, Programmer p, QWidget *parent = Q_NULLPTR);
	~Window() {}

private:
	Ui::Window ui;
	Controller& ctrl;
	Programmer programmer;
	vector<Task> currentTasks;

	void update() override;
	void populateRepo();

	private slots:
	void add();
	void remove();
	void start();
	void done();
};