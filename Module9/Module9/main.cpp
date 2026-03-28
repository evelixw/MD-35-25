#include <iostream>
#include "Forest.h"
#include "Tree.h"

int main() {
    std::cout << " ДЕМОНСТРАЦИЯ РАБОТЫ " << std::endl;
    std::cout << "\nСоздаём первый лес " << std::endl;
    Forest forest1;

    forest1.growUp("Старый дуб", OAK);
    forest1.growUp("Сосна-великан", PINE);
    forest1.growUp("Берёзка", BIRCH);

    std::cout << "\nПервый лес " << std::endl;
    forest1.printAllTrees();

    std::cout << "\nВетер в первом лесу " << std::endl;
    forest1.windBlow();

    std::cout << "\nСоздаём второй лес " << std::endl;
    Forest forest2;

    forest2.growUp("Клён японский", MAPLE);
    forest2.growUp("Ель голубая", SPRUCE);

    std::cout << "\nВторой лес" << std::endl;
    forest2.printAllTrees();

    std::cout << "\nСлияние лесов" << std::endl;
    Forest forest3 = forest1 + forest2;
    forest3.printAllTrees();

    std::cout << "\nИзменяем ID первого дерева" << std::endl;
    forest3.changeFirstTreeID(999);
    forest3.printAllTrees();

    std::cout << "\nВетер в объединённом лесу" << std::endl;
    forest3.windBlow();

    std::cout << "\nВырубка леса" << std::endl;
    forest3.cutAll();
    forest3.printAllTrees();

    std::cout << "\n Статистика " << std::endl;
    std::cout << "Всего создано деревьев: " << Tree::getTotalCount() << std::endl;

    std::cout << "\n КОНЕЦ ПРОГРАММЫ " << std::endl;

    return 0;
}