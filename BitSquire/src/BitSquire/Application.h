#pragma once
#include "Core.h"
#include "BitSquire/Events/Event.h"
#include "BitSquire/Events/ApplicationEvent.h"
#include "Window.h" 
#include "LayerStack.h"

namespace Squire 
{

class SQUIRE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);

	inline Window& GetWindow() { return *m_Window; }
	inline static Application& Get() { return *s_Instance; }
private:
	bool OnWindowClose(WindowCloseEvent& e);

	std::unique_ptr<Window> m_Window;
	bool m_Running = true;
	LayerStack m_LayerStack;
	static Application* s_Instance;
};
	
//Defined in clinet
Application* CreateApplication();


}
