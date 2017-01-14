#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <ctime>

using namespace std;

int menu();
int comparison(vector<int> *pHidden, vector<int> *pVariation);
int readValue(vector<int> *pVariation);

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));
	const int size = 4;
	vector<int> hidden(size);
	vector<int> variation(size);
	//основной цикл игры.
	for (int x = 1; x > 0;) {
		
		//генерация случайного числа.
		for (int i = 0; i < hidden.size(); i++) {
			hidden[i] = rand() % 10;
			for (int j = 0; j < i; j++) {
				if (hidden[i] == hidden[j]) {
					i--;
				}
			}
		}
		 
		//Вступление. Текст правил.
		cout << "\t\t\tBull and Cow\n\tПравила игры:"
			<< "\n1. Компьютер загадывает четырёхзначное число. Цифры в числе не повторяются."
			<< "\n2. Вы пытаетесь это число угадать, вводя свои варианты загаданного числа."
			<< "\n3. На каждую вашу попытку, компьютер Вам сообщает кое-что про соответствие"
			<< "\nмежду цифрами загаданного числа и вашего варианта, а именно - количество"
			<< "\n\"быков\" и \"коров\":"
			<< "\n\"Быки\" - это те цифры вашего числа, расположение которых поразрядно совпадает "
			<< "\nс цифрами загаданного числа;"
			<< "\n\"Коровы\" - это те цифры вашего числа, которые присутствуют в загаданном числе,"
			<< "\nно находятся в другом месте, (в другом разряде, на другой позиции).\n"
			<< "\n\nВаш вариант загаданого числа:\n";
		//цикл работает пока функция сравнения не вернет 0 - совпадение.
		bool flag = true;
		unsigned int number = 0;
		do {
			int resRead = 0;
			cout << endl;
			resRead = readValue(&variation);
			if (resRead) {
				cout << "Некоректное значение, повторите попытку.";
			}
			else
			{
				number++;
				if (!comparison(&hidden, &variation))
				{
					flag = false;
					cout << "\t\t\tПобеда!!!" << "\n\t\tКоличество попыток:  " << number << endl;
				}
			}

		
		} while (flag);
		x = menu();
	}
	return 0;
}

int menu() {
	cout << "\n\n\t\tMenu :\n  1. Для выхода нажмите 'Esc'\n  2. Для продолжения нажмите любую другую клавишу";
	int c = _getch();
	if (c == 27) return 0;
	system("cls");
	return 1;
}

int comparison(vector<int> *pHidden, vector<int> *pVariation) {
	//принимает ссылки на 2 вектора и сравнивеает их согласно правилам игры.
	int bull = 0, cow = 0;
	for (int i = 0; i < (*pHidden).size(); i++) {
		if ((*pHidden)[i] == (*pVariation)[i]) bull++;
		else {
			for (int j = 0; j < (*pVariation).size(); j++) {
				if (i == j) continue;
				if ((*pHidden)[i] == (*pVariation)[j]) cow++;
			}
		}
	}
	if (bull == (*pHidden).size()) {
		return 0;
	}
	cout << "Bull = " << bull << "\tCow = " << cow;
	return 1;
}

int readValue(vector<int> *pVariation) {
	//принимает ссылку на вектор в который необходимо заполнить
	string svalue;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> svalue;
	if (!cin) {
		return 1;
	}
	if (svalue.length() != pVariation->size()) {
		return 1;
	}
	char temp;
	for (int i = 0; i < pVariation->size(); i++) {
		temp = svalue[i];
		for (int j = 0; j < i; j++) {
			if (temp == svalue[j]) {
				return 2;
			}
		}
		(*pVariation)[i] = atoi(&temp);
	}
	return 0;
}