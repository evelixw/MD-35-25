#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include "Tree.h"

class Forest {
private:
    std::vector<Tree> trees; 

public:

    Forest();

    Forest(const std::vector<Tree>& t);

    ~Forest();

    int getTreesNumber() const;

    void growUp(const std::string& name, TreeType type);

    void cutAll();

    Forest operator+(const Forest& other) const;

    void changeID(Tree& tree, int newID);

    void changeFirstTreeID(int newID);

    void printAllTrees() const;

    void windBlow() const;
};

#endif s
