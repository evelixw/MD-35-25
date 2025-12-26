#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Введите первое число (a): " << endl;
    cin >> a;
    cout << "Введите второе число (b): " << endl;
    cin >> b;

    cout << "Все операции" << endl;;

    cout << "sizeof(a) = " << sizeof(a) << " байт" << endl;;
    cout << "sizeof(b) = " << sizeof(b) << " байт" << endl;

    cout << "Арифметические операции:" << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;

    cout << "Логические операции:" << endl;
    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;

    cout << "Побитовые операции:" << endl;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~a = " << (~a) << endl;
    cout << "a << 2 = " << (a << 2) << endl;
    cout << "b >> 1 = " << (b >> 1) << endl;

    return 0;
}