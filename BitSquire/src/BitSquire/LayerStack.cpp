#include "sqpch.h"
#include "LayerStack.h"

namespace Squire
{

	LayerStack::LayerStack()
	{
		// At the beginning, insert point is at the start of the vector
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		// Cleanup: delete all layers (if LayerStack owns them)
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		// Insert layer before the overlay insertion point
		m_LayerInsert = m_Layers.insert(m_LayerInsert, layer);

	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		// Overlays are inserted at the end
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			--m_LayerInsert; // Adjust insert point back
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}


