#include "Thread.h"
#include"MyThread.h"

Thread::Thread(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//1、创建子线程对象
	Generate *gen = new Generate;
	BubbleSort *bubble = new BubbleSort;
	QuickSort *quick = new QuickSort;

	connect(this, &Thread::starting, gen, &Generate::recivNum);//设置子线程随机数的个数，通过信号与槽

	//2、启动子线程
	connect(ui.start, &QPushButton::clicked, this, [=]()
		{
			emit starting(10000);//设置数量
			gen->start();//开启子线程

		});

	connect(gen, &Generate::sendArray, bubble, &BubbleSort::recivArray);
	connect(gen, &Generate::sendArray, quick, &QuickSort::recivArray);


	//3、接受子线程的随机数
	connect(gen, &Generate::sendArray, this, [=](QVector<int> list)
		{
			bubble->start();
			quick->start();
			for (int i = 0; i < list.size(); i++)
			{
				ui.randList->addItem(QString::number(list.at(i)));//窗口显示
			}

		});

	connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.bubbleList->addItem(QString::number(list.at(i)));//窗口显示
			}

		});

	connect(quick, &QuickSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.quickList->addItem(QString::number(list.at(i)));//窗口显示
			}

		});
}

Thread::~Thread()
{}
