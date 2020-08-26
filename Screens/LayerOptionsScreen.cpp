#include "LayerOptionsScreen.h"

LayerOptionsScreen::LayerOptionsScreen(QWidget *parent)
    : QDialog(parent)
{
    uploadMaterials();

    setWindowTitle(tr("Layer Options Screen"));
    resize(400, 600);

    QGridLayout* layout = new QGridLayout(this);

    m_labels << new QLabel(tr("Material"), this)
             << new QLabel(tr("Width"), this)
             << new QLabel(tr("Energy Zone Shape"), this)
             << new QLabel(tr("Diffusion"), this)
             << new QLabel(tr("Mobility"), this)
             << new QLabel(tr("Surface Recombination"), this);
    for (auto label : m_labels)
    {
        static int row = 0;
        layout->addWidget(label, row++, 0);
    }

    m_materialsList = new QComboBox(this);
    for (const Material& i : m_materials)
        m_materialsList->addItem(i.name);
    layout->addWidget(m_materialsList, 0, 1);

    m_editors.push_back(new QLineEdit);
    layout->addWidget(m_editors[0], 1, 1);

    m_buttons.push_back(new QPushButton(tr("Advace Options"), this));
    layout->addWidget(m_buttons[0], 2, 1);

    for (int row = 3; row <= 5; row++)
    {
        m_editors.push_back(new QLineEdit);
        layout->addWidget(m_editors[row-2], row, 1);
    }

    m_buttons << new QPushButton(tr("Save Pattern"), this)
              << new QPushButton(tr("Add Layer"), this)
              << new QPushButton(tr("Cancel"), this);

    for (int row = 6; row <= 8; row++)
        layout->addWidget(m_buttons[row - 5], row, 1);


}

void LayerOptionsScreen::uploadMaterials()
{

}
