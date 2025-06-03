#include "sqpch.h"
#include "Application.h"
#include <glad/glad.h>
namespace Squire {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this,  std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		SQ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SQ_CORE_TRACE("{0}", e.ToString());


		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true; // Returning true indicates that the event has been handled and should not propagate further
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach(); // Call OnAttach when a layer is pushed
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach(); // Call OnAttach when an overlay is pushed

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

}