#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openDialogButton, &QPushButton::clicked, this, [this]() {
        Dialog dlg(this);
        if (dlg.exec() == QDialog::Accepted) {
            QString host = dlg.getHostName();
            QString db = dlg.getDbName();
            QString login = dlg.getLogin();
            uint port = dlg.getPort();

            QString info = QString("Хост: %1\nБД: %2\nЛогин: %3\nПорт: %4")
                               .arg(host, db, login, QString::number(port));
            QMessageBox::information(this, "Данные подключения", info);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
