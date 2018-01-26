#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <iostream>

#include "src/user/user.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

	QGuiApplication app(argc, argv);

	qmlRegisterType<User>("user", 1, 0, "User");
	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
	return -1;
	return app.exec();
}
