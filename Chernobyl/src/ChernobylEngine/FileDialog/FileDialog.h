#pragma once
#include <string>
#include "../Core/ChernobylCore.h"

namespace Chernobyl
{
	class CHERNOBYL_API FileDialog
	{
		static std::string OpenFile(std::string directory);
		static std::string SaveFile(std::string directory, std::string file);
	};
}


