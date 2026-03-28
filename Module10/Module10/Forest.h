#pragma once
#include <vector>

#include "Tree.h"

class Forest
{
public:
    Forest(const std::string& name) : _name(name) {}
    virtual ~Forest() = default;

    virtual void growUp(std::unique_ptr<Tree> tree) = 0;

    void cutAll()
    {
        _trees.clear();
        std::cout << "Forest \"" << _name << "\" was cleared\n";
    }

    void wind()
    {
        std::cout << "Forest \"" << _name << "\":\n";
        for (const auto& tree : _trees)
        {
            if (tree)
            {
                tree->wind();
            }
        }
    }

    const std::string& name() const { return _name; }

protected:
    void addTree(std::unique_ptr<Tree> tree, ForestTypes forestType)
    {
        if (!tree)
        {
            std::cerr << "Error: Attempted to add a null tree\n";
            return;
        }

        ForestTypes type = getForestType(tree->type());
        if (type == forestType)
        {
            std::cout << getTreeTypeName(tree->type()) << " Tree \"" << tree->name()
                << "\" was added to the " << getForestTypeName(forestType) << " Forest\n";

            _trees.push_back(std::move(tree));
        }
        else
        {
            std::cerr << "Error: Tree of type "
                << getTreeTypeName(tree->type())
                << " is not a " << getForestTypeName(forestType) << " Tree and cannot be added to the "
                << getForestTypeName(forestType) << " Forest\n";
        }
    }

    std::vector<std::unique_ptr<Tree>> _trees;
    std::string _name;
};
