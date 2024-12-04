// OOJL_LR3_Orlov_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

// Базовый класс
class Base {
public:
    virtual ~Base() { std::cout << "Base destroyed.\n"; }
    virtual void show() const {
        std::cout << "This is a Base object.\n";
    }
};

// Производный класс
class Derived : public Base {
public:
    ~Derived() override { std::cout << "Derived destroyed.\n"; }
    void show() const override {
        std::cout << "This is a Derived object.\n";
    }
};

// Функция для добавления объектов в хранилище
void add(std::vector<std::shared_ptr<Base>>& storage, std::shared_ptr<Base> item) {
    storage.push_back(item);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Инициализация генератора случайных чисел
    std::vector<std::shared_ptr<Base>> storage;

    // Создание случайного количества объектов
    for (int i = 0; i < 10; ++i) { // Создаем 10 объектов для примера
        int randomValue = std::rand();
        if (randomValue % 2 == 0) { // Четное число - создаем Base
            add(storage, std::make_shared<Base>());
        }
        else { // Нечетное число - создаем Derived
            add(storage, std::make_shared<Derived>());
        }
    }

    // Показать поведение каждого объекта в хранилище
    for (const auto& item : storage) {
        item->show();
    }

    // Умные указатели автоматически освободят ресурсы при выходе из области видимости

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
