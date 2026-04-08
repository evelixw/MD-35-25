#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int player1() {
    return rand() % 11 - 5;
}

int player2() {
    return rand() % 11 - 5;
}

int main() {
    srand(time(0));

    int counter = 0;
    int moveNumber = 0;
    bool needPositive = true;

    cout << "Игра началась!" << endl;
    cout << "Начальный счёт: " << counter << endl << endl;

    while (moveNumber < 100) {
        int moveValue;
        int currentPlayer;

        moveNumber++;
        currentPlayer = (moveNumber % 2 == 1) ? 1 : 2;

        do {
            if (currentPlayer == 1) {
                moveValue = player1();
            }
            else {
                moveValue = player2();
            }

            if (needPositive && moveValue > 0) {
                break;
            }
            else if (!needPositive && moveValue < 0) {
                break;
            }

        } while (true);

        counter += moveValue;

        cout << "Ход " << moveNumber << ": Игрок " << currentPlayer
            << " сгенерировал " << moveValue
            << " | Счётчик: " << counter << endl;

        if (counter > 50) {
            cout << "\nПОБЕДИТЕЛЬ: Игрок " << currentPlayer << "!" << endl;
            cout << "Счётчик превысил 50 после " << moveNumber << " ходов!" << endl;
            return 0;
        }

        needPositive = !needPositive;
    }

    cout << "\nничья!" << endl;
    cout << "После 100 ходов счётчик остановился на " << counter << endl;

    return 0;
}