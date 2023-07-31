#include "MyThread.h"
#include"qelapsedtimer.h"//记录运行时间
#include"qdebug.h"
#include <algorithm>
//生成随机数
Generate::Generate(QObject *parent) :QThread(parent)
{

}
void Generate::recivNum(int num)
{
	m_num = num;
}

void Generate::run()
{
	qDebug() << "生成随机数的线程的线程地址" << QThread::currentThread();
	QVector<int> List;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < m_num; i++)
	{
		List.push_back(qrand() % 100000);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "生成" << m_num << "个随机数总共用时" << ms.count() << "微秒";
	emit sendArray(List);
}

//冒泡排序子线程
BubbleSort::BubbleSort(QObject *parent) :QThread(parent)
{

}
void BubbleSort::recivArray(QVector<int> list)
{
	m_list = list;
}
void BubbleSort::run()
{
	qDebug() << "冒泡排序的线程的线程地址" << QThread::currentThread();
	auto start = std::chrono::high_resolution_clock::now();
	int temp;
	for (int i = 0; i < m_list.size(); i++)
	{
		for (int j = 0; j < m_list.size() - 1 - i; j++)
		{
			if (m_list[j] > m_list[j + 1])
			{
				temp = m_list[j];
				m_list[j] = m_list[j + 1];
				m_list[j + 1] = temp;
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "冒泡排序总用时" << ms.count() << "微秒";
	emit finish(m_list);
}

//快速排序子线程

QuickSort::QuickSort(QObject *parent) :QThread(parent)
{

}

void QuickSort::recivArray(QVector<int> list)
{
	m_list = list;
}

void QuickSort::run()
{
	qDebug() << "快速排序的线程的线程地址" << QThread::currentThread();
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(m_list.begin(), m_list.end());
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "冒泡排序总用时" << ms.count() << "微秒";
	emit finish(m_list);
}