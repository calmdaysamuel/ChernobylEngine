#pragma once

extern Chernobyl::Application* CreateApplication();

int main()
{
	Chernobyl::Application* application = CreateApplication();

	application->Run();
}