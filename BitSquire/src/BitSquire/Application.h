#pragma once
#include "Core.h"
#include "BitSquire/Events/Event.h"

namespace Squire 
{

class SQUIRE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};
	
//Defined in clinet
Application* CreateApplication();


}
