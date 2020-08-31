#include "EnergyZoneScreen.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#define WIDTH 400
#define HEIGHT 300
#define BTN_SIZE 30

enum Buttons
{
    P, I, N
};

EnergyZoneScreen::EnergyZoneScreen(QWidget *parent)
    : QDialog(parent)
{
    resize(WIDTH, HEIGHT);
    m_layout = new QVBoxLayout(this);

    QWidget* buttonWidget = new QWidget(this);
    m_buttonGroup = new QButtonGroup(buttonWidget);
    m_buttonGroup->setExclusive(true);
    m_buttonGroup->addButton(new QPushButton("P", buttonWidget), P);
    m_buttonGroup->addButton(new QPushButton("I", buttonWidget), I);
    m_buttonGroup->addButton(new QPushButton("N", buttonWidget), N);

    for (int i = P; i <= N; i++)
        m_buttonGroup->button(i)->setGeometry((WIDTH/2 - 1.5 * BTN_SIZE) + i * BTN_SIZE, 0, BTN_SIZE, BTN_SIZE);
    m_buttonGroup->button(P)->setDown(true);

    m_layout->addWidget(buttonWidget);

    QHBoxLayout* zoneLayout = new QHBoxLayout(this);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    m_leftGap = new QLineEdit(this);
    leftLayout->addWidget(m_leftGap);
    leftLayout->addWidget(new QLabel(tr("eV")));
    zoneLayout->addLayout(leftLayout);

    m_energyZoneWidget = new EnergyZoneWidget(this);
    zoneLayout->addWidget(m_energyZoneWidget);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    m_rightGap = new QLineEdit(this);
    rightLayout->addWidget(m_rightGap);
    rightLayout->addWidget(new QLabel(tr("eV")));
    zoneLayout->addLayout(rightLayout);

    m_layout->addLayout(zoneLayout);

    m_bottomWidget = new QWidget(this);
    QHBoxLayout* bottomLayout = new QHBoxLayout(m_bottomWidget);
    bottomLayout->addWidget(new QLabel(tr("Concentration of impur.")));
    m_concImpur = new QLineEdit(this);
    bottomLayout->addWidget(m_concImpur);

    m_layout->addWidget(m_bottomWidget);

    updateLayout();

    connect(m_buttonGroup, SIGNAL(idReleased(int)), this, SLOT(updateLayout()));
}

void EnergyZoneScreen::updateLayout()
{
    if (m_buttonGroup->button(I)->isDown())
        m_bottomWidget->hide();
    else
        m_bottomWidget->show();
}
