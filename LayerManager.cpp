#include "LayerManager.h"

LayerManager::LayerManager()
{

}

LayerManager* LayerManager::instance()
{
    static LayerManager* instance = new LayerManager;
    return instance;
}
