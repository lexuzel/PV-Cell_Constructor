#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Screens/FileManagerScreen.h"
#include "Screens/PreferencesScreen.h"
#include "Screens/InfoScreen.h"
#include "Screens/LayerOptionsScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateLayout();

private:
    void initMenu();

private slots:
    void showStartingLayout();
    void showOpenFileScreen();
    void saveFile();
    void showSaveFileScreen();
    void showPreferencesScreen();
    void showInfoScreen();
    void showLayerOptionsScreen();

private:
    Ui::MainWindow *ui;

    FileManagerScreen* m_fileManagerScreen;
    PreferencesScreen* m_preferencesScreen;
    InfoScreen* m_infoScreen;
    LayerOptionsScreen* m_layerOptionsScreen;
};
#endif // MAINWINDOW_H
