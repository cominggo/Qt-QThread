#pragma once

#include <QtWidgets/QWidget>
#include "ui_Thread.h"

class Thread : public QWidget
{
    Q_OBJECT

public:
    Thread(QWidget *parent = nullptr);
    ~Thread();
signals:
	void starting(int num);//�����źŸ����߳�
private:
    Ui::ThreadClass ui;
};
