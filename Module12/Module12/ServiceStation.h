#ifndef SERVICE_STATION_H
#define SERVICE_STATION_H

#include <iostream>
#include <vector>
#include <memory>
#include "Car.h"
#include "Garage.h"

template<typename T>
class ServiceStation {
private:
    static const int MAX_CARS = 5;
    std::vector<T*> waitingCars;
    Garage<T> garage;        

public:
    ServiceStation() {
        std::cout << "Создана СТО для " << getTypeName() << " (максимум " << MAX_CARS << " машин)" << std::endl;
    }

    ~ServiceStation() {
        for (T* car : waitingCars) {
            delete car;
        }
    }

    void AddCar(T* car) {
        if (waitingCars.size() < MAX_CARS) {
            waitingCars.push_back(car);
            std::cout << "  Машина \"" << car->getName() << "\" добавлена на СТО. "
                << "Очередь: " << waitingCars.size() << "/" << MAX_CARS << std::endl;
        }
        else {
            std::cout << "  ОШИБКА: СТО переполнена! Машина \"" << car->getName()
                << "\" не может быть добавлена (лимит " << MAX_CARS << ")" << std::endl;
            delete car; 
        }
    }

    void RepairAll() {
        if (waitingCars.empty()) {
            std::cout << "  На СТО нет машин для ремонта" << std::endl;
            return;
        }

        std::cout << "\n  Начинаем ремонт " << waitingCars.size() << " машин на СТО:" << std::endl;

        for (T* car : waitingCars) {
            std::cout << "    До ремонта: " << *car << std::endl;
            car->Repair();
            std::cout << "    После ремонта: " << *car << std::endl;

            garage.AddToGarage(car);
        }

        waitingCars.clear();
        std::cout << "  СТО очищена, все машины отремонтированы и перемещены в гараж" << std::endl;
    }

    void DisplayGarage() const {
        std::cout << "\n  Содержимое гаража (" << getTypeName() << "):" << std::endl;
        garage.DisplayAll();
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

    int getWaitingCount() const {
        return waitingCars.size();
    }
};

#endif 