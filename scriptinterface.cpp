#include "scriptinterface.h"

void InternalDoWrite(WrenVM* vm, const char* text)
{
	g_output->Log(text);
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

	if (err_msg == (char*)malloc(13 * sizeof(char)))
	{
		g_output->Log(err_msg);
	}
	else {
		g_output->Log("SCRIPT: Unidentified error");
	}
}

CScriptInterface::CScriptInterface(std::string file)
{
	WrenConfiguration config;
	wrenInitConfiguration(&config);
	config.writeFn = &InternalDoWrite;
	config.errorFn = &InternalDoError;
	m_vm = wrenNewVM(&config);

	const char* module = "main";
	// const char* script = "System.print(\"WREN: Hello!\")";

	WrenInterpretResult result = wrenInterpret(m_vm, module, file.c_str());

	switch (result) {
		case WREN_RESULT_COMPILE_ERROR:
		{ g_output->Log("ENGINE: Script Compile Error"); } break;
		case WREN_RESULT_RUNTIME_ERROR:
		{ g_output->Log("ENGINE: Script Runtime Error"); } break;
		case WREN_RESULT_SUCCESS:
		{ g_output->Log("ENGINE: Script Compile Success"); } break;
	}
}

CScriptInterface::~CScriptInterface()
{
	wrenFreeVM(m_vm);
}
