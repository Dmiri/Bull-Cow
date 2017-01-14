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
	//�������� ���� ����.
	for (int x = 1; x > 0;) {
		
		//��������� ���������� �����.
		for (int i = 0; i < hidden.size(); i++) {
			hidden[i] = rand() % 10;
			for (int j = 0; j < i; j++) {
				if (hidden[i] == hidden[j]) {
					i--;
				}
			}
		}
		 
		//����������. ����� ������.
		cout << "\t\t\tBull and Cow\n\t������� ����:"
			<< "\n1. ��������� ���������� ������������� �����. ����� � ����� �� �����������."
			<< "\n2. �� ��������� ��� ����� �������, ����� ���� �������� ����������� �����."
			<< "\n3. �� ������ ���� �������, ��������� ��� �������� ���-��� ��� ������������"
			<< "\n����� ������� ����������� ����� � ������ ��������, � ������ - ����������"
			<< "\n\"�����\" � \"�����\":"
			<< "\n\"����\" - ��� �� ����� ������ �����, ������������ ������� ���������� ��������� "
			<< "\n� ������� ����������� �����;"
			<< "\n\"������\" - ��� �� ����� ������ �����, ������� ������������ � ���������� �����,"
			<< "\n�� ��������� � ������ �����, (� ������ �������, �� ������ �������).\n"
			<< "\n\n��� ������� ���������� �����:\n";
		//���� �������� ���� ������� ��������� �� ������ 0 - ����������.
		bool flag = true;
		unsigned int number = 0;
		do {
			int resRead = 0;
			cout << endl;
			resRead = readValue(&variation);
			if (resRead) {
				cout << "����������� ��������, ��������� �������.";
			}
			else
			{
				number++;
				if (!comparison(&hidden, &variation))
				{
					flag = false;
					cout << "\t\t\t������!!!" << "\n\t\t���������� �������:  " << number << endl;
				}
			}

		
		} while (flag);
		x = menu();
	}
	return 0;
}

int menu() {
	cout << "\n\n\t\tMenu :\n  1. ��� ������ ������� 'Esc'\n  2. ��� ����������� ������� ����� ������ �������";
	int c = _getch();
	if (c == 27) return 0;
	system("cls");
	return 1;
}

int comparison(vector<int> *pHidden, vector<int> *pVariation) {
	//��������� ������ �� 2 ������� � ����������� �� �������� �������� ����.
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
	//��������� ������ �� ������ � ������� ���������� ���������
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