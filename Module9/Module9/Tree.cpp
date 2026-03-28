#include "Tree.h"
#include "Forest.h"
#include <iostream>

int Tree::totalCount = 0;

Tree::Tree(const std::string& n, TreeType t) : name(n), type(t) {
    totalCount++;
    id = totalCount;
    std::cout << "Создано дерево: " << name << " (ID: " << id
        << ", тип: " << treeTypeToString(type) << ")" << std::endl;
}

Tree::Tree(const Tree& other) : name(other.name), type(other.type) {
    totalCount++;
    id = totalCount;
    std::cout << "Скопировано дерево: " << name << " (ID: " << id
        << ", тип: " << treeTypeToString(type) << ")" << std::endl;
}

Tree::~Tree() {
    std::cout << "Уничтожено дерево: " << name << " (ID: " << id << ")" << std::endl;
}

void Tree::wind() const {
    std::cout << "Дерево \"" << name << "\" (ID: " << id << ") шумит на ветру" << std::endl;
}

int Tree::getID() const {
    return id;
}

std::string Tree::getName() const {
    return name;
}

TreeType Tree::getType() const {
    return type;
}

int Tree::getTotalCount() {
    return totalCount;
}

std::string treeTypeToString(TreeType type) {
    switch (type) {
    case OAK: return "Дуб";
    case PINE: return "Сосна";
    case BIRCH: return "Берёза";
    case MAPLE: return "Клён";
    case SPRUCE: return "Ель";
    default: return "Неизвестно";
    }
}