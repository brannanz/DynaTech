#pragma once

// this file must be called something other than Instance.h
// or it will conflict with the msvc sdk

#include <iostream>
#include <vector>

class Instance
{
public:
	Instance();
	~Instance();

	inline Instance* getParent() { return parent; };
	void setParent(Instance* instance);
	std::string getName();
	void setName(std::string newName);
	void addChild(Instance* instance);
	void removeChild(Instance* child);

	std::vector<Instance*> children;
protected:
	Instance* parent;
	std::string name;
	std::string className;
};