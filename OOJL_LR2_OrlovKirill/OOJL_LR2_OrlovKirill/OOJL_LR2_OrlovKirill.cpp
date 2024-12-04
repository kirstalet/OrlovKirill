// OOJL_LR2_OrlovKirill.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;
public:
    void getdata() {

        std::cout << "Enter title: ";
        std::cin >> title;

        std::cout << "Enter ";
        std::getline(std::cin, title);
        std::cout << "price: ";
        std::cin >> price;
        std::cin.ignore();
    }
    void putdata() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        std::cout << "Enter sales for the last three months:" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "Month " << i + 1 << ": $";
            std::cin >> sales[i];
        }
    }
    void putdata() const {
        std::cout << "Sales for the last three months:" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "Month " << i + 1 << ": $" << sales[i] << std::endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
        Sales::getdata();
    }
    void putdata() const {
        Publication::putdata();
        std::cout << "Page Count: " << pageCount << std::endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
private:
    float playTime;
public:
    void getdata() {
        Publication::getdata();
        std::cout << "Enter play time in minutes: ";
        std::cin >> playTime;
        Sales::getdata();
    }
    void putdata() const {
        Publication::putdata();
        std::cout << "Play Time: " << playTime << " minutes" << std::endl;
        Sales::putdata();
    }
};

int main() {
    Book book;
    Tape tape;

    std::string data;
    std::string data_1;
    std::string ndata;
    std::string ndata_1;


    std::cout << "Enter data for book: ";
    std::cin >> data;
    book.getdata();

    std::cout << "nEnter data for tape: ";
    std::cin >> data_1;
    tape.getdata();

    std::cout << "nData for book: ";
    std::cin >> ndata;
    book.putdata();

    std::cout << "nData for tape: ";
    std::cin >> ndata_1;
    tape.putdata();

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
