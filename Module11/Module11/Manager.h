#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    Manager(const std::string& n) : Employee(n) {}

    ~Manager() override {
        std::cout << "Менеджер " << name << " покинул пост" << std::endl;
    }

    void manageTeam() {
        std::cout << "Менеджер " << name << " управляет командой" << std::endl;
    }
};

#endif 