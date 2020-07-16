#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    void showMessage();

    int adminftp=0;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ftpServerbtn_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
        void on_exit();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
