#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "Files.h"
#include "Professors.h"
#include "Students.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int mode;

	do
	{
		cout << "�������� �����: " << endl;
		cout << "1. ����� �������������" << endl;
		cout << "2. ����� ��������" << endl;
		cout << "(��� ������ �� ��������� ������� 0)" << endl << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(mode);
			if ((mode < 0) || (mode > 2)) cout << "������! ��������� ������� ��������." << endl;
		} while ((mode < 0) || (mode > 2));

		system("cls");

		switch (mode)
		{
		case 1:  ProfessorMenu(); break;
		case 2:  StudentsMenu();
		}

	} while (mode != 0);

	system("pause");

	return 1;
}