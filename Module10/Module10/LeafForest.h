#pragma once
#include "Forest.h"

//Лиственный лес
class LeafForest : public Forest
{
public:
	LeafForest(const std::string& name) : Forest(name) {}

	void growUp(std::unique_ptr<Tree> tree) override
	{
		addTree(std::move(tree), ForestTypes::Leaf);
	}
};