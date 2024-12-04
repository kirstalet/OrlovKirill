// OOJL_LR1_Orlov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Book {
public:
    enum class Type {
        Fiction,
        Technical
    };

    Book(const std::string& author, const std::string& title, Type type)
        : author_(author), title_(title), type_(type) {
        if (author.empty() || title.empty()) {
            throw std::invalid_argument("Author and title cannot be empty");
        }
    }

    void display() const {
        std::cout << "Author: " << author_ << ", Title: " << title_
            << ", Type: " << (type_ == Type::Fiction ? "Fiction" : "Technical") << std::endl;
    }

private:
    std::string author_;
    std::string title_;
    Type type_;
};

class Library {
public:
    void addBook(const Book& book) {
        books_.push_back(book);
    }

    void displayBooks() const {
        for (const auto& book : books_) {
            book.display();
        }
    }

private:
    std::vector<Book> books_;
};

Book::Type getTypeFromUser() {
    int type;
    std::cout << "Enter book type (0 for Fiction, 1 for Technical): ";
    std::cin >> type;

    if (type == 0) {
        return Book::Type::Fiction;
    }
    else if (type == 1) {
        return Book::Type::Technical;
    }
    else {
        throw std::invalid_argument("Invalid book type entered");
    }
}

int main() {
    try {
        Library library;
        char choice;

        do {
            std::string author;
            std::string title;
            Book::Type type;

            std::cout << "Enter author name: ";
            std::cin.ignore(); // Игнорируем оставшийся символ новой строки в буфере
            std::getline(std::cin, author);

            std::cout << "Enter book title: ";
            std::getline(std::cin, title);

            try {
                type = getTypeFromUser();
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << ". Please try again." << std::endl;
                continue; // Перезапрашиваем ввод в случае ошибки
            }

            library.addBook(Book(author, title, type));

            std::cout << "Do you want to add another book? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        std::cout << "Library contains the following books:" << std::endl;
        library.displayBooks();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
