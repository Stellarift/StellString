#include <iostream>
#include <string>
using namespace std;

//задание 1, замена пробелов на табуляции
void task1() {
    cout << "задание 1: замена пробелов на табуляции" << endl;
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i] = '\t';
        }
    }

    cout << "Результат: " << str << endl << endl;
}

//задание 2, подсчет всего
void task2() {
    cout << "задание 2: подсчет символов" << endl;
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    int letters = 0, digits = 0, others = 0;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        //проверка на буквы
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') ||
            c == 'ё' || c == 'Ё') {
            letters++;
        }
        //проверка на цифры
        else if (c >= '0' && c <= '9') {
            digits++;
        }
        //остальные симловы
        else {
            others++;
        }
    }

    cout << "Буквы: " << letters << endl;
    cout << "Цифры: " << digits << endl;
    cout << "Остальные символы: " << others << endl << endl;
}

//задание 3, подсчет слов
void task3() {
    cout << "задание 3:подсчет слов " << endl;
    string sentence;
    cout << "Введите предложение: ";
    getline(cin, sentence);

    int count = 0;
    bool inWord = false;

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\t') {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
        else {
            inWord = false;
        }
    }

    cout << "Количество слов: " << count << endl << endl;
}

// задание 4, палиндром
void task4() {
    cout << "задание 4:проверка на палиндром" << endl;
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    //создание очищенной строки
    string cleaned;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (c == ' ' || c == '\t')
            continue;

        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
        //для кириллицы
        else if (c >= 'А' && c <= 'Я') {
            c = c + ('а' - 'А');
        }
        else if (c == 'Ё') {
            c = 'ё';
        }

        cleaned += c;
    }

    //проверка на палиндром
    bool isPalindrome = true;
    int len = cleaned.length();

    for (int i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Строка является палиндромом." << endl;
    }
    else {
        cout << "Строка не является палиндромом." << endl;
    }
    cout << endl;
}

//основ. программа
int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    do {
        cout << "------------------------------------" << endl;
        cout << "Выберите задание для выполнения:" << endl;
        cout << "1. Замена пробелов на табуляции" << endl;
        cout << "2. Подсчет букв, цифр и других символов" << endl;
        cout << "3. Подсчет слов в предложении" << endl;
        cout << "4. Проверка на палиндром" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore(); //очистка буфера обмена после ввода числа

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
            task4();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl << endl;
        }
    } while (choice != 0);

    return 0;
}
