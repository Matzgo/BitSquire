#include "BitSquire.h"

class Sandbox : public BitSquire::Application
{
public:
	Sandbox(){}
	~Sandbox(){}

private:

};

//Sandbox : public BitSquire::Application::Sandbox : public BitSquire::Application()
//{
//}
//
//Sandbox : public BitSquire::Application::~Sandbox : public BitSquire::Application()
//{
//}
BitSquire::Application* BitSquire::CreateApplication()
{
	return new Sandbox();
}