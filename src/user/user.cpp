#include "user.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <iostream>
#include <thread>

User::User(QObject *parent) : QObject(parent) {}

void User::signUp()
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
	userObj.insert("username", username());

	userObj.insert("password",
		   QString(QCryptographicHash::hash(password().toLocal8Bit(),
							QCryptographicHash::Md5)
				   .toHex()));
	userObj.insert("name", name());
	userObj.insert("family", family());
	userObj.insert("email", email());
	userObj.insert("sex", sex());
	userObj.insert("phoneNumber", phoneNumber());
	QJsonObject berthdayObj;
	berthdayObj.insert("year", berthdayYear());
	berthdayObj.insert("month", berthdayMonth());
	berthdayObj.insert("day", berthdayDay());
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

QString User::email() const { return _email; }

void User::setEmail(const QString &email)
{
	_email = email;
	emit emailChanged();
}

QString User::username() const { return _username; }

void User::setUsername(const QString &username)
{
	_username = username;
	emit usernameChanged();
}

QString User::password() const { return _password; }

void User::setPassword(const QString &password)
{
	_password = password;
	emit passwordChanged();
}

QString User::name() const { return _name; }

void User::setName(const QString &name)
{
	_name = name;
	emit nameChanged();
}

QString User::family() const { return _family; }

void User::setFamily(const QString &family)
{
	_family = family;
	emit familyChanged();
}

QString User::sex() const { return _sex; }

void User::setSex(const QString &sex)
{
	_sex = sex;
	emit sexChanged();
}

QString User::phoneNumber() const { return _phoneNumber; }

void User::setPhoneNumber(const QString &phoneNumber)
{
	_phoneNumber = phoneNumber;
	emit phoneNumberChanged();
}

int User::berthdayYear() const { return _berthdayYear; }

void User::setBerthdayYear(int value)
{
	_berthdayYear = value;
	emit berthdayYearChanged();
}

int User::berthdayMonth() const { return _berthdayMonth; }

void User::setBerthdayMonth(int value)
{
	_berthdayMonth = value;
	emit berthdayMonthChanged();
}

int User::berthdayDay() const { return _berthdayDay; }

void User::setBerthdayDay(int value)
{
	_berthdayDay = value;
	emit berthdayDayChanged();
}
