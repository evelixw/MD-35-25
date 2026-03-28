#include <iostream>
#include <random>
#include <future>
#include <mutex>

std::mutex mtx;

int sum(int* p, int size)
{
    std::lock_guard<std::mutex> lock(mtx);

    int result = 0;

    if (p != nullptr && size > 0)
    {
        for (int i = 0; i < size; ++i)
            result += p[i];
    }

    return result;
}

int min(int* p, int size)
{
    std::lock_guard<std::mutex> lock(mtx);

    int result = 0;

    if (p != nullptr && size > 0)
    {
        result = p[0];
        for (int i = 1; i < size; ++i)
        {
            if (p[i] < result)
                result = p[i];
        }
    }

    return result;
}

int max(int* p, int size)
{
    std::lock_guard<std::mutex> lock(mtx);

    int result = 0;

    if (p != nullptr && size > 0)
    {
        result = p[0];
        for (int i = 1; i < size; ++i)
        {
            if (p[i] > result)
                result = p[i];
        }
    }

    return result;
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);

    const int size = 100;
    int arr[size] = {};
    std::cout << "Array:\n";
    for (int i = 0; i < size; ++i)
    {
        arr[i] = distr(gen);
        std::cout << i + 1 << ". " << arr[i] << std::endl;
    }

    std::future<int> f_sum = std::async(std::launch::async, sum, arr, size);
    std::future<int> f_min = std::async(std::launch::async, min, arr, size);
    std::future<int> f_max = std::async(std::launch::async, max, arr, size);

    std::cout << "Sum: " << f_sum.get() << std::endl;
    std::cout << "Min: " << f_min.get() << std::endl;
    std::cout << "Max: " << f_max.get() << std::endl;
}