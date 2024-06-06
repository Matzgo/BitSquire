#include "BitSquire.h"

class Sandbox : public Squire::Application
{
public:
	Sandbox(){}
	~Sandbox(){}

private:

};


Squire::Application* Squire::CreateApplication()
{
	return new Sandbox();
}