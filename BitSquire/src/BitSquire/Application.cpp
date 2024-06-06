#include "Application.h"
#include"BitSquire/Events/ApplicationEvent.h"
#include"BitSquire/Log.h"

namespace Squire {



	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SQ_TRACE(e.ToString());
		while (true);
	}

}