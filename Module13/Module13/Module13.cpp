#define _USE_MATH_DEFINES

#include <iostream>
#include <windows.h>
#include <functional>
#include <cmath>
#include <stdexcept>

class InvalidLogArgument : public std::runtime_error
{
public:
    InvalidLogArgument() : std::runtime_error("Ошибка: Аргумент логарифма должен быть больше нуля.") {}
};

class InvalidRadiusArgument : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Ошибка: Радиус круга не может быть отрицательным.";
    }
};

void calculate(double a, double b, std::function<double(double, double)> operation)
{
    try
    {
        double result = operation(a, b);
        std::cout << "Результат операции: " << result << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Caught invalid_argument: " << e.what() << std::endl;
    }
    catch (const std::domain_error& e)
    {
        std::cerr << "Caught domain_error: " << e.what() << std::endl;
    }
    catch (const InvalidLogArgument& e)
    {
        std::cerr << "Caught InvalidLogArgument: " << e.what() << std::endl;
    }
    catch (const InvalidRadiusArgument& e)
    {
        std::cerr << "Caught InvalidRadiusArgument: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Неизвестная ошибка: " << e.what() << std::endl;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // Лямбда для деления
    auto divide = [](double a, double b)
        {
            if (b == 0) throw std::invalid_argument("Деление на ноль!");
            return a / b;
        };

    // Лямбда для извлечения корня 
    auto squareRoot = [](double a, double)
        {
            if (a < 0) throw std::domain_error("Отрицательное число под корнем!");
            return std::sqrt(a);
        };

    // Лямбда для логарифма
    auto logarithm = [](double a, double b)
        {
            if (a <= 0) throw InvalidLogArgument();
            return std::log(a);
        };

    // Лямбда для площади круга (a - радиус)
    auto circleArea = [](double r, double)
        {
            if (r < 0) throw InvalidRadiusArgument();
            return M_PI * r * r;
        };


    std::cout << "--- Тест деления ---" << std::endl;
    calculate(10, 2, divide);
    calculate(10, 0, divide);

    std::cout << "\n--- Тест корня ---" << std::endl;
    calculate(16, 0, squareRoot);
    calculate(-4, 0, squareRoot);

    std::cout << "\n--- Тест логарифма ---" << std::endl;
    calculate(std::exp(1), 0, logarithm);
    calculate(-1, 0, logarithm);

    std::cout << "\n--- Тест площади круга ---" << std::endl;
    calculate(5, 0, circleArea);
    calculate(-3, 0, circleArea);
}