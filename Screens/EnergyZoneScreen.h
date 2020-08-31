#ifndef ENERGYZONESCREEN_H
#define ENERGYZONESCREEN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QButtonGroup>

#include "Tools/EnergyZoneWidget.h"

class EnergyZoneScreen : public QDialog
{
    Q_OBJECT
public:
    explicit EnergyZoneScreen(QWidget *parent = nullptr);

private slots:
    void updateLayout();

private:
    QVBoxLayout* m_layout;
    QWidget* m_bottomWidget;

    QButtonGroup* m_buttonGroup;
    QLineEdit* m_leftGap;
    QLineEdit* m_rightGap;
    EnergyZoneWidget* m_energyZoneWidget;
    QLineEdit* m_concImpur;
};

#endif // ENERGYZONESCREEN_H
