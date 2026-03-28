#include <iostream>
#include <functional>
#include <memory>
#include <vector>

#include "Tree.h"
#include "Forest.h"
#include "LeafForest.h"
#include "ConiferForest.h"
#include "TreeClasses.h"

int main()
{
    std::unique_ptr<Forest> pLeafForest = std::make_unique<LeafForest>("Leaf Forest");
    std::unique_ptr<Forest> pConiferForest = std::make_unique<ConiferForest>("Conifer Forest");

    std::cout << "\nAdding trees to Leaf Forest " << std::endl;
    pLeafForest->growUp(std::make_unique<Oak>("Old Oak"));
    pLeafForest->growUp(std::make_unique<Maple>("Japanese Maple"));
    pLeafForest->growUp(std::make_unique<Birch>("Silver Birch"));
    pLeafForest->growUp(std::make_unique<Pine>("Pine Tree"));

    std::cout << "\n Adding trees to Conifer Forest " << std::endl;
    pConiferForest->growUp(std::make_unique<Pine>("Scots Pine"));
    pConiferForest->growUp(std::make_unique<Cedar>("Atlas Cedar"));
    pConiferForest->growUp(std::make_unique<Maple>("Maple Tree"));

    std::cout << "\n Wind in forests " << std::endl;
    pLeafForest->wind();
    pConiferForest->wind();

    std::cout << "\nSTATISTICS " << std::endl;
    std::vector<std::pair<std::string, std::function<int()>>> treesCount =
    {
        { "Oak", &Oak::getObjectsCount },
        { "Pine", &Pine::getObjectsCount },
        { "Maple", &Maple::getObjectsCount },
        { "Birch", &Birch::getObjectsCount },
        { "Cedar", &Cedar::getObjectsCount }
    };

    for (const auto& t : treesCount)
    {
        std::cout << "Number of " << t.first << " trees: " << t.second() << std::endl;
    }

    std::cout << "Total trees created: " << Tree::getTotalCount() << std::endl;

    std::cout << "\nCutting down forests " << std::endl;
    pLeafForest->cutAll();
    pConiferForest->cutAll();

    std::cout << "\n END OF PROGRAM " << std::endl;

    return 0;
}