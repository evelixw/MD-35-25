#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include <vector>
#include "Car.h"

template<typename T>
class Garage {
private:
    std::vector<T*> cars;

public:
    Garage() {
        std::cout << "Создан гараж для " << getTypeName() << std::endl;
    }

    ~Garage() {
        for (T* car : cars) {
            delete car;
        }
    }

    void AddToGarage(T* car) {
        if (car->getIsRepaired()) {
            cars.push_back(car);
            std::cout << "  Машина \"" << car->getName() << "\" помещена в гараж" << std::endl;
        }
        else {
            std::cout << "  Ошибка: машина \"" << car->getName() << "\" не отремонтирована!" << std::endl;
            delete car; 
        }
    }

    void DisplayAll() const {
        if (cars.empty()) {
            std::cout << "  Гараж пуст" << std::endl;
            return;
        }

        std::cout << "Машины в гараже (" << getTypeName() << "):" << std::endl;
        for (size_t i = 0; i < cars.size(); i++) {
            std::cout << "  " << i + 1 << ". " << *cars[i] << std::endl;
        }
    }

    std::string getTypeName() const {
        if (typeid(T) == typeid(PassengerCar)) {
            return "легковых автомобилей";
        }
        else if (typeid(T) == typeid(CargoCar)) {
            return "грузовых автомобилей";
        }
        return "автомобилей";
    }

    int getSize() const {
        return cars.size();
    }
};

#endif 