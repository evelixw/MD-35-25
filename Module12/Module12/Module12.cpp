#include <iostream>
#include <string>
#include "Car.h"
#include "Garage.h"
#include "ServiceStation.h"

int main() {
    std::cout << "СТО и гаражи для автомобилей" << std::endl;

    std::cout << "\nСТО ДЛЯ ЛЕГКОВЫХ АВТОМОБИЛЕЙ" << std::endl;
    ServiceStation<PassengerCar> passengerStation;

    std::cout << "\nДобавляем машины на СТО (лимит 5)" << std::endl;
    passengerStation.AddCar(new PassengerCar("Toyota Camry"));
    passengerStation.AddCar(new PassengerCar("Honda Accord"));
    passengerStation.AddCar(new PassengerCar("BMW X5"));
    passengerStation.AddCar(new PassengerCar("Mercedes E-Class"));
    passengerStation.AddCar(new PassengerCar("Audi A6"));

    passengerStation.AddCar(new PassengerCar("Lexus RX"));

    std::cout << "\nСтатус СТО" << std::endl;
    std::cout << "На СТО ожидают ремонта: " << passengerStation.getWaitingCount() << " машин" << std::endl;

    std::cout << "\n Ремонт машин" << std::endl;
    passengerStation.RepairAll();

    passengerStation.DisplayGarage();


    std::cout << "\nСТО ДЛЯ ГРУЗОВЫХ АВТОМОБИЛЕЙ" << std::endl;
    ServiceStation<CargoCar> cargoStation;

    std::cout << "\nДобавляем грузовики на СТО (лимит 5) " << std::endl;
    cargoStation.AddCar(new CargoCar("Volvo FH16"));
    cargoStation.AddCar(new CargoCar("Scania R500"));
    cargoStation.AddCar(new CargoCar("MAN TGX"));
    cargoStation.AddCar(new CargoCar("DAF XF"));
    cargoStation.AddCar(new CargoCar("Mercedes Actros"));

    cargoStation.AddCar(new CargoCar("Kamaz 5490"));

    std::cout << "\nСтатус СТО" << std::endl;
    std::cout << "На СТО ожидают ремонта: " << cargoStation.getWaitingCount() << " грузовиков" << std::endl;

    std::cout << "\n Ремонт грузовиков" << std::endl;
    cargoStation.RepairAll();

    cargoStation.DisplayGarage();

    std::cout << "Все операции выполнены успешно!" << std::endl;
    std::cout << "  - Легковые автомобили отремонтированы: 5 шт." << std::endl;
    std::cout << "  - Грузовые автомобили отремонтированы: 5 шт." << std::endl;
    std::cout << "  - Все отремонтированные машины находятся в гаражах" << std::endl;



    return 0;
}