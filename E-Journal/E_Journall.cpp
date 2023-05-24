#include "E_Journall.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <fstream>

using namespace std;

void E_Journall::AddStudent() {
	//��������� � ������ Student
	Student* newStudent = new Student;
	cout << "\n������ ��'� ��������: ";
	cin >> newStudent->name;
	index++;
	newStudent->index = index;
	newStudent->next = nullptr;

	if (Shead == nullptr && Ahead == nullptr) {
		Shead = newStudent;
		return;
	}

	Student* temp = Shead;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newStudent;

}

void E_Journall::DelStudent() {
	//��������� � ������ Student
	string name;
	cout << "\n������ ��'� �������� ����� ����� ��������: ";
	cin >> name;
	int k = 0;

	Student* temp = Shead;
	Student* prevision = nullptr;
	while (temp != nullptr) {
		if (temp->name == name) {
			prevision->next = temp->next;
			delete temp;
			break;
		}
		prevision = temp;
		temp = temp->next;
	}

	temp = Shead;

}

void E_Journall::AttStudent() {

	Student* temp = Shead;
	Attendance* newDateAtt = new Attendance;
	//��������� �������� � ������ Attendence � �������� 0
	cout << "\n������ ���� ������: ";
	cin >> newDateAtt->att;
	newDateAtt->index = 0;
	newDateAtt->next = nullptr;
	if (Ahead == nullptr)
		Ahead = newDateAtt;
	else {
		Attendance* ChekAtt = Ahead;

		while (ChekAtt->next != nullptr) {
			ChekAtt = ChekAtt->next;
		}

		ChekAtt->next = newDateAtt;
	}
	//��������� �������� � ������ Attendence
	while (temp != nullptr) {
		Attendance* newAtt = new Attendance;
		cout << '\n' << temp->name << " ����������: ";
		newAtt->index = temp->index;
		cin >> newAtt->att;
		newAtt->next = nullptr;

		Attendance* Att = Ahead;
		while (Att->next != nullptr) {
			Att = Att->next;
		}
		temp = temp->next;
		Att->next = newAtt;
	}

}

void E_Journall::ProcentAtt() {
	//��������� ������� �����������
	Student* Stemp = Shead;
	Attendance* Atemp = Ahead;
	int k = 0;
	while (Atemp != nullptr) {
		if (Atemp->index == 0) { k++; } // ��������� ������� ���
		Atemp = Atemp->next;
	}
	while (Stemp != nullptr) {
		double  k_student = 0;
		Atemp = Ahead;
		while (Atemp != nullptr) {
			if (Stemp->index == Atemp->index && Atemp->att != "-") {
				k_student++;
			}
			Atemp = Atemp->next;
		}
		k_student = k_student / k * 100;
		cout << Stemp->name << " ��� �������� �� " << k_student << "% ���\n";
		Stemp = Stemp->next;
	}
	system("pause");
}

void E_Journall::PrintStudent() {
	string name;
	cout << "\n������ ��'� �������� ����� ����� �������: ";
	cin >> name;
	Student* current = Shead;
	while (current != nullptr) {
		if (current->name == name)
		{
			Attendance* temp = Ahead;
			cout << '\n' << current->index << ". " << current->name;
			cout << '\n' << setw(9) << "����:";
			while (temp != nullptr) {
				if (temp->index == 0)
					cout << setw(6) << temp->att;
				temp = temp->next;
			} 

			temp = Ahead;
			cout << '\n' << setw(10) << "������: ";
			while (temp != nullptr) {
				if (temp->index == current->index) {
					cout << setw(5) << temp->att << setw(5);
				}
				temp = temp->next;
			}
			cout << "\n";
		}
		current = current->next;
	}
}

void E_Journall::PrintList() {

	Student* current = Shead;
	Attendance* temp = Ahead;
	cout << setw(15) << "\n�������� ||";
	while (temp != nullptr) {
		if (temp->index == 0)
			cout << setw(6) << temp->att << setw(4) << "||";
		temp = temp->next;
	}
	while (current != nullptr) {
		temp = Ahead;
		cout << '\n' << setw(6) << current->name << setw(5) << "||";

		while (temp != nullptr) {
			if (temp->index == current->index) {
				cout << setw(4) << temp->att << setw(6) << "||";
			}
			temp = temp->next;
		}

		current = current->next;
	}
	cout << endl;

}

void E_Journall::ReadStudentFile() {	
		ifstream fin("Student.txt");

		int ind;
		string name;

		while (fin >> ind >> name)
		{
			Student* newElem = new Student;
			newElem->index = ind;
			newElem->name = name;
			newElem->next = nullptr;
			if (Shead == nullptr) {
				Shead = newElem;
			}
			else {
				Student* current = Shead;
				while (current->next != nullptr) { current = current->next; }

				current->next = newElem;
			}
		}
		index = ind;

		fin.close();	
}

void E_Journall::WriteStudentFile() {
	ofstream out("Student.txt");
	Student* current = Shead;

	while (current != nullptr) {
		out << current->index << " " << current->name << endl;
		current = current->next;
	}

	out.close();
}

void E_Journall::ReadAttFile() {
	ifstream fin("Att.txt");

	int ind;
	string att;
	while (fin >> ind >> att)
	{
		Attendance* newElem = new Attendance;
		newElem->index = ind;
		newElem->att = att;
		newElem->next = nullptr;
		if (Ahead == nullptr) {
			Ahead = newElem;
		} else{
			Attendance* current = Ahead;
			while (current->next != nullptr) { current = current->next; }

			current->next = newElem;
		}
	}

	fin.close();
}

void E_Journall::WriteAttFile() {
	ofstream out("Att.txt");
	Attendance* current = Ahead;

	while (current != nullptr) {
		out << current->index << " " << current->att << " ";
		current = current->next;
	}
	cout << endl;

	out.close();
}