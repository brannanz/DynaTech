#pragma once

#include <string>

#include "scriptinterface.h"

namespace filesystem
{
	static std::string g_contentPath = "/content/";

	std::string LoadAsset(std::string file);
}
