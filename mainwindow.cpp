#include <QVBoxLayout>
#include <QPushButton>

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "LayerManager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_fileManagerScreen(nullptr)
    , m_preferencesScreen(nullptr)
    , m_infoScreen(nullptr)
    , m_layerOptionsScreen(nullptr)
{
    ui->setupUi(this);
    resize(600, 400);
    setWindowTitle(tr("Starting screen"));
    updateLayout();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    QMenu* fileMenu = new QMenu(tr("File"), this);
    fileMenu->addAction(tr("New element"), QApplication::instance(), SLOT(showStartingLayout()));
    fileMenu->addAction(tr("Open"), QApplication::instance(), SLOT(showOpenFileScreen()));
    fileMenu->addAction(tr("Save"), QApplication::instance(), SLOT(saveFile()));
    fileMenu->addAction(tr("Save as"), QApplication::instance(), SLOT(showSaveFileScreen()));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Exit"), QApplication::instance(), SLOT(quit()));

    menuBar()->addMenu(fileMenu);
    menuBar()->addAction(tr("Preferences"), QApplication::instance(), SLOT(showPreferencesScreen()));
    menuBar()->addAction(tr("Info"), QApplication::instance(), SLOT(showInfoScreen()));
}

void MainWindow::updateLayout()
{
    qDeleteAll(findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    initMenu();

    if (LayerManager::instance()->isEmpty())
    {
        setWindowTitle(tr("Starting screen"));
        resize(600, 400);
        showStartingLayout();
    }
    else
    {
        setWindowTitle(tr("Main screen"));
        resize(600, 400);

    }


}

void MainWindow::showStartingLayout()
{
    if (!LayerManager::instance()->isEmpty())
    {

    }

    QPushButton* newElementBtn = new QPushButton("Create New Element", this);
    newElementBtn->setGeometry(QRect(QPoint((width()/2 - 100), (height()/2 - 25)), QSize(200, 50)));
    connect(newElementBtn, SIGNAL (released()), this, SLOT (showLayerOptionsScreen()));
}

void MainWindow::showLayerOptionsScreen()
{
    if (!m_layerOptionsScreen)
        m_layerOptionsScreen = new LayerOptionsScreen(this);

    m_layerOptionsScreen->exec();
}

void MainWindow::showOpenFileScreen()
{

}

void MainWindow::saveFile()
{

}

void MainWindow::showSaveFileScreen()
{

}

void MainWindow::showPreferencesScreen()
{
    if (!m_preferencesScreen)
        m_preferencesScreen = new PreferencesScreen(this);

    m_preferencesScreen->exec();
}

void MainWindow::showInfoScreen()
{
    if (!m_infoScreen)
        m_infoScreen = new InfoScreen(this);

    m_infoScreen->exec();
}
