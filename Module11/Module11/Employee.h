#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;

public:
    Employee(const std::string& n) : name(n) {}


    virtual ~Employee() {
        std::cout << "Сотрудник " << name << " уволен" << std::endl;
    }

    std::string getName() const {
        return name;
    }
};

#endif 