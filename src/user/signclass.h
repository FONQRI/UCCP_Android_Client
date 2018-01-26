#ifndef SIGNCLASS_H
#define SIGNCLASS_H

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QTimer>
#include <QUrl>
#include <QUrlQuery>

class SignClass : public QObject {
	Q_OBJECT

  public:
	SignClass(QObject *parent = nullptr);

  signals:

  public slots:
	void signUp();
	void sec();
	void faild();

  private slots:
	void onReply();

  signals:
	void succeed();
	void failed(QNetworkReply::NetworkError error, QString msg);

  private:
};

#endif // SIGNCLASS_H
