#ifndef LAYEROPTIONSSCREEN_H
#define LAYEROPTIONSSCREEN_H

#include <vector>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include "Screens/EnergyZoneScreen.h"

struct Material;

class LayerOptionsScreen : public QDialog
{
    Q_OBJECT
public:
    explicit LayerOptionsScreen(QWidget *parent = nullptr);

private:
    void uploadMaterials();
    void initLayout();

private slots:
    void updateLayout();
    void showEnergyZoneScreen();
    void savePattern();
    void addLayer();
    void editPattern();
    void deletePattern();

private:
    std::vector<Material> m_materials;
    QComboBox* m_materialsList;
    QList<QLineEdit*> m_editors;
    QList<QPushButton*> m_buttons;

    QWidget* m_customWidget;
    QWidget* m_preloadWidget;
    QVBoxLayout* m_layout;

    EnergyZoneScreen* m_energyZoneScreen;

};

struct Material
{
    QString name;
    double diffusion;
    double mobility;
    double surfaceRecombination;
};

#endif // LAYEROPTIONSSCREEN_H
