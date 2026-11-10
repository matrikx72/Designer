#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

   connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
   connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

Dialog::~Dialog()
{
delete ui;
}

QString Dialog::getHostName() const { return ui->hostLineEdit->text(); }
QString Dialog::getDbName() const { return ui->dbNameLineEdit->text(); }
QString Dialog::getLogin() const { return ui->loginLineEdit->text(); }
QString Dialog::getPassword() const { return ui->passwordLineEdit->text(); }
uint Dialog::getPort() const { return ui->portSpinBox->value(); }
