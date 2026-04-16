#include "mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLayout>
#include <QListWidget>
#include <string>




MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {
    setWindowTitle("GitHub Status");
    resize(500,400);
    setWindowIcon(QIcon("icon.ico"));
    manager = new QNetworkAccessManager(this);

    QWidget *centralWidget = new QWidget(this);
    goodStatusList = new QListWidget(centralWidget);
    badStatusList = new QListWidget(centralWidget);
    fetchButton = new QPushButton("Fetch Status", centralWidget);
    layout = new QVBoxLayout(centralWidget);
    goodStatusLabel = new QLabel("operational status:", centralWidget);
    badStatusLabel = new QLabel("non operational status:", centralWidget);

    layout->addWidget(fetchButton);
    layout->addWidget(goodStatusLabel);
    layout->addWidget(goodStatusList);
    layout->addWidget(badStatusLabel);
    layout->addWidget(badStatusList);


    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(fetchButton, &QPushButton::clicked, this, &MainWindow::fetchStatus);

}


void MainWindow::fetchStatus() {
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.githubstatus.com/api/v2/summary.json"));
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]{handleReply(reply);});

}

void MainWindow::handleReply(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Fehler beim Einlesen: " << reply->errorString();
        reply->deleteLater();
        return;
    }
    QByteArray result = reply->readAll();

    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(result, &error);

    if (json.isNull() || !json.isObject()) {
        qDebug() << "Fehler beim Parsen: " << error.errorString();
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObj = json.object();

    QJsonArray components = jsonObj["components"].toArray();

    goodStatusList->clear();
    badStatusList->clear();

    foreach (QJsonValue v, components) {
        QJsonObject componentObj = v.toObject();
        QString name = componentObj["name"].toString();
        QString status = componentObj["status"].toString();
        QString line = name + " - " + status;
        if (name != "Visit www.githubstatus.com for more information" && status == "operational") {
            goodStatusList->addItem(line);
        }
        if (name != "Visit www.githubstatus.com for more information" && status != "operational") {
            badStatusList->addItem(line);
        }
    }

    reply->deleteLater();

}


