#include <iostream>
#include <cmath>
using namespace std;

// Оголошення функцій
void task1();
void task2();
void task3();
void menu();

bool isValidDouble(double &value);
bool isValidInt(int &value, bool positiveOnly = false);

int main() {
    menu();
    return 0;
}

// Реалізація меню
void menu() {
    while (true) {
        cout << "\nОберіть завдання:\n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "3 - Завдання 3\n";
        cout << "4 - Вихід\n";
        cout << "Ваш вибір: ";

        int choice;
        if (!isValidInt(choice)) {
            cout << "Помилка введення. Спробуйте знову.\n";
            continue;
        }

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                cout << "Вихід з програми.\n";
                return;
            default:
                cout << "Некоректний вибір. Спробуйте знову.\n";
        }
    }
}

// Завдання 1: Обчислити кількість точок у заданій області
void task1() {
    int n;
    cout << "\nВведіть кількість точок: ";
    if (!isValidInt(n, true)) {
        cout << "Кількість точок має бути натуральним числом.\n";
        return;
    }

    int countInside = 0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cout << "Введіть координати точки " << i + 1 << " (x y): ";
        if (!isValidDouble(x) || !isValidDouble(y)) {
            cout << "Помилка введення. Координати мають бути дійсними числами.\n";
            return;
        }

        if ((x >= 0 && y >= 0 && x * x + y * y <= 1) || (x >= 0 && y <= 0 && y >= -x)) {
            ++countInside;
        }
    }

    cout << "Кількість точок у фігурі: " << countInside << "\n";
}

// Завдання 2: Обчислити ряд та вивести непарні елементи
void task2() {
    int n;
    double x, sum, xs;

    cout << "\nВведіть x: ";
    if (!isValidDouble(x)) {
        cout << "Помилка введення. x має бути дійсним числом.\n";
        return;
    }

    cout << "Введіть n: ";
    if (!isValidInt(n, true)) {
        cout << "Помилка введення. n має бути натуральним числом.\n";
        return;
    }

    sum = x;
    xs = 1;
    for (int j = 1; j <= n; j++) {
        xs /= x;
        sum += xs;

        if (j % 2 != 0) {
            cout << "Непарний елемент " << j << ": " << xs << endl;
        }
    }

    cout << "Сума ряду: " << sum << endl;
}

// Завдання 3: Продемонструвати збіжність ряду
void task3() {
    double x, u, sum, e = 1E-20;

    cout << "\nx (x > 1): ";
    if (!isValidDouble(x) || x <= 1) {
        cout << "Помилка введення. x має бути дійсним числом більше 1.\n";
        return;
    }

    u = 1 / x;
    sum = u;
    while (fabs(u) >= e) {
        cout << "Елемент ряду: " << u << endl;
        x *= x;
        u = 1 / x;
        sum += u;
    }

    cout << "Останній елемент: " << u << endl;
    cout << "Сума ряду: " << sum << endl;
}

// Перевірка введення дійсного числа
bool isValidDouble(double &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// Перевірка введення цілого числа
bool isValidInt(int &value, bool positiveOnly) {
    cin >> value;
    if (cin.fail() || (positiveOnly && value <= 0)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
