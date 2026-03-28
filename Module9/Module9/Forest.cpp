#include "Forest.h"
#include <iostream>

Forest::Forest() {
    std::cout << "Создан пустой лес" << std::endl;
}

Forest::Forest(const std::vector<Tree>& t) : trees(t) {
    std::cout << "Создан лес с " << trees.size() << " деревьями" << std::endl;
}

Forest::~Forest() {
    std::cout << "Лес уничтожен. В лесу было " << trees.size() << " деревьев" << std::endl;
}

int Forest::getTreesNumber() const {
    return trees.size();
}

void Forest::growUp(const std::string& name, TreeType type) {
    trees.push_back(Tree(name, type));
    std::cout << "В лес добавлено дерево. Теперь в лесу " << trees.size() << " деревьев" << std::endl;
}

void Forest::cutAll() {
    std::cout << "Вырубаем все деревья в лесу..." << std::endl;
    trees.clear();
    std::cout << "Лес очищен. Теперь в лесу " << trees.size() << " деревьев" << std::endl;
}

Forest Forest::operator+(const Forest& other) const {
    Forest newForest;

    for (const auto& tree : trees) {
        newForest.trees.push_back(tree);
    }

    for (const auto& tree : other.trees) {
        newForest.trees.push_back(tree);
    }
    std::cout << "Леса слились! В новом лесу " << newForest.trees.size() << " деревьев" << std::endl;
    return newForest;
}

void Forest::changeID(Tree& tree, int newID) {
    std::cout << "Изменяем ID дерева \"" << tree.name << "\" с " << tree.id << " на " << newID << std::endl;
    tree.id = newID;
}

void Forest::changeFirstTreeID(int newID) {
    if (!trees.empty()) {
        changeID(trees[0], newID);
    }
    else {
        std::cout << "Лес пуст, нечего изменять!" << std::endl;
    }
}

void Forest::printAllTrees() const {
    if (trees.empty()) {
        std::cout << "Лес пуст" << std::endl;
        return;
    }
    std::cout << "Деревья в лесу:" << std::endl;
    for (const auto& tree : trees) {
        std::cout << "  - ";
        tree.wind();
    }
}

void Forest::windBlow() const {
    if (trees.empty()) {
        std::cout << "В лесу нет деревьев, ветру нечем шуметь" << std::endl;
        return;
    }
    std::cout << "Подул ветер! Все деревья шумят:" << std::endl;
    for (const auto& tree : trees) {
        std::cout << "  - ";
        tree.wind();
    }
}