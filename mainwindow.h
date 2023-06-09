
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include <QTextBrowser>
#include <QPixmap>
#include <QLabel>
#include <QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ZorkUL game;
    QTextBrowser* console;
    QTextBrowser* consoleGUI;
    QTextBrowser* inventory;
    QLabel* imageLabel;
    QComboBox* list1;
    QComboBox* list2;
    void appendTextToConsole(const QString& text);
    void appendTextToConsoleGUI(const QString& text);
    void appendTextToinventory(const QString& text);
    string nextRoom;
    void findForNextRoom(string nextRoom);
    bool gameIsStarted;
    void setCoverImage();
    void displayLocationDesc();

private slots: // handle the events triggered
    void onStartGameButtonPressed();
    void oncommandsButtonPressed();
    void onMapButtonPressed();
    void onupButtonPressed();
    void onrightButtonPressed();
    void ondownButtonPressed();
    void onleftButtonPressed();
    void on_exit_button_pressed();
    void on_textEdit_textChanged();
    void on_yes_pressed();
    void on_no_pressed();
    void on_drop_clicked();
};

#endif // MAINWINDOW_H
