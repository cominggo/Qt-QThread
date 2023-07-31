#pragma once
#pragma execution_character_set("utf-8")
#include<QThread>
#include<Qvector>
//���������
class Generate : public QThread
{
	Q_OBJECT
public:
	explicit Generate(QObject *parent = nullptr);
	void recivNum(int num);
protected:
	void run() override;
signals:
	void sendArray(QVector<int> list);
private:
	int m_num;
};

//ð������
class BubbleSort : public QThread
{
	Q_OBJECT
public:
	explicit BubbleSort(QObject *parent = nullptr);

	void recivArray(QVector<int> list);
protected:
	void run() override;
signals:
	void finish(QVector<int> num);
private:
	QVector<int> m_list;
};
//��������
class QuickSort : public QThread
{
	Q_OBJECT
public:
	explicit QuickSort(QObject *parent = nullptr);

	void recivArray(QVector<int> list);
protected:
	void run() override;
signals:
	void finish(QVector<int> num);
private:
	QVector<int> m_list;
};