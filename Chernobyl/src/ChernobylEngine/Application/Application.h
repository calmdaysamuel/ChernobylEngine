#pragma once
#include "../Core/ChernobylCore.h"
#include "../Timer/Time.h"


namespace Chernobyl
{
	class CHERNOBYL_API Application
	{
	public:
		Time ApplicationTime = Time();
	public:
		Application();
		virtual ~Application();
		virtual void Run();
	};
}


