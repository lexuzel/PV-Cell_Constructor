#ifndef LAYEROPTIONSSCREEN_H
#define LAYEROPTIONSSCREEN_H

#include <vector>

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>

struct Material;

class LayerOptionsScreen : public QDialog
{
    Q_OBJECT
public:
    explicit LayerOptionsScreen(QWidget *parent = nullptr);

private:
    void uploadMaterials();

private:
    std::vector<Material> m_materials;

    QList<QLabel*> m_labels;
    QList<QLineEdit*> m_editors;
    QList<QPushButton*> m_buttons;
    QComboBox* m_materialsList;


};

struct Material
{
    QString name;
    double diffusion;
    double mobility;
    double surfaceRecombination;
};

#endif // LAYEROPTIONSSCREEN_H
