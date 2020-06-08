#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ftp-server/ftpgui.h"

#ifdef FTP
    FTPGUI *ftpgui;
#endif


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile stylesheet("./Resource/themes/qdarkstyle/qdarkstyle.qss");
    stylesheet.open(QFile::ReadOnly);
    this->setStyleSheet(stylesheet.readAll());
    stylesheet.close();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ftpServerbtn_clicked()
{
#ifdef FTP
    if (adminftp==0){
    ftpgui = new FTPGUI;
    adminftp=1;
    }
    if (adminftp) { ftpgui->show();}
#endif
}
