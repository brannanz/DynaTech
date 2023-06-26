#pragma once

#include <qfilesystemmodel.h>
#include <QListWidget>

class CScriptOutput : public QListWidget
{
public:
	CScriptOutput();

	void Log(std::string text);
};