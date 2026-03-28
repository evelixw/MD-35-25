#include <iostream>
#include <vector>
#include <memory>  //unique_ptr

//ЗАДАЧА 2

int findMax(const int* arr, int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// ЗАДАЧА 3
void swap(int* a, int* b) {
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

// ЗАДАЧА 5 
void consume(std::unique_ptr<int> p) {
    std::cout << "    Значение до увеличения: " << *p << std::endl;
    (*p)++;  
    std::cout << "    Значение после увеличения: " << *p << std::endl;
}


int main() {

    // ЗАДАЧА 1 
    std::cout << " ЗАДАЧА 1 " << std::endl;
    std::cout << "Динамический массив" << std::endl;

    int N;
    std::cout << "Введите размер массива: ";
    std::cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    std::cout << "Массив: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //  ЗАДАЧА 2 
    std::cout << "\n ЗАДАЧА 2 " << std::endl;
    std::cout << "Поиск максимального элемента" << std::endl;

    int max = findMax(arr, N);
    std::cout << "Максимальный элемент: " << max << std::endl;

    delete[] arr;

    //  ЗАДАЧА 3 
    std::cout << "\n ЗАДАЧА 3" << std::endl;
    std::cout << "Обмен значений через указатели" << std::endl;

    int x, y;
    std::cout << "Введите два числа: ";
    std::cin >> x >> y;

    std::cout << "До обмена: x = " << x << ", y = " << y << std::endl;

    swap(&x, &y);  

    std::cout << "После обмена: x = " << x << ", y = " << y << std::endl;

    //  ЗАДАЧА 4 
    std::cout << "\n ЗАДАЧА 4 " << std::endl;
    std::cout << "Вектор и среднее арифметическое" << std::endl;

    std::vector<int> numbers;
    int num;

    std::cout << "Введите числа (0 для завершения):" << std::endl;

    while (true) {
        std::cin >> num;
        if (num == 0) {
            break;
        }
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "Числа не были введены" << std::endl;
    }
    else {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            sum += numbers[i];
        }

        double average = (double)sum / numbers.size();

        std::cout << "Среднее арифметическое: " << average << std::endl;
    }

    //  ЗАДАЧА 5 
    std::cout << "\n ЗАДАЧА 5 " << std::endl;
    std::cout << "unique_ptr" << std::endl;

    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    std::cout << "Создан unique_ptr со значением 10" << std::endl;
    std::cout << "Передаём в функцию consume:" << std::endl;

    consume(std::move(ptr));

    std::cout << "После вызова функции ptr пуст" << std::endl;

    return 0;
}