#ifndef USER_H
#define USER_H

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QTimer>
#include <QUrl>
#include <QUrlQuery>

class User : public QObject {
	Q_OBJECT
	/**

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

	  */
	Q_PROPERTY(
	QString username READ username WRITE setUsername NOTIFY usernameChanged)
	Q_PROPERTY(
	QString password READ password WRITE setPassword NOTIFY passwordChanged)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString family READ family WRITE setFamily NOTIFY familyChanged)
	Q_PROPERTY(QString sex READ sex WRITE setSex NOTIFY sexChanged)
	Q_PROPERTY(QString phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY
		   phoneNumberChanged)
	Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
	Q_PROPERTY(int berthdayYear READ berthdayYear WRITE setBerthdayYear NOTIFY
		   berthdayYearChanged)
	Q_PROPERTY(int berthdayMonth READ berthdayMonth WRITE setBerthdayMonth
		   NOTIFY berthdayMonthChanged)
	Q_PROPERTY(int berthdayDay READ berthdayDay WRITE setBerthdayDay NOTIFY
		   berthdayDayChanged)
  public:
	User(QObject *parent = nullptr);

	int berthdayDay() const;
	void setBerthdayDay(int value);

	int berthdayMonth() const;
	void setBerthdayMonth(int value);

	int berthdayYear() const;
	void setBerthdayYear(int value);

	QString phoneNumber() const;
	void setPhoneNumber(const QString &phoneNumber);

	QString sex() const;
	void setSex(const QString &sex);

	QString family() const;
	void setFamily(const QString &family);

	QString name() const;
	void setName(const QString &name);

	QString password() const;
	void setPassword(const QString &password);

	QString username() const;
	void setUsername(const QString &username);

	QString email() const;
	void setEmail(const QString &email);

  signals:

  public slots:
	void signUp();

	// qml propertys

  private slots:

  signals:
	void usernameChanged();
	void passwordChanged();
	void nameChanged();
	void familyChanged();
	void sexChanged();
	void phoneNumberChanged();
	void emailChanged();
	void berthdayYearChanged();
	void berthdayMonthChanged();
	void berthdayDayChanged();

  private:
	QString _email{""};
	QString _username{""};
	QString _password{""};
	QString _name{""};
	QString _family{""};
	QString _sex{""};
	QString _phoneNumber{""};
	int _berthdayYear{0};
	int _berthdayMonth{0};
	int _berthdayDay{0};
};

#endif // USER_H
