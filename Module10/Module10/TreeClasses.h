#pragma once
#include "Tree.h"
#include <iostream>


class Tree {
protected:
    std::string _name;
    TreeType _type;
    static int _totalCount;

public:
    Tree(const std::string& name, TreeType type) : _name(name), _type(type) {
        _totalCount++;
    }

    virtual ~Tree() {
        _totalCount--;
    }


    virtual void wind() const = 0;

    std::string name() const { return _name; }
    TreeType type() const { return _type; }

    static int getTotalCount() { return _totalCount; }
};

int Tree::_totalCount = 0;


class Oak : public Tree {
private:
    static int _objectsCount;

public:
    Oak(const std::string& name) : Tree(name, TreeType::Oak) {
        _objectsCount++;
    }

    ~Oak() override {
        _objectsCount--;
    }

    void wind() const override {
        std::cout << "  Oak \"" << _name << "\" rustles heavily: WHOOSH-WHOOSH!" << std::endl;
    }

    static int getObjectsCount() { return _objectsCount; }
};

int Oak::_objectsCount = 0;

class Pine : public Tree {
private:
    static int _objectsCount;

public:
    Pine(const std::string& name) : Tree(name, TreeType::Pine) {
        _objectsCount++;
    }

    ~Pine() override {
        _objectsCount--;
    }

    void wind() const override {
        std::cout << "  Pine \"" << _name << "\" whispers: Sh-sh-sh-sh!" << std::endl;
    }

    static int getObjectsCount() { return _objectsCount; }
};

int Pine::_objectsCount = 0;

class Maple : public Tree {
private:
    static int _objectsCount;

public:
    Maple(const std::string& name) : Tree(name, TreeType::Maple) {
        _objectsCount++;
    }

    ~Maple() override {
        _objectsCount--;
    }

    void wind() const override {
        std::cout << "  Maple \"" << _name << "\" rustles gently: Rustle-rustle!" << std::endl;
    }

    static int getObjectsCount() { return _objectsCount; }
};

int Maple::_objectsCount = 0;

class Birch : public Tree {
private:
    static int _objectsCount;

public:
    Birch(const std::string& name) : Tree(name, TreeType::Birch) {
        _objectsCount++;
    }

    ~Birch() override {
        _objectsCount--;
    }

    void wind() const override {
        std::cout << "  Birch \"" << _name << "\" rings: Ding-ding-ding!" << std::endl;
    }

    static int getObjectsCount() { return _objectsCount; }
};

int Birch::_objectsCount = 0;

class Cedar : public Tree {
private:
    static int _objectsCount;

public:
    Cedar(const std::string& name) : Tree(name, TreeType::Cedar) {
        _objectsCount++;
    }

    ~Cedar() override {
        _objectsCount--;
    }

    void wind() const override {
        std::cout << "  Cedar \"" << _name << "\" sways majestically: Sh-sh-sh-woosh!" << std::endl;
    }

    static int getObjectsCount() { return _objectsCount; }
};

int Cedar::_objectsCount = 0;