#include "scriptoutput.h"

#include <chrono>
#include <iostream>

CScriptOutput::CScriptOutput()
{
	setReadOnly(true);
}

void CScriptOutput::Log( std::string text, bool isscript )
{
	const auto now = std::chrono::system_clock::now();
	const std::time_t tc = std::chrono::system_clock::to_time_t( now );

	std::string timestr = std::ctime( &tc );
	timestr.erase( std::remove( timestr.begin(), timestr.end(), '\n' ), timestr.cend() );

	// append( QString::fromStdString(timestr + " - " + text) );
	// const char* out = text.c_str();
	// addItem(new QListWidgetItem(out));

	if (!isscript)
	{
		std::cout << text << std::endl;
	}
	else {
		std::cout << text;
	}
}
