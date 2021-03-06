#include "booPCH.h"
#include "LayerStack.h"

namespace boo
{
    LayerStack::LayerStack()
    {
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
        {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer * layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer * overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer * layer)
    {
        auto iterate = std::find(m_Layers.begin(), m_Layers.end(), layer);

        if (iterate != m_Layers.end())
        {
            m_Layers.erase(iterate);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer * overlay)
    {
        auto iterate = std::find(m_Layers.begin(), m_Layers.end(), overlay);

        if (iterate != m_Layers.end())
        {
            m_Layers.erase(iterate);
        }
    }
}
