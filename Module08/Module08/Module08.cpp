#include <iostream>
#include <cstring> 

class Book {
private:
    char* title;
    char* author;
    int year;
    char* ISBN;

public:
    Book(const char* t, const char* a, int y, const char* isbn) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        year = y;

        ISBN = new char[strlen(isbn) + 1];
        strcpy(ISBN, isbn);
    }

    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        year = other.year;

        ISBN = new char[strlen(other.ISBN) + 1];
        strcpy(ISBN, other.ISBN);
    }

    ~Book() {
        delete[] title;
        delete[] author;
        delete[] ISBN;
    }

    const char* getTitle() const {
        return title;
    }

    const char* getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    const char* getISBN() const {
        return ISBN;
    }

    void printInfo() const {
        std::cout << "Название: " << title << std::endl;
        std::cout << "Автор: " << author << std::endl;
        std::cout << "Год издания: " << year << std::endl;
        std::cout << "ISBN: " << ISBN << std::endl;
    }
};

int main() {
    std::cout << " Создаём книгу 1 " << std::endl;
    Book book1("Война и мир", "Лев Толстой", 1869, "978-5-17-098765-4");
    book1.printInfo();

    std::cout << "\n Тестируем геттеры " << std::endl;
    std::cout << "Название (через геттер): " << book1.getTitle() << std::endl;
    std::cout << "Автор (через геттер): " << book1.getAuthor() << std::endl;
    std::cout << "Год (через геттер): " << book1.getYear() << std::endl;
    std::cout << "ISBN (через геттер): " << book1.getISBN() << std::endl;

    std::cout << "\nСоздаём книгу 2" << std::endl;
    Book book2("Преступление и наказание", "Фёдор Достоевский", 1866, "978-5-17-123456-7");
    book2.printInfo();

    std::cout << "\n Копируем книгу 1 (конструктор копирования) " << std::endl;
    Book book3(book1);
    book3.printInfo();

    std::cout << "\nПоказываем, что копия независима " << std::endl;
    std::cout << "Оригинал (книга 1): " << book1.getTitle() << std::endl;
    std::cout << "Копия (книга 3): " << book3.getTitle() << std::endl;

    std::cout << "\nКопируем книгу 2 " << std::endl;
    Book book4(book2);
    book4.printInfo();

    return 0;
}