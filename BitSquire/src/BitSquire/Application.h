#pragma once
#include "Core.h"
namespace BitSquire 
{

class BITSQUIRE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};
	
//Defined in clinet
Application* CreateApplication();


}
