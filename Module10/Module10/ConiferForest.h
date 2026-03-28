#pragma once
#include "Forest.h"

//Хвойный лес
class ConiferForest : public Forest
{
public:
	ConiferForest(const std::string& name) : Forest(name) {}

	void growUp(std::unique_ptr<Tree> tree) override
	{
		addTree(std::move(tree), ForestTypes::Conifer);
	}
};