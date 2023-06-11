#include <iostream>
#include <fstream> //библиотека для работы с файлами
#include <string> // библиотека для работы со строками
using namespace std;

class User { // создаём класс юзер с параметарми имени и пароля
    public:
        string name;
        string password;
};

class Auth { // создаём класс системы регистарции
    private:
        User user;
    public:
        void registerUser() { // создаём функцию регистрации пользователя
            cout << "Enter your name: ";
            cin >> user.name; // Запрашивают имя пользователя
            cout << "Enter your password: ";
            cin >> user.password;
            
            ofstream file("data.txt", ios::app); // создаём файл, куда будут записываться ранее вводимы пароли и логины
            if(file.is_open()) { // если файл открывается, то в него записываются данные
                file << user.name << " " << user.password << endl;
                file.close(); // закрытие файла
                
                cout << "User registration successful" << endl; // регистрация успешна
            } else {
                cout << "Could not open file" << endl; // файл не смог открыться
            }
        }
        
        bool loginUser() { // создаём функцию, в которой хрнаится или истина, или ложь
            string name, password;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your password: ";
            cin >> password;
            
            ifstream file("data.txt"); // открываес файл
            if(file.is_open()) { // если файл открыт, то...
                string file_name, file_password;
                while(file >> file_name >> file_password) { // пока в файле есть логины и пароль
                    if(name == file_name && password == file_password) { // если введенный пароль и логин совпадают, то...
                        file.close(); // закрыть файл
                        return true; // возвращщаем истинное значение, то есть логин и пароль верен
                    }
                }
                file.close(); //  закрываем файл
                return false; // возвращаем ложное значение, то есть привденные данные неверны
            } else { // иначе 
                cout << "Could not open file" << endl; 
                return false; // возвращаем ложное значение, потому что файл схлопнулся
            }
        }
};

int main() { // без этой функции код, как человек без мозга 
    Auth auth;
    int choice; // создаём переменную выбора, в зависимости от значения которого, будут вызыватьсся соотвествующие функции
    bool isLoggedIn = false; // записываем в переменну "вошёл в систему" значение ложь
    
    do { // цикл-инструктор
        cout << "Welcome to the system" << endl; // Выводим в консоли команды, которые пользователь должен выбрать
        cout << "1. Register" << endl; // кстати, endl - это такая штука, которая делает переход на новую строку, позволяя делать красивое оформление информации для пользователя 
        cout << "2. Login" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) { // прикольная вещь, чтобы в зависимости от принимаемого значения выполнять соотвествующие операции
            case 1:
                auth.registerUser(); // вызываем функцию регистрации пользовтеля
                break;
            case 2:
                isLoggedIn = auth.loginUser(); // вызываем функцию входа в соотвествии с заданным ранее ложным значением
                if(isLoggedIn) { // если значение оказалось верным, то..
                    cout << "Login successful" << endl; // Вход завершен успешно
                } else {
                    cout << "Login failed" << endl; // вход неудачен
                }
                break;
            case 0:
                break;
            default: // штука(тип переменной), которая принимает любые значения, обрабатывает их и выдает базу в видн проверки на дурачка или слепца
                cout << "Invalid choice" << endl; // неверный выбор
        }
    } while(choice != 0); // всё это дело выполняется пока выбор не равен 0, то есть выходу
    
    return 0; // программа прекращает успешно работу, все довольны, все заргестрированы
}
