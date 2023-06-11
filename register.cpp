#include <iostream>
#include <string>
#include <vector> // библиотека для векторных массивов 

using namespace std;

// Вектор для хранения имен пользователей
vector<string> usernames;

// Вектор для хранения паролей пользователей
vector<string> passwords;

// Функция для проверки, существует ли пользователь с данным именем
bool userExists(string username) {
    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == username) {
            return true;
        }
    }

    return false;
}

// Функция для регистрации нового пользователя
void registerUser() {
    string username, password;

    // Запрашиваем у пользователя имя и пароль
    cout << "--- Регистрация нового пользователя ---" << endl;
    cout << "Введите имя пользователя: ";
    cin >> username;

    // Проверяем, не занято ли уже указанное имя
    if (userExists(username)) {
        cout << "Это имя пользователя уже занято. Выберите другое." << endl;
        return;
    }

    cout << "Введите пароль: ";
    cin >> password;

    // Заносим нового пользователя в векторы
    usernames.push_back(username);
    passwords.push_back(password);
    cout << "Регистрация успешно завершена." << endl;
}

// Функция для авторизации пользователя
void authorize() {
    string username, password;

    // Запрашиваем у пользователя имя и пароль
    cout << "--- Авторизация пользователя ---" << endl;
    cout << "Введите имя пользователя: ";
    cin >> username;

    // Проверяем, существует ли пользователь с таким именем
    int userIndex = -1;
    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == username) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        cout << "Пользователь с таким именем не найден." << endl;
        return;
    }

    // Проверяем, совпадает ли пароль
    cout << "Введите пароль: ";
    cin >> password;
    if (password != passwords[userIndex]) {
        cout << "Неверный пароль." << endl;
        return;
    }

    cout << "Авторизация успешно завершена." << endl;
}

// Функция для вывода списка всех пользователей
void listUsers() {
    cout << "--- Список всех пользователей ---" << endl;
    for (int i = 0; i < usernames.size(); i++) {
        cout << "Имя: " << usernames[i] << endl;
    }
}

// Основной цикл программы
int main() {
    while (true) {
        cout << "--- Главное меню ---" << endl;
        cout << "1. Регистрация нового пользователя" << endl;
        cout << "2. Авторизация пользователя" << endl;
        cout << "3. Просмотр списка пользователей" << endl;
        cout << "4. Выход" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authorize();
                break;
            case 3:
                listUsers();
                break;
            case 4:
                return 0;
            default:
                cout << "Неверный выбор." << endl;
        }
    }
}
