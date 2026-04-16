#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLayout>
#include <QListWidget>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QPushButton>
#include <QLabel>


class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
    MainWindow(QWidget *parent = nullptr);

    void fetchStatus();

    private:

    void handleReply(QNetworkReply *reply);
    QNetworkAccessManager *manager;
    QListWidget *goodStatusList;
    QListWidget *badStatusList;
    QPushButton *fetchButton;
    QVBoxLayout *layout;
    QLabel *goodStatusLabel;
    QLabel *badStatusLabel;

};


#endif //_MAINWINDOW_H
