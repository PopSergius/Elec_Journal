#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "E_Journall.h"

using namespace std;

//Функція для виводу меню
int Menu() {
	int temp;
	cout << "\nОберіть режим:"
		<< "\n1. Додати студента."
		<< "\n2. Видалити студента."
		<< "\n3. Виставити оцінки та відвідуваність."
		<< "\n4. Вивести журнал."
		<< "\n5. Вивести відсоток відвідуваності"
		<< "\n0. Вийти з журналу."
		<< "\n => ";
	cin >> temp;
	return temp;
}
//Функція для додання студента
void AddStudent(E_Journall& Ej) {
	Ej.AddStudent();
}
//Функція для видалення студента
void DelStudent(E_Journall& Ej) {
	Ej.DelStudent();
}
//Функція для відвідуваності студента
void AttStudent(E_Journall& Ej) {
	cout << "\nДля коректного заповнення дотримуйтесь інструкції: "
		<< "\n'-' - студент відстуній"
		<< "\n'+' - Студент присутній, без оцінки"
		<< "\n'1-5' - Оцінка студента"
		<< "\nЯкщо студент був на парі та отримав оцінку '+' ставити не треба, тільки оцінку";
	Ej.AttStudent();
}
//Функція для виведення журналу
void ShowJournal(E_Journall& Ej) {
	int temp;
	string name;
	do {
		cout << "\nОберіть:"
			<< "\n1. Вивести весь журнал"
			<< "\n2. Вивести конкретного студента"
			<< "\n0. Повернутись до вибору режима"
			<< "\n => ";
		cin >> temp;
		switch (temp) {
		case 1: { Ej.PrintList(); } break;
		case 2: { Ej.PrintStudent(); } break;
		case 0: {} break;
		default: { cout << "\nВвели значення не зі списку!"; } break;
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
		default: { cout << "\nВвели значення не зі списку!"; } break;
		}
		system("cls");

	} while (temp);
	cout << "Вихід з програми...";
	Ej.WriteStudentFile();
	Ej.WriteAttFile();
}