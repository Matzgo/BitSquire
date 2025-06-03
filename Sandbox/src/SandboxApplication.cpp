#include <BitSquire.h>


class ExampleLayer : public Squire::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		SQ_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Squire::Event& event) override
	{
		SQ_TRACE("{}", event.ToString());
	}
};

class Sandbox : public Squire::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Squire::ImGuiLayer());
	}
	~Sandbox(){}

private:

};


Squire::Application* Squire::CreateApplication()
{
	return new Sandbox();
}