#include <iostream>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Developer.h"

int main() {

    std::vector<Employee*> employees;


    employees.push_back(new Manager("Иван Петров"));
    employees.push_back(new Developer("Алексей Смирнов"));
    employees.push_back(new Manager("Елена Соколова"));
    employees.push_back(new Developer("Дмитрий Иванов"));
    employees.push_back(new Developer("Мария Кузнецова"));

    std::cout << "\n Выполняем обязанности сотрудников" << std::endl;

    for (Employee* emp : employees) {
        Manager* manager = dynamic_cast<Manager*>(emp);
        if (manager) {
            manager->manageTeam();
            continue;
        }

        Developer* developer = dynamic_cast<Developer*>(emp);
        if (developer) {
            developer->writeCode();
            continue;
        }

        std::cout << "Неизвестный тип сотрудника" << std::endl;
    }

    std::cout << "\n Увольняем сотрудников " << std::endl;
    for (Employee* emp : employees) {
        delete emp;
    }


    return 0;
}