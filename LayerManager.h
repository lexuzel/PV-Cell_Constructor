#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include <vector>
#include <map>

#include "PVLayer.h"

class LayerManager
{
public:
    static LayerManager* instance();

    void addLayer(const PVLayer& layer, bool inTail = true);
    void removeLayer(int index);
    void clearAll();

    bool isEmpty() { return m_layers.empty(); }
private:
    LayerManager();
private:
    std::vector<PVLayer> m_layers;
};

#endif // LAYERMANAGER_H
