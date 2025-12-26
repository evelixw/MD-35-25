#include <iostream>
#include <string>
using namespace std;

enum class TrafficLight { RED, YELLOW, GREEN, UNKNOWN };

void printLight(TrafficLight light) {
    switch (light) {
    case TrafficLight::RED:
        cout << "Red" << endl;
        break;
    case TrafficLight::YELLOW:
        cout << "Yellow" << endl;
        break;
    case TrafficLight::GREEN:
        cout << "Green" << endl;
        break;
    case TrafficLight::UNKNOWN:
        cout << "Unknown" << endl;
        break;
    }
}

int main() {
    TrafficLight light = TrafficLight::UNKNOWN;
    printLight(light);

    string input;
    cout << "Введите цвет светофора (red, yellow, green): ";
    cin >> input;

    TrafficLight userLight = TrafficLight::UNKNOWN;

    if (input == "red") {
        userLight = TrafficLight::RED;
    }
    else if (input == "yellow") {
        userLight = TrafficLight::YELLOW;
    }
    else if (input == "green") {
        userLight = TrafficLight::GREEN;
    }
    else {
        cout << "Некорректный ввод! Будет использован цвет по умолчанию." << endl;
    }

    printLight(userLight);

    return 0;
}