#include <iostream>
#include <stdio.h>
#include <fstream> // библиотека для работы с файлами
#include <ctime> // для работы с теущим временем

#define CRT_SECURE_NO_WARNINGS // от раздражающих ошибок, из-за которых хочется уничтожить визуал студио

using namespace std;

time_t seconds = time(NULL); // чекаем текущее время
tm* timeinfo = localtime(&seconds); // преобразует секунды в текущую дату 

//C:\check расположение всех файлов

int userIDInt, pinCodeInt, cardBallance; // создаём переменные айди пользотвеля, его пин код  и баланс на карте

void OpenFiles() // функция открытия файла и записи в него 
{
	ifstream pinCode;
	pinCode.open("pinCode.txt"); // эти три строчки создают в общем-то файл, где будет храниться пин-код юзера
	pinCode >> pinCodeInt;

	ifstream cardBallanceFile;
	cardBallanceFile.open("cardBallance.txt"); // а в этих четырех строчках образвуется файл, где будет храниться баланс юзера
	cardBallanceFile >> cardBallance;
	cardBallanceFile.close();

	ifstream userID;
	userID.open("userID.txt"); // айди юзера
	userID >> userIDInt;
}



//тут мы задаем значения для проверки без работы с файлами

//userIDInt = 12345678;
//pinCodeInt = 1234;
int cardStatus = 1;
int mobileBallance = 100;
int JKHcheque = 500;
int newPinCode;
int oldPinCode;
int JKHchoise;

int inputUserID;
int inputPinCode;


int loginning() // создаем фунцкию входа
{
	cout << "Insert you user ID" << "\n"; // просят ввести айди юзера
	cin >> inputUserID;
	while (inputUserID != userIDInt) // пока айди изера не совпадает с существуюими в файле данными, юзера продолжат колоть фразой user ID is not correct
	{
		cin >> inputUserID;
		if (inputUserID == userIDInt) { cout << "user ID is correct" << "\n"; break; } // но если юзеру посчастливилось правильно ввести айди, то его гостеприимно встречают фразой user ID is correct
		else cout << "user ID is not correct" << "\n";
	}

	if (inputUserID != userIDInt) return 1; 

	int trying;

	if (cardStatus == 1) // Если статус карты равен 1, -то всё хорошо
	{
		cout << "Insert you pin code" << "\n";
		cin >> inputPinCode;
		if (inputPinCode == pinCodeInt) { cout << "pin code is correct" << "\n"; return 1;} 
		else
		{
			inputPinCode = 0;
			cout << "pin code is not correct, please, try again. Attempts left: 2" << "\n"; // но если вдргу чуваку не повезло с цифоркой или он солдат удачи, то просят ввести код по новой, но попыток осталось только две
			cin >> inputPinCode;
			if (inputPinCode == pinCodeInt) { cout << "pin code is correct" << "\n"; return 1;}
			else
			{
				inputPinCode = 0;
				cout << "pin code is not correct, please, try again. Attempts left: 1" << "\n"; // ой, одна попытка! Почему же это?
				cin >> inputPinCode;
				if (inputPinCode == pinCodeInt) { cout << "pin code is correct" << "\n"; return 1; }
				else
				{
					inputPinCode = 0;
					cout << "bye!" << "\n"; // Пока.
					return 0;
				}
			}
		}
	}

	cout << "Welcome!" << "\n"; //ПРИВЕТ!!!!!!
}

int userChange; // Юзер - вфыбор 
int nalMoney; // наличка

int main()
{
	OpenFiles(); // открываем файл, начинаем вести ззаписи

	std::ofstream Logs;
	Logs.open("logs.txt", std::ofstream::app);

	if (loginning() == 0) return 0;  // если вдруг оказался пук, то закрываем програамму

	Logs << "User in system" << "\n"; // выбери таблекту: синюю или красную 

	while (true) // пока значение истинное...
	{
		cout << "top up your account - 1, withdraw from the account - 2, top up your mobile - 3, change pin code - 4, services JKH - 5, leave from terminal - 6" << "\n"; // выбираем таблетку
		cin >> userChange;
		switch (userChange) // таблетка выбирается 
		{
		case 1: // таблетка выбрана, судьба кошелька решена 
			cout << "insert a sum(above 100)" << "\n";
			cin >> nalMoney;
			if (nalMoney >= 100) // как и любой другой норамльный банкомат, он требует, чтобы подавали ему челобитную не меньше 100. Ну, денег много не бывает
			{
				cardBallance += nalMoney; //тепербь на карте больше денег
				cout << "money deposited, current balance: " << cardBallance << "\n";
				Logs << "money deposited: " << nalMoney << " " << asctime(timeinfo) << "\n"; // в логах записываем подробности шалости с кошельком и денюжкой
			}
			else cout << "wrong number, please try again" << "\n"; // иначе, если банкомат выплянул твои жалкие 50 рублей, то ты инвалид
			nalMoney = 0;
			break; // все фигня, давай по новой

		case 2:
			cout << "insert a sum(above 100)" << "\n";
			cin >> nalMoney;
			if (nalMoney >= 100 && nalMoney <= cardBallance) // опять та же история, как и любой другой нормальный банкомат, он отдаст тебе только не меньше 100 рублей
			{
				cardBallance -= nalMoney; // отнимаем 
				cout << "money withdrawn, current balance: " << cardBallance << "\n";
				Logs << "money withdrawn: " << nalMoney << " " << asctime(timeinfo) << "\n";
			}
			else cout << "wrong number, please try again" << "\n";
			nalMoney = 0;
			break;

		case 3:
			cout << "insert a sum(above 100)" << "\n";
			cin >> nalMoney;
			if (nalMoney >= 100) // Кладём деньги на телефон. Нет, не прямо на телефон. 
			{
				mobileBallance += nalMoney; //прибавляем баланс телефона
				cout << "the mobile account has been replenished, the balance is on the account: " << mobileBallance << "\n";
				Logs << "Money deposited on mobile ballance" << asctime(timeinfo) << "\n";
			}
			else cout << "wrong number, please try again" << "\n";
			nalMoney = 0;
			break;

		case 4:
			cout << "insert old pin code"; // Это что, прикол про Альцгеймера?!

			cin >> oldPinCode;

			if (oldPinCode == pinCodeInt) // запрашиваем старый пароль, сравниваем и выполняем следюущие фунцкции...
			{
				cout << "insert new pin code";
				cin >> newPinCode;
				if (newPinCode > 9999 or newPinCode < 0) cout << "wrong pin code, please insert up to 4 characters and retry" << "\n"; break; // Ну, как и любой другой пин-код, он не должен содержать карикатуры о величии банкоматов, а только натуральные числа не выше 9999
				pinCodeInt = newPinCode;
				cout << "pin code has been changed!" << "\n";
				Logs << "Pin code has been changed on: " << pinCodeInt << " " << asctime(timeinfo) << "\n"; // запись в файл подробностей о новом пин-коде
			}
			else cout << "wrong old pin code, please try again" << "\n"; // О, нет! А что я делаю? Пин-код? О, чёрт, я забыл свой пин-код!
				break;

		case 5:
			cout << "you JKH cheque is: " << JKHcheque << " can you pay? (1 - yes, 0 - no)" << "\n"; // Любой другой нормальный банк будет впаривать услуги 
			cin >> JKHchoise;
			if (JKHchoise == 1 or JKHchoise == 0)
			{
				if (JKHchoise == 1)
				{
					if (JKHcheque <= cardBallance) { cardBallance -= JKHcheque; JKHcheque = 0; cout << "you has pay of all JKH cheque! You card ballance: " << cardBallance << "\n"; Logs << "Payed for all JKH cheques" << " " << asctime(timeinfo) << "\n"; }
					else cout << "Insufficient funds! Please try again" << "\n";
					break;
				}
				break;

			}
			else cout << "Uncorrect answer! Please try again" << "\n";
			break;

		case 6:
			cout << "Thanks for using me!" << "\n";
			Logs << "User leave at system" << " " << asctime(timeinfo) << "\n";
			return 0;
			break;

		default:
			cout << "Please, select a number from the list!" << "\n";
				break;
		}
	}
	ofstream cardBallanceFile;
	cardBallanceFile.open("cardBallance.txt", ios::trunc | ios::out);
	cardBallanceFile << cardBallance; // закрываемся, сворачиваемся, банкомат больше не трогаем.
}
