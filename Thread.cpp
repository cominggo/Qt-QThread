#include "Thread.h"
#include"MyThread.h"

Thread::Thread(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//1���������̶߳���
	Generate *gen = new Generate;
	BubbleSort *bubble = new BubbleSort;
	QuickSort *quick = new QuickSort;

	connect(this, &Thread::starting, gen, &Generate::recivNum);//�������߳�������ĸ�����ͨ���ź����

	//2���������߳�
	connect(ui.start, &QPushButton::clicked, this, [=]()
		{
			emit starting(10000);//��������
			gen->start();//�������߳�

		});

	connect(gen, &Generate::sendArray, bubble, &BubbleSort::recivArray);
	connect(gen, &Generate::sendArray, quick, &QuickSort::recivArray);


	//3���������̵߳������
	connect(gen, &Generate::sendArray, this, [=](QVector<int> list)
		{
			bubble->start();
			quick->start();
			for (int i = 0; i < list.size(); i++)
			{
				ui.randList->addItem(QString::number(list.at(i)));//������ʾ
			}

		});

	connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.bubbleList->addItem(QString::number(list.at(i)));//������ʾ
			}

		});

	connect(quick, &QuickSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.quickList->addItem(QString::number(list.at(i)));//������ʾ
			}

		});
}

Thread::~Thread()
{}
