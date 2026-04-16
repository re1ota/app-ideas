#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLayout>
#include <QListWidget>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QPushButton>


class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
    MainWindow(QWidget *parent = nullptr);

    void fetchStatus();

    private:

    void handleReply(QNetworkReply *reply);
    QNetworkAccessManager *manager;
    QListWidget *statusList;
    QPushButton *fetchButton;
    QVBoxLayout *layout;

};


#endif //_MAINWINDOW_H
