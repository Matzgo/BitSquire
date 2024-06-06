#pragma once

#ifdef  BS_PLATFORM_WINDOWS

extern BitSquire::Application* BitSquire::CreateApplication();

int main(int argc, char** argv)
{
	auto app = BitSquire::CreateApplication();
	app->Run();
	delete app;
}

#endif //  BS_PLATFORM_WINDOWS
