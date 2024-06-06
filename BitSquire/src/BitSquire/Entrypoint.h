#pragma once

#ifdef  SQ_PLATFORM_WINDOWS

extern Squire::Application* Squire::CreateApplication();

int main(int argc, char** argv)
{
	Squire::Log::Init();
	SQ_CORE_WARN("Initialized Core Log");
	int a = 5;
	SQ_INFO("Var={0}",a);

	auto app = Squire::CreateApplication();
	app->Run();
	delete app;
}

#endif //  BS_PLATFORM_WINDOWS
