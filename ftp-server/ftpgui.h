void on_adduserbtn_clicked();
void on_rmuserbtn_clicked();
#ifdef FTP
#ifndef FTPGUI_H
#define FTPGUI_H

#include <QDialog>

namespace Ui {
    class FTPGUI;
}

class FtpServer;

class FTPGUI : public QDialog
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit FTPGUI(QWidget *parent = 0);
    virtual ~FTPGUI();

    // Note that this will only have an effect on Symbian and Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

private slots:
    void on_pushButtonRestartServer_clicked();

    void on_toolButtonBrowse_clicked();

    void onPeerIpChanged(const QString &peerIp);

    void on_pushButtonShowDebugLog_clicked();

    void on_pushButtonExit_clicked();

    void on_adduserbtn_clicked();
    void on_rmuserbtn_clicked();
    void on_savesettings_clicked();
void writeusers();

private:
    Ui::FTPGUI *ui;

    // This is the FTP server object.
    FtpServer *server;

    // Load the stored settings.
    void loadSettings();

    // Save the current settings.
    void saveSettings();

    // Restart the FTP server.
    void startServer();

    // Get the LAN IP of the host, e.g. "192.168.1.10".
    QString lanIp();
};

#endif // FTPGUI_H
#endif
