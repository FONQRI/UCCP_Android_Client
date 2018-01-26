#include "signclass.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <iostream>
#include <thread>

SignClass::SignClass(QObject *parent) : QObject(parent) {}

void SignClass::signUp()
{
	QTimer timer;
	timer.start(30000);

	QNetworkAccessManager *manager = new QNetworkAccessManager();

	QNetworkRequest req;
	timer.setSingleShot(true);

	// connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

	req.setUrl(QUrl("http://127.0.0.1:8888/signup"));
	req.setRawHeader("Accept-Encoding", "gzip, deflate");
	req.setRawHeader("Content-Type", "application/json");
	req.setHeader(QNetworkRequest::ContentTypeHeader,
		  QVariant("application/json"));
	QJsonObject userObj;
	userObj.insert("username", "FONQRI");

	userObj.insert(
	"password",
	QString(QCryptographicHash::hash(("password"), QCryptographicHash::Md5)
			.toHex()));
	userObj.insert("name", "behnam");
	userObj.insert("family", "sabaghi");
	userObj.insert("email", "behnamsabaghi@gmail.com");
	userObj.insert("sex", "male");
	userObj.insert("phoneNumber", "09304912785");
	QJsonObject berthdayObj;
	berthdayObj.insert("year", 2018);
	berthdayObj.insert("month", 1);
	berthdayObj.insert("day", 26);
	userObj.insert("berthday", berthdayObj);

	//	qDebug() << QJsonDocument(userObj).toJson();

	QNetworkReply *rep = manager->post(req, QJsonDocument(userObj).toJson());
	connect(&timer, &QTimer::timeout, [&rep]() { rep->abort(); });

	QJsonObject replyObj;

	QObject::connect(manager, &QNetworkAccessManager::finished,
			 [&replyObj](QNetworkReply *reply) {
			 if (reply->error() != QNetworkReply::NoError) {
				 qDebug() << "Error:" << reply->errorString();
				 return;
			 }
			 QByteArray buf = reply->readAll();

			 std::clog << "OK : " << buf.toStdString();
			 });
}

void SignClass::sec() { std::clog << "worked" << std::endl; }

void SignClass::faild() {}

void SignClass::onReply() {}
