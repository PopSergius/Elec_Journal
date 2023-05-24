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
	//додавання студента в журнал
	void AddStudent();
	//видалення студента з журналу
	void DelStudent();
	//виставлення відвідуваності студентів
	void AttStudent();
	//кількість відвідуваності студентів
	void ProcentAtt();

	//вивід конкретного студента
	void PrintStudent();
	//вивід всього журналу
	void PrintList();

	//Зчитування студентів з файлу
	void ReadStudentFile();
	//Запис студентів у файл
	void WriteStudentFile();

	//Зчитування оцінок студента
	void ReadAttFile();
	//Запис оцінок студентів
	void WriteAttFile();
};