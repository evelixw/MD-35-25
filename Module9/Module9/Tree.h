#pragma once
#ifndef TREE_H
#define TREE_H

#include <string>

enum TreeType {
    OAK,        // Дуб
    PINE,       // Сосна
    BIRCH,      // Берёза
    MAPLE,      // Клён
    SPRUCE      // Ель
};

std::string treeTypeToString(TreeType type);

class Forest;

class Tree {
private:
    std::string name; 
    TreeType type; 
    int id;
    static int totalCount; 

public:
    Tree(const std::string& n, TreeType t);

    Tree(const Tree& other);

    virtual ~Tree();

    void wind() const;

    int getID() const;
    std::string getName() const;
    TreeType getType() const;

    static int getTotalCount();

    friend void Forest::changeID(Tree& tree, int newID);
};

#endif // TREE_H