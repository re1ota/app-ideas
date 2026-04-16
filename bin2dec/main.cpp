#include "bin2dec.h"
#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QIcon>

int main(int argc , char **argv) {
    QApplication app(argc, argv);
    QWidget window;

    window.setWindowTitle("bin2dec");
    window.setWindowIcon(QIcon("icon.ico"));


    auto *input = new QLineEdit;
    input->setPlaceholderText("Enter binary number");

    auto *button = new QPushButton("Convert to decimal");

    auto *layout = new QVBoxLayout;
    window.setLayout(layout);

    auto *resultLabel = new QLabel("Result in decimal:");
    auto *resultPlace = new QLabel("");

    layout->addWidget(input);
    layout->addWidget(button);
    layout->addWidget(resultLabel);
    layout->addWidget(resultPlace);


    QObject::connect(button, &QPushButton::clicked, [&] {
        try {
            const std::string text = input->text().toStdString();
            const int result = binToDec(text);
            resultPlace->setText(QString::number(result));
        }catch (const std::exception &e) {
            resultPlace->setText(e.what());
        }
    });

    window.resize(300,150);
    window.show();

    return app.exec();
}