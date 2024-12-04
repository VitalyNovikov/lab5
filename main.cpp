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
    double x;

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

    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = pow(i, 3) * exp(2 * i + 1) / tgamma(i + 1); // tgamma(i + 1) обчислює факторіал i
        sum += term;

        // Для парних варіантів — кожен третій елемент
        if (i % 2 == 0 && i % 3 == 0) {
            cout << "Кожен третій елемент (парний варіант): " << term << endl;
        }
        // Для непарних варіантів — кожен четвертий елемент
        if (i % 2 != 0 && i % 4 == 0) {
            cout << "Кожен четвертий елемент (непарний варіант): " << term << endl;
        }
    }

    cout << "Сума ряду: " << sum << endl;
}


// Функція обчислення факторіала
double factorial(int x) {
    if (x <= 1) return 1;
    double res = 1;
    for (int i = 2; i <= x; i++)
        res *= i;
    return res;
}

// Завдання 3: Продемонструвати збіжність ряду
void task3() {
    double x, u, sum, e;
    int n;

    u = exp(3);
    sum = u;
    n = 2;
    e = 1E-05;
    
    cout << "\nВведіть e (малу величину, наприклад, 1E-5): ";
    if (!isValidDouble(x)) {
        cout << "Помилка введення. n має бути дійсним числом.\n";
        return;
    }

    while (fabs(u) >= e) {
        cout << "Елемент ряду: " << u << endl;
        u = pow(n, 3) * exp(2 * n + 1) / factorial(n);
        sum += u;
        n++;
        if (n > 100) break;
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