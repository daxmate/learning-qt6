#include "mainwindow.h"
#include <QTranslator>
#include <print>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;

	if(translator.load(":/i18n/learningqt6_ja.qm"))
	{
		a.installTranslator(&translator);
	}
	else
	{
		std::print("Failed to load learningqt6_zh.qm");
	}

	MainWindow w;

	w.show();
	return a.exec();
}
