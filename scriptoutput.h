#pragma once

#include <qfilesystemmodel.h>
#include <qtextedit.h>

class CScriptOutput : public QTextEdit
{
public:
	CScriptOutput();

	void Log(std::string text, bool isscript);
};