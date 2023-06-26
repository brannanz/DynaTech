#pragma once

#include <wren.hpp>

#include "scriptoutput.h"

static CScriptOutput* g_output;

class CScriptInterface
{
public:
	CScriptInterface();
	~CScriptInterface();

	WrenVM* m_vm;
};
