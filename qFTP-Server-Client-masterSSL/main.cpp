#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

QString mediadir2 = "./Resource/";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(mediadir2 + "FTP.png"));
    a.setQuitOnLastWindowClosed(false);
    MainWindow w;
    w.setWindowFlags( Qt::Dialog  | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);

        QPixmap m("./Resource/FTP.png");

    QSplashScreen splash(m);
    splash.show();

    splash.finish(&w);


    w.show();

    return a.exec();
}
