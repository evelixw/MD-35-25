#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "Operating System:" << std::endl;

#if defined(_WIN32) || defined(_WIN64)
    std::cout << "  Название: Windows" << std::endl;

#ifdef _WIN64
    std::cout << "  Архитектура: 64-bit" << std::endl;
#else
    std::cout << "  Архитектура: 32-bit" << std::endl;
#endif

#elif defined(__APPLE__) || defined(__MACH__)
    std::cout << "  Название: macOS" << std::endl;

#ifdef __x86_64__
    std::cout << "  Архитектура: x86_64" << std::endl;
#elif defined(__arm64__) || defined(__aarch64__)
    std::cout << "  Архитектура: ARM64" << std::endl;
#endif

#elif defined(__linux__)
    std::cout << "  Название: Linux" << std::endl;

#ifdef __x86_64__
    std::cout << "  Архитектура: x86_64" << std::endl;
#elif defined(__i386__)
    std::cout << "  Архитектура: x86" << std::endl;
#elif defined(__arm__) || defined(__aarch64__)
    std::cout << "  Архитектура: ARM" << std::endl;
#endif

#else
    std::cout << "  Название: Неизвестная ОС" << std::endl;

#endif

    std::cout << std::endl << "Compiler:" << std::endl;

#if defined(_MSC_VER)
    std::cout << "  Название: MSVC" << std::endl;
    std::cout << "  Версия: " << _MSC_VER << std::endl;
#elif defined(__clang__)
    std::cout << "  Название: Clang" << std::endl;
    std::cout << "  Версия: " << __clang_major__ << "." << __clang_minor__ << std::endl;
#elif defined(__GNUC__)
    std::cout << "  Название: GCC" << std::endl;
    std::cout << "  Версия: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
#else
    std::cout << "  Название: Неизвестный компилятор" << std::endl;
#endif

    return 0;
}