#include "MyThread.h"
#include"qelapsedtimer.h"//��¼����ʱ��
#include"qdebug.h"
#include <algorithm>
//���������
Generate::Generate(QObject *parent) :QThread(parent)
{

}
void Generate::recivNum(int num)
{
	m_num = num;
}

void Generate::run()
{
	qDebug() << "������������̵߳��̵߳�ַ" << QThread::currentThread();
	QVector<int> List;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < m_num; i++)
	{
		List.push_back(qrand() % 100000);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "����" << m_num << "��������ܹ���ʱ" << ms.count() << "΢��";
	emit sendArray(List);
}

//ð���������߳�
BubbleSort::BubbleSort(QObject *parent) :QThread(parent)
{

}
void BubbleSort::recivArray(QVector<int> list)
{
	m_list = list;
}
void BubbleSort::run()
{
	qDebug() << "ð��������̵߳��̵߳�ַ" << QThread::currentThread();
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
	qDebug() << "ð����������ʱ" << ms.count() << "΢��";
	emit finish(m_list);
}

//�����������߳�

QuickSort::QuickSort(QObject *parent) :QThread(parent)
{

}

void QuickSort::recivArray(QVector<int> list)
{
	m_list = list;
}

void QuickSort::run()
{
	qDebug() << "����������̵߳��̵߳�ַ" << QThread::currentThread();
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(m_list.begin(), m_list.end());
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "ð����������ʱ" << ms.count() << "΢��";
	emit finish(m_list);
}