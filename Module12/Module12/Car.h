#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
protected:
    std::string name;
    bool isRepaired;

public:
    Car(const std::string& n) : name(n), isRepaired(false) {}

    virtual ~Car() {}

    void Repair() {
        isRepaired = true;
    }

    bool getIsRepaired() const {
        return isRepaired;
    }

    std::string getName() const {
        return name;
    }

    virtual std::string getType() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.getType() << " \"" << car.name << "\" - ";
        if (car.isRepaired) {
            os << "отремонтирован";
        }
        else {
            os << "не отремонтирован";
        }
        return os;
    }
};

class PassengerCar : public Car {
public:
    PassengerCar(const std::string& n) : Car(n) {}

    std::string getType() const override {
        return "Легковой автомобиль";
    }
};

class CargoCar : public Car {
public:
    CargoCar(const std::string& n) : Car(n) {}

    std::string getType() const override {
        return "Грузовой автомобиль";
    }
};

#endif 