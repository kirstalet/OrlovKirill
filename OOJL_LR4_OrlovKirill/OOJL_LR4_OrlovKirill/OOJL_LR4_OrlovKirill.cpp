// OOJL_LR4_OrlovKirill.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>

using namespace std;

class Person {
public:
    virtual void introduce() const = 0; // Чисто виртуальная функция
    virtual ~Person() {} // Виртуальный деструктор
};

class Preschooler : public Person {
public:
    void introduce() const override {
        cout << "Я дошкольник." << endl;
    }
};

class Schoolboy : public Person {
public:
    void introduce() const override {
        cout << "Я школьник." << endl;
    }
};

class Student : public Person {
public:
    void introduce() const override {
        cout << "Я студент." << endl;
    }
};

class Working : public Person {
public:
    void introduce() const override {
        cout << "Я работающий." << endl;
    }
};

// Шаблонный класс для массива указателей на объекты произвольного класса
template<typename T>
class PointerArray {
private:
    vector<T*> arr;
public:
    ~PointerArray() { // Деструктор освобождает память
        for (T* ptr : arr) {
            delete ptr;
        }
    }

    void add(T* item) { // Метод добавления элемента в массив
        if (!item) throw runtime_error("Cannot add null pointer to the array");
        arr.push_back(item);
    }

    T& operator[](size_t index) { // Перегрузка оператора []
        if (index >= arr.size()) throw out_of_range("Index out of range");
        return *arr[index];
    }

    size_t size() const { return arr.size(); } // Возвращает размер массива
};

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        PointerArray<Person> people;

        people.add(new Preschooler());
        people.add(new Schoolboy());
        people.add(new Student());
        people.add(new Working());

        for (size_t i = 0; i < people.size(); ++i) {
            people[i].introduce();
        }

        // Пример выброса runtime_error
        people.add(nullptr); // для исключения

    }
    catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Общая ошибка: " << e.what() << endl;
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
