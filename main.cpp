#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <iostream>

#include "src/user/signclass.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
	return -1;

	SignClass s;
	s.signUp();
	return app.exec();
}
