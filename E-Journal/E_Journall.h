#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Student {
	string name;
	int index;
	Student* next;
};

struct Attendance {
	string att;
	int index;
	Attendance* next;
};

class E_Journall {
private:
	int index = 0;
	string date;
	Student* Shead;
	Attendance* Ahead;
public:

	E_Journall() { Shead = nullptr; Ahead = nullptr; }
	//��������� �������� � ������
	void AddStudent();
	//��������� �������� � �������
	void DelStudent();
	//����������� ����������� ��������
	void AttStudent();
	//������� ����������� ��������
	void ProcentAtt();

	//���� ����������� ��������
	void PrintStudent();
	//���� ������ �������
	void PrintList();

	//���������� �������� � �����
	void ReadStudentFile();
	//����� �������� � ����
	void WriteStudentFile();

	//���������� ������ ��������
	void ReadAttFile();
	//����� ������ ��������
	void WriteAttFile();
};