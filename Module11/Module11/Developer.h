#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee {
public:
    Developer(const std::string& n) : Employee(n) {}

    ~Developer() override {
        std::cout << "Разработчик " << name << " завершил проект" << std::endl;
    }

    void writeCode() {
        std::cout << "Разработчик " << name << " пишет код" << std::endl;
    }
};

#endif 