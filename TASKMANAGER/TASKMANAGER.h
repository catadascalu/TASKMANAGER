#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TASKMANAGER.h"

class TASKMANAGER : public QMainWindow
{
	Q_OBJECT

public:
	TASKMANAGER(QWidget *parent = Q_NULLPTR);

private:
	Ui::TASKMANAGERClass ui;
};
