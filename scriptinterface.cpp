#include "scriptinterface.h"

#include <string>
#include <sstream>
#include <iostream>
#include "filesystem.h"

void InternalDoWrite(WrenVM* vm, const char* text)
{
	g_output->Log(text, true);
}

void InternalDoError(WrenVM* vm, WrenErrorType errorType,
	const char* module, const int line,
	const char* msg)
{
	char* err_msg = (char*)malloc(13 * sizeof(char));

	switch (errorType)
	{
		// TODO: sprintf is unsafe
		case WREN_ERROR_COMPILE:
		{
			sprintf(err_msg, "[%s line %d] [Error] %s\n", module, line, msg);
		} break;
		case WREN_ERROR_STACK_TRACE:
		{
			sprintf(err_msg, "[%s line %d] in %s\n", module, line, msg);
		} break;
		case WREN_ERROR_RUNTIME:
		{
			sprintf(err_msg, "[Runtime Error] %s\n", msg);
		} break;
	}

	if (err_msg != NULL)
	{
		g_output->Log(err_msg, false);
	}
	else {
		g_output->Log("SCRIPT: Unidentified error", false);
	}
}

WrenLoadModuleResult InternalLoadModule(WrenVM* vm, const char* name) {
	WrenLoadModuleResult result = { 0 };
	result.source = filesystem::LoadAsset("scripts/" + std::string(name)).c_str();
	return result;
}

CScriptInterface::CScriptInterface(std::string file)
{
	WrenConfiguration config;
	wrenInitConfiguration(&config);
	config.writeFn = &InternalDoWrite;
	config.errorFn = &InternalDoError;
	config.loadModuleFn = &InternalLoadModule;
	m_vm = wrenNewVM(&config);

	const char* module = "main";

	WrenInterpretResult result = wrenInterpret(m_vm, module, file.c_str());

	switch (result) {
		case WREN_RESULT_COMPILE_ERROR:
		{ g_output->Log("ENGINE: Script Compile Error", false); } break;
		case WREN_RESULT_RUNTIME_ERROR:
		{ g_output->Log("ENGINE: Script Runtime Error", false); } break;
		case WREN_RESULT_SUCCESS:
		{ g_output->Log("ENGINE: Script Compile Success", false); } break;
	}
}

CScriptInterface::~CScriptInterface()
{
	wrenFreeVM(m_vm);
}
