#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ftp-server/ftpgui.h"
#include <QFile>
#include <QPixmap>
#include "ftp-server/CSslSocket/csslsocket.h"

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

    QPixmap oPixmap(32,32);
    oPixmap.load ( "./Resource/FTP.png");

    QIcon oIcon( oPixmap );

    trayIcon = new QSystemTrayIcon(oIcon);

    QAction *quit_action = new QAction( "Exit", trayIcon );
    connect( quit_action, SIGNAL(triggered()), this, SLOT(on_exit()) );

    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction( quit_action );

    trayIcon->setContextMenu( trayIconMenu);
    trayIcon->setVisible(true);
    //trayIcon->showMessage("Test Message", "Text", QSystemTrayIcon::Information, 1000);
    //trayIcon->show();


    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    CSslSocket* ssl_socket = new CSslSocket();
    if(ssl_socket)
    {
        delete ssl_socket;
    }

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

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
     case QSystemTrayIcon::Trigger:
         this->show();
         break;
     case QSystemTrayIcon::DoubleClick:
         this->show();
         break;
     case QSystemTrayIcon::MiddleClick:
        showMessage();
        break;

     default:
         break;
    }
}
void MainWindow::showMessage()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon();
    trayIcon->showMessage(tr("QSatisfy"), tr("Will you smoke now..."), icon, 100);
}

void MainWindow::on_exit()
{
    this->close();
    QApplication::quit();
}
