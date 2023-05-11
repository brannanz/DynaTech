#include "DInstance.h"

Instance::Instance()
	: parent(NULL)
	, name("Instance")
{
}

Instance::~Instance()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}

	children.clear();
}

void Instance::removeChild(Instance* child)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] == child)
		{
			children.erase(children.begin() + i);
		}
	}
}

void Instance::setParent(Instance* instance)
{
	if (instance != parent)
	{
		if (instance->parent != NULL)
		{
			instance->parent->removeChild(this);
		}

		parent = instance;

		if (instance != NULL)
		{
			instance->addChild(this);
		}
	}
}

std::string Instance::getName()
{
	return name;
}

void Instance::setName(std::string newName)
{
	if (newName != name)
	{
		name = newName;
	}
}

void Instance::addChild(Instance* instance)
{
	children.push_back(instance);
}
