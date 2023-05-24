#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "E_Journall.h"

using namespace std;

//������� ��� ������ ����
int Menu() {
	int temp;
	cout << "\n������ �����:"
		<< "\n1. ������ ��������."
		<< "\n2. �������� ��������."
		<< "\n3. ��������� ������ �� �����������."
		<< "\n4. ������� ������."
		<< "\n5. ������� ������� �����������"
		<< "\n0. ����� � �������."
		<< "\n => ";
	cin >> temp;
	return temp;
}
//������� ��� ������� ��������
void AddStudent(E_Journall& Ej) {
	Ej.AddStudent();
}
//������� ��� ��������� ��������
void DelStudent(E_Journall& Ej) {
	Ej.DelStudent();
}
//������� ��� ����������� ��������
void AttStudent(E_Journall& Ej) {
	cout << "\n��� ���������� ���������� ������������ ����������: "
		<< "\n'-' - ������� �������"
		<< "\n'+' - ������� ��������, ��� ������"
		<< "\n'1-5' - ������ ��������"
		<< "\n���� ������� ��� �� ��� �� ������� ������ '+' ������� �� �����, ����� ������";
	Ej.AttStudent();
}
//������� ��� ��������� �������
void ShowJournal(E_Journall& Ej) {
	int temp;
	string name;
	do {
		cout << "\n������:"
			<< "\n1. ������� ���� ������"
			<< "\n2. ������� ����������� ��������"
			<< "\n0. ����������� �� ������ ������"
			<< "\n => ";
		cin >> temp;
		switch (temp) {
		case 1: { Ej.PrintList(); } break;
		case 2: { Ej.PrintStudent(); } break;
		case 0: {} break;
		default: { cout << "\n����� �������� �� � ������!"; } break;
		}
		system("pause"); system("cls");
	} while (temp);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int temp;
	E_Journall Ej;

	Ej.ReadStudentFile();
	Ej.ReadAttFile();

	do {

		temp = Menu();
		switch (temp) {
		case 1: { AddStudent(Ej); } break;
		case 2: { DelStudent(Ej); }break;
		case 3: { AttStudent(Ej); } break;
		case 4: { ShowJournal(Ej); } break;
		case 5: { Ej.ProcentAtt(); } break;
		default: { cout << "\n����� �������� �� � ������!"; } break;
		}
		system("cls");

	} while (temp);
	cout << "����� � ��������...";
	Ej.WriteStudentFile();
	Ej.WriteAttFile();
}