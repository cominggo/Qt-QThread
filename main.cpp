#include "Thread.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	qRegisterMetaType<QVector<int>>("QVector<int>");//ע����Ϣ���ó������ʹ��QVector
    QApplication a(argc, argv);
    Thread w;
    w.show();
    return a.exec();
}
