#pragma once
#include <string>
#include <memory>
#include <iostream>

enum class TreeType {
    Oak,
    Pine,
    Maple,
    Birch,
    Cedar,
    Spruce
};

inline std::string getTreeTypeName(TreeType type) {
    switch (type) {
    case TreeType::Oak: return "Oak";
    case TreeType::Pine: return "Pine";
    case TreeType::Maple: return "Maple";
    case TreeType::Birch: return "Birch";
    case TreeType::Cedar: return "Cedar";
    case TreeType::Spruce: return "Spruce";
    default: return "Unknown";
    }
}

enum class ForestTypes {
    Leaf,      
    Conifer    
};

inline std::string getForestTypeName(ForestTypes type) {
    switch (type) {
    case ForestTypes::Leaf: return "Leaf";
    case ForestTypes::Conifer: return "Conifer";
    default: return "Unknown";
    }
}

inline ForestTypes getForestType(TreeType treeType) {
    switch (treeType) {
    case TreeType::Oak:
    case TreeType::Maple:
    case TreeType::Birch:
        return ForestTypes::Leaf;
    case TreeType::Pine:
    case TreeType::Cedar:
    case TreeType::Spruce:
        return ForestTypes::Conifer;
    default:
        return ForestTypes::Leaf;
    }
}