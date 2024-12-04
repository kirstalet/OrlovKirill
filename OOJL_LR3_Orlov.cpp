// OOJL_LR3_Orlov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <memory>

// Базовый класс - Деталь
class Detail {
protected:
    Detail() { std::cout << "Detail created.\n"; }
public:
    virtual ~Detail() { std::cout << "Detail destroyed.\n"; }
    virtual void show() const = 0;
};

// Производный класс - Сборка
class Assembly : public Detail {
protected:
    Assembly() { std::cout << "Assembly created.\n"; }
public:
    ~Assembly() override { std::cout << "Assembly destroyed.\n"; }

    void show() const override {
        std::cout << "This is an Assembly.\n";
    }

    // Фабричный метод для создания объектов
    static std::shared_ptr<Assembly> create() {
        return std::shared_ptr<Assembly>(new Assembly());
    }
};

// Другой производный класс - Деталь (например)
class Component : public Detail {
protected:
    Component() { std::cout << "Component created.\n"; }
public:
    ~Component() override { std::cout << "Component destroyed.\n"; }

    void show() const override {
        std::cout << "This is a Component.\n";
    }

    // Фабричный метод для создания объектов
    static std::shared_ptr<Component> create() {
        return std::shared_ptr<Component>(new Component());
    }
};

// Шаблонная дружественная функция для хранения объектов в векторе
template <typename T>
void storeInVector(std::vector<std::shared_ptr<Detail>>& storage, const std::shared_ptr<T>& item) {
    storage.push_back(item);
}

int main() {
    std::vector<std::shared_ptr<Detail>> storage;

    // Создаем объекты через фабричные методы
    auto assembly = Assembly::create();
    auto component = Component::create();

    // Храним их в векторе
    storeInVector(storage, assembly);
    storeInVector(storage, component);

    // Отображаем содержимое хранилища
    for (const auto& item : storage) {
        item->show();
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
