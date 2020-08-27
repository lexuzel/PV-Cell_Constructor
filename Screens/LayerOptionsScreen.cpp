#include "LayerOptionsScreen.h"

#define WIDTH 300
#define HEIGHT 300

enum Editors
{
    Width,
    Diffusion,
    Mobility,
    SurfaceRecombination
};

enum Buttons
{
    AdvanceOptions,
    SavePattern,
    AddLayer,
    Cancel,
    EditPattern,
    DeletePattern
};

LayerOptionsScreen::LayerOptionsScreen(QWidget *parent)
    : QDialog(parent)
    , m_materialsList(nullptr)
    , m_customWidget(nullptr)
    , m_preloadWidget(nullptr)
    , m_layout(nullptr)
    , m_energyZoneScreen(nullptr)
{
    uploadMaterials();

    setWindowTitle(tr("Layer Options Screen"));
    resize(WIDTH, HEIGHT);

    m_editors << new QLineEdit      // Width
              << new QLineEdit      // Diffusion
              << new QLineEdit      // Mobility
              << new QLineEdit;     // SurfaceRecombination

    m_buttons << new QPushButton(tr("Advance Options"))
              << new QPushButton(tr("Save Pattern"))
              << new QPushButton(tr("Add Layer"))
              << new QPushButton(tr("Cancel"))
              << new QPushButton(tr("Edit Pattern"))
              << new QPushButton(tr("Delete Pattern"));

    initLayout();
    updateLayout();

    connect(m_materialsList, SIGNAL(currentIndexChanged(int)), this, SLOT(updateLayout()));
    connect(m_buttons[AdvanceOptions], SIGNAL(released()), this, SLOT(showEnergyZoneScreen()));
    connect(m_buttons[SavePattern], SIGNAL(released()), this, SLOT(savePattern()));
    connect(m_buttons[AddLayer], SIGNAL(released()), this, SLOT(addLayer()));
    connect(m_buttons[Cancel], SIGNAL(released()), this, SLOT(reject()));
    connect(m_buttons[EditPattern], SIGNAL(released()), this, SLOT(editPattern()));
    connect(m_buttons[DeletePattern], SIGNAL(released()), this, SLOT(deletePattern()));
}

void LayerOptionsScreen::uploadMaterials()
{

}

void LayerOptionsScreen::initLayout()
{
    m_layout = new QVBoxLayout(this);

    QGridLayout* headLayout = new QGridLayout;
    m_layout->addLayout(headLayout);

    headLayout->addWidget(new QLabel(tr("Material")), 0, 0);
    headLayout->addWidget(new QLabel(tr("Width (mm)")), 1, 0);
    headLayout->addWidget(new QLabel(tr("Energy Zone Shape")), 2, 0);
    headLayout->addWidget(new QLabel(tr("Diffusion")), 3, 0);
    headLayout->addWidget(new QLabel(tr("Mobility")), 4, 0);
    headLayout->addWidget(new QLabel(tr("Surface Recombination")), 5, 0);

    m_materialsList = new QComboBox;
    m_materialsList->addItem(tr("Custom"));
    m_materialsList->addItem(tr("NonCustom"));
    m_materialsList->setCurrentIndex(0);
    for (const Material& i : m_materials)
        m_materialsList->addItem(i.name);

    headLayout->addWidget(m_materialsList, 0, 1);
    headLayout->addWidget(m_editors[Width], 1, 1);
    headLayout->addWidget(m_buttons[AdvanceOptions], 2, 1);
    headLayout->addWidget(m_editors[Diffusion], 3, 1);
    headLayout->addWidget(m_editors[Mobility], 4, 1);
    headLayout->addWidget(m_editors[SurfaceRecombination], 5, 1);

    m_customWidget = new QWidget;
    m_customWidget->hide();
    m_layout->addWidget(m_customWidget);

    QHBoxLayout* customLayout = new QHBoxLayout(m_customWidget);
    customLayout->addWidget(m_buttons[SavePattern]);

    m_preloadWidget = new QWidget;
    m_preloadWidget->hide();
    m_layout->addWidget(m_preloadWidget);

    QHBoxLayout* preloadLayout = new QHBoxLayout(m_preloadWidget);
    preloadLayout->addWidget(m_buttons[EditPattern]);
    preloadLayout->addWidget(m_buttons[DeletePattern]);

    QHBoxLayout* bottomLayout = new QHBoxLayout;
    m_layout->addLayout(bottomLayout);
    bottomLayout->addWidget(m_buttons[AddLayer]);
    bottomLayout->addWidget(m_buttons[Cancel]);
}

void LayerOptionsScreen::updateLayout()
{
    if (m_materialsList->currentIndex() == 0)
    {
        if (m_preloadWidget->isVisible())
            m_preloadWidget->hide();

        m_customWidget->setVisible(true);
    }
    else
    {
        if (m_customWidget->isVisible())
            m_customWidget->hide();

        m_preloadWidget->setVisible(true);
    }
}

void LayerOptionsScreen::showEnergyZoneScreen()
{
    if (!m_energyZoneScreen)
        m_energyZoneScreen = new EnergyZoneScreen(this);

    m_energyZoneScreen->exec();
}

void LayerOptionsScreen::savePattern()
{

}

void LayerOptionsScreen::addLayer()
{

}

void LayerOptionsScreen::editPattern()
{

}

void LayerOptionsScreen::deletePattern()
{

}
