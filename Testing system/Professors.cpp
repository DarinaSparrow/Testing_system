#include "Professors.h"

void ProfessorMenu()
{
	int work, current_professor;
	string current_login, current_password;
	struct Account Professors[profes];
	bool to_be = true;

	ReadProfessorsDataFile(Professors);

	cout << "���� �� ������ ����� �� ������ �������������, ������� ������ ������ 0." << endl;

	do
	{
		cout << "������� �����: ";
		cin >> current_login;
		if (current_login != "0")
		{
			to_be = false;
			for (int i = 0; i < profes; i++)
			{
				if (current_login == Professors[i].login)
				{
					current_professor = i;
					to_be = true;
				}
			}
			if (to_be == false) cout << "����� ������� ������ �� ����������." << endl;
		}
	} while ((to_be == false) && (current_login != "0"));

	if (current_login == "0") system("cls");

	else
	{
		do
		{
			cout << "������� ������: ";
			cin >> current_password;
			if (current_password != Professors[current_professor].password) cout << "�������� ������ ��������." << endl;
		} while (current_password != Professors[current_professor].password);

		system("cls");

		do
		{
			cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

			cout << "�������� ��������: " << endl;
			cout << "1. �������������� ��������" << endl;
			cout << "2. ������ �� ������� ���������" << endl;
			cout << "(��� ������ �� ������� ������ ������� 0)" << endl << endl;

			do
			{
				cout << "��� �����: ";
				IntInputValidation(work);
				if ((work < 0) || (work > 2)) cout << "������! ��������� ������� ��������." << endl;
			} while ((work < 0) || (work > 2));

			system("cls");

			switch (work)
			{
			case 1: QuestionEditor(Professors, current_professor); break;
			case 2: WorkWithStudents(Professors, current_professor);
			}

		} while (work != 0);
	}
}

void QuestionEditor(struct Account *Professors, int current_professor)
{
	int work;

	do
	{
		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "�������������� ��������: " << endl;
		cout << "1. ��������" << endl;
		cout << "2. ����������" << endl;
		cout << "3. ���������" << endl;
		cout << "(��� ������ �� ������ ������� 0)" << endl << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(work);
			if ((work < 0) || (work > 3)) cout << "������! ��������� ������� ��������." << endl;
		} while ((work < 0) || (work > 3));

		system("cls");

		switch (work)
		{
		case 1: Deletion(Professors, current_professor); break;
		case 2: Adding(Professors, current_professor); break;
		case 3: Change(Professors, current_professor);
		}

	} while (work != 0);
}

void Deletion(struct Account *Professors, int current_professor)
{
	int current_topic, current_question;
	struct List Questions[topics];

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	ReadQuestionsDataFile(Questions);

	cout << "������ ��������� ���: " << endl;
	cout << "���� 1. �����" << endl;
	cout << "���� 2. �������" << endl;
	cout << "���� 3. ������" << endl;
	cout << "���� 4. ��������" << endl;
	cout << "���� 5. ���������" << endl;
	cout << "���� 6. �����" << endl;
	cout << "���� 7. ������ � ���������" << endl;
	cout << "���� 8. ������������ ������" << endl;
	cout << "������� ����, � ������� ������ ������� ������: ";

	do
	{
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > topics))
		{
			cout << "������! ��������� ������� ��������." << endl;
			cout << "������� ����, � ������� ������ ������� ������: ";
		}
	} while ((current_topic < 1) || (current_topic > topics));
	current_topic -= 1;

	cout << endl;
	cout << Questions[current_topic].theme << ":" << endl;
	for (int i = 0; i < Questions->n[current_topic]; i++) cout << i + 1 << ". " << Questions[current_topic].question[i] << endl;
	cout << endl;

	do
	{
		cout << "������� ������, ������� ������ �������: ";
		IntInputValidation(current_question);
		if ((current_question < 1) || (current_question > Questions->n[current_topic])) cout << "������! ��������� ������� ��������." << endl;
	} while ((current_question < 1) || (current_question > Questions->n[current_topic]));
	current_question -= 1;

	cout << endl << "������ \"" << Questions[current_topic].question[current_question] << "\" ��� �����." << endl << endl;

	for (int i = current_question; i < Questions->n[current_topic]; i++)
	{
		Questions[current_topic].question[i] = Questions[current_topic].question[i + 1];
		for (int k = 0; k < variants; k++) Questions[current_topic].answers[i][k] = Questions[current_topic].answers[i + 1][k];
		Questions[current_topic].rightanswer[i] = Questions[current_topic].rightanswer[i + 1];
	}
	Questions->n[current_topic] -= 1;

	PrintQuestionsDataFile(Questions);

	system("pause");
	system("cls");
}

void Adding(struct Account *Professors, int current_professor)
{
	int current_topic;
	string part2;
	struct List Questions[topics];

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	ReadQuestionsDataFile(Questions);

	cout << "������ ��������� ���: " << endl;
	cout << "���� 1. �����" << endl;
	cout << "���� 2. �������" << endl;
	cout << "���� 3. ������" << endl;
	cout << "���� 4. ��������" << endl;
	cout << "���� 5. ���������" << endl;
	cout << "���� 6. �����" << endl;
	cout << "���� 7. ������ � ���������" << endl;
	cout << "���� 8. ������������ ������" << endl;
	cout << "������� ����, � ������� ������ �������� ������: ";

	do
	{
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > topics))
		{
			cout << "������! ��������� ������� ��������." << endl;
			cout << "������� ����, � ������� ������ �������� ������: ";
		}
	} while ((current_topic < 1) || (current_topic > topics));
	current_topic -= 1;

	cout << endl;

	cout << "������� ������: ";
	getchar();
	getline(cin, Questions[current_topic].question[Questions->n[current_topic]], '\n');
	for (int k = 0; k < variants; k++)
	{
		cout << "������� " << k + 1 << " ������� ������: ";
		std::string part1 = std::to_string(k + 1);
		getline(cin, part2, '\n');
		Questions[current_topic].answers[Questions->n[current_topic]][k] = part1 + ") " + part2;
	}
	do
	{
		cout << "������� ����� ����������� ������: ";
		IntInputValidation(Questions[current_topic].rightanswer[Questions->n[current_topic]]);
		if ((Questions[current_topic].rightanswer[Questions->n[current_topic]] < 1) || (Questions[current_topic].rightanswer[Questions->n[current_topic]] > variants)) cout << "������! ��������� ������� ��������." << endl;
	} while ((Questions[current_topic].rightanswer[Questions->n[current_topic]] < 1) || (Questions[current_topic].rightanswer[Questions->n[current_topic]] > variants));
	Questions->n[current_topic] += 1;

	PrintQuestionsDataFile(Questions);

	cout << endl << "������ ��� �������� � ������ \"" << Questions[current_topic].theme << "\"." << endl << endl;

	system("pause");
	system("cls");
}

void Change(struct Account *Professors, int current_professor)
{
	int current_topic, current_question;
	string part2, old_question;
	struct List Questions[topics];

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	ReadQuestionsDataFile(Questions);

	cout << "������ ��������� ���: " << endl;
	cout << "���� 1. �����" << endl;
	cout << "���� 2. �������" << endl;
	cout << "���� 3. ������" << endl;
	cout << "���� 4. ��������" << endl;
	cout << "���� 5. ���������" << endl;
	cout << "���� 6. �����" << endl;
	cout << "���� 7. ������ � ���������" << endl;
	cout << "���� 8. ������������ ������" << endl;
	cout << "������� ����, � ������� ������ �������� ������: ";

	do
	{
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > topics))
		{
			cout << "������! ��������� ������� ��������." << endl;
			cout << "������� ����, � ������� ������ �������� ������: ";
		}
	} while ((current_topic < 1) || (current_topic > topics));
	current_topic -= 1;

	cout << endl;
	cout << Questions[current_topic].theme << ":" << endl;
	for (int i = 0; i < Questions->n[current_topic]; i++)
	{
		cout << i + 1 << ". " << Questions[current_topic].question[i] << endl;
		for (int j = 0; j < variants; j++) cout << Questions[current_topic].answers[i][j] << endl;
		cout << "��������� �����: " << Questions[current_topic].rightanswer[i]<< endl << endl;
	}

	do
	{
		cout << "������� ������, ������� ������ ��������: ";
		IntInputValidation(current_question);
		if ((current_question < 1) || (current_question > Questions->n[current_topic])) cout << "������! ��������� ������� ��������." << endl;
	} while ((current_question < 1) || (current_question > Questions->n[current_topic]));
	current_question -= 1;

	old_question = Questions[current_topic].question[current_question];

	cout << "������� ����� ������: ";
	getchar();
	getline(cin, Questions[current_topic].question[current_question], '\n');
	for (int k = 0; k < variants; k++)
	{
		cout << "������� " << k + 1 << " ������� ������: ";
		std::string part1 = std::to_string(k + 1);
		getline(cin, part2, '\n');
		Questions[current_topic].answers[current_question][k] = part1 + ") " + part2;
	}
	do
	{
		cout << "������� ����� ����������� ������: ";
		IntInputValidation(Questions[current_topic].rightanswer[current_question]);
		if ((Questions[current_topic].rightanswer[current_question] < 1) || (Questions[current_topic].rightanswer[current_question] > variants)) cout << "������! ��������� ������� ��������." << endl;
	} while ((Questions[current_topic].rightanswer[current_question] < 1) || (Questions[current_topic].rightanswer[current_question] > variants));

	PrintQuestionsDataFile(Questions);

	cout << endl << "������ \"" << old_question << "\" ��� ������ �� \"" << Questions[current_topic].question[current_question] << "\"." << endl << endl;

	system("pause");
	system("cls");
}

void WorkWithStudents(struct Account* Professors, int current_professor)
{
	int work;

	do
	{
		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "������ �� ������� ���������: " << endl;
		cout << "1. �������� � ����������� ���������" << endl;
		cout << "2. ��������� ��������� ���������" << endl;
		cout << "3. ����� ������ ��������� � ��������" << endl;
		cout << "(��� ������ �� ������ ������� 0)" << endl << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(work);
			if ((work < 0) || (work > 3)) cout << "������! ��������� ������� ��������." << endl;
		} while ((work < 0) || (work > 3));

		system("cls");

		switch (work)
		{
		case 1: DeletionAndRegistration(Professors, current_professor); break;
		case 2: ChangingProgress(Professors, current_professor); break;
		case 3: ListOutput(Professors, current_professor);
		}

	} while (work != 0);
}

void DeletionAndRegistration(struct Account* Professors, int current_professor)
{
	int work;

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "�������� ��������: " << endl;
	cout << "1. �������� ������� ������ ��������" << endl;
	cout << "2. �������� ����� ������� ������ ��������" << endl;
	cout << "(��� ������ �� ������ ������� 0)" << endl << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(work);
		if ((work < 0) || (work > 2)) cout << "������! ��������� ������� ��������." << endl;
	} while ((work < 0) || (work > 2));

	system("cls");

	switch (work)
	{
	case 1: DeletionOfStudent(Professors, current_professor); break;
	case 2: StudentRegistration(Professors, current_professor);
	}
}

void DeletionOfStudent(struct Account* Professors, int current_professor)
{
	int current_student;
	string current_surname, confirmation, list;
	struct Data* Students = NULL;
	bool to_be = true;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	do
	{
		cout << "�� ������ ����������� �� ������� ���������? ";
		cin >> list;
if ((list == "��") || (list == "��"))
{
	cout << endl;
	for (int i = 0; i < Students->quantity; i++) cout << Students[i].surname << " " << Students[i].name << endl;
}
else if ((list != "���") && (list != "���")) cout << "����������, ������� ������ �� ��� ���!" << endl;
	} while ((list != "��") && (list != "��") && (list != "���") && (list != "���"));
	cout << endl;

	do
	{
		cout << "������� ������� ��������, ��� ������� ������ ������ �������: ";
		cin >> current_surname;
		to_be = false;
		for (int i = 0; i < Students->quantity; i++)
		{
			if (current_surname == Students[i].surname)
			{
				current_student = i;
				to_be = true;
			}
		}
		if (to_be == false) cout << "�������� � ����� ������� ������� �� ����������." << endl;
	} while (to_be == false);

	system("cls");
	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "���������� ������� ������ �������� � ������ " << Students[current_student].surname << " " << Students[current_student].name << "." << endl;
	do
	{
		cout << "�� ������������ ������ � �������? ";
		cin >> confirmation;
		if ((confirmation == "��") || (confirmation == "��"))
		{
			for (int i = current_student; i < Students->quantity; i++)
			{
				Students[i].login = Students[i + 1].login;
				Students[i].password = Students[i + 1].password;
				Students[i].name = Students[i + 1].name;
				Students[i].surname = Students[i + 1].surname;
				for (int k = 0; k < topics; k++) Students[i].tmark[k] = Students[i + 1].tmark[k];
				Students[i].fmark = Students[i + 1].fmark;
				Students[i].average = Students[i + 1].average;
			}
			Students->quantity -= 1;

			PrintStudentsDataFile(Students);
			cout << endl << "������� ������ �������." << endl << endl;
			system("pause");
			system("cls");
		}
		else if ((confirmation == "���") || (confirmation == "���"))
		{
			cout << endl;
			system("pause");
			system("cls");
		}
		else cout << "����������, ������� ������ �� ��� ���!" << endl;
	} while ((confirmation != "��") && (confirmation != "��") && (confirmation != "���") && (confirmation != "���"));

	PrintStudentsDataFile(Students);

	delete[]Students;
}

void StudentRegistration(struct Account* Professors, int current_professor)
{
	int current_mark, i, current_position;
	double sum, count;
	string glass_surname, glass_name;
	string themes[topics] = { "�����", "�������", "������", "��������", "���������", "�����", "������ � ���������", "������������ ������", };
	struct Data* Students = NULL;
	bool flag1, flag2, FLAG, flag_name;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "��� �������� ����� ������� ������ �������� ������� ��� ����������� ������." << endl << endl;

	Students->quantity += 1;

	cout << "�������: ";
	cin >> glass_surname;

	FLAG = true;
	flag_name = false;
	flag1 = false;
	i = 0;
	while (flag1 == false)
	{
		if (glass_surname == Students[i].surname)
		{
			cout << "���: ";
			cin >> glass_name;
			flag_name = true;
			flag2 = false;
			while ((flag2 == false) && (glass_surname == Students[i].surname))
			{
				if (glass_name == Students[i].name)
				{
					FLAG = false;
					flag2 = true;
					flag1 = true;
					cout << endl << "������� ������ �������� ��� �����������." << endl << endl;
				}
				else
				{
					if (i == Students->quantity - 2)
					{
						current_position = i + 1;
						flag2 = true;
						flag1 = true;
					}
					else
					{
						if (glass_name > Students[i].name)
						{
							if (glass_surname == Students[i + 1].surname)
							{
								if (glass_name < Students[i + 1].name)
								{
									current_position = i + 1;
									flag2 = true;
									flag1 = true;
								}
								else i += 1;
							}
							else
							{
								current_position = i + 1;
								flag2 = true;
								flag1 = true;
							}
						}
						else i += 1;
					}
				}
			}
		}
		else
		{
			if (i == Students->quantity - 2)
			{
				current_position = i + 1;
				flag1 = true;
			}
			else
			{
				if ((glass_surname > Students[i].surname) && (glass_surname < Students[i + 1].surname))
				{
					current_position = i + 1;
					flag1 = true;
				}
				else i += 1;
			}
		}
	}
	
	if (FLAG == true)
	{
		for (int i = Students->quantity - 1; i > current_position; i--)
		{
			Students[i].login = Students[i - 1].login;
			Students[i].password = Students[i - 1].password;
			Students[i].name = Students[i - 1].name;
			Students[i].surname = Students[i - 1].surname;
			for (int k = 0; k < topics; k++) Students[i].tmark[k] = Students[i - 1].tmark[k];
			Students[i].fmark = Students[i - 1].fmark;
			Students[i].average = Students[i - 1].average;
		}

		Students[current_position].surname = glass_surname;
		if (flag_name == false)
		{
			cout << "���: ";
			cin >> Students[current_position].name;
		}
		else Students[current_position].name = glass_name;
		sum = 0;
		count = 0;
		cout << endl << "������ �� ������ (� ������, ���� ������� �� �������� ����, ������� 0):" << endl;
		for (int i = 0; i < topics; i++)
		{
			do
			{
				cout << "������ �� ���� �� ���� \"" << themes[i] << "\": ";
				IntInputValidation(current_mark);
				if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "������! ��������� ������� ��������." << endl;
			} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));
			Students[current_position].tmark[i] = current_mark;
			if (Students[current_position].tmark[i] != 0)
			{
				sum += Students[current_position].tmark[i];
				count += 1;
			}
		}
		do
		{
			cout << "������ �� �������� ����: ";
			IntInputValidation(Students[current_position].fmark);
			if (((Students[current_position].fmark < 2) || (Students[current_position].fmark > 5)) && (Students[current_position].fmark != 0)) cout << "������! ��������� ������� ��������." << endl;
		} while (((Students[current_position].fmark < 2) || (Students[current_position].fmark > 5)) && (Students[current_position].fmark != 0));
		if (Students[current_position].fmark != 0)
		{
			sum += Students[current_position].fmark;
			count += 1;
		}
		Students[current_position].average = round(sum / count * 100) / 100;
		cout << endl << "���������� ����� � ������ ��� ����� ������� ������ ��������." << endl;
		do
		{
			cout << "�����: ";
			cin >> Students[current_position].login;
			if (Students[current_position].login.length() < 7) cout << "����� ������ �������� ������� �� 7 ��������." << endl;
		} while (Students[current_position].login.length() < 7);
		do
		{
			cout << "������: ";
			cin >> Students[current_position].password;
			if (Students[current_position].password.length() < 10) cout << "������ ������ �������� ������� �� 10 ��������." << endl;
		} while (Students[current_position].password.length() < 10);

		PrintStudentsDataFile(Students);
		cout << endl << "������� ������ �������." << endl << endl;
	}

	system("pause");
	system("cls");

	delete[]Students;
}

void ChangingProgress(struct Account* Professors, int current_professor)
{
	int current_student, parameter;
	double sum, count;
	string current_surname, list;
	string themes[topics] = { "�����", "�������", "������", "��������", "���������", "�����", "������ � ���������", "������������ ������", };
	struct Data* Students = NULL;
	bool to_be = true;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	do
	{
		cout << "�� ������ ����������� �� ������� ���������? ";
		cin >> list;
		if ((list == "��") || (list == "��"))
		{
			cout << endl;
			for (int i = 0; i < Students->quantity; i++) cout << Students[i].surname << " " << Students[i].name << endl;
		}
		else if ((list != "���") && (list != "���")) cout << "����������, ������� ������ �� ��� ���!" << endl;
	} while ((list != "��") && (list != "��") && (list != "���") && (list != "���"));
	cout << endl;

	do
	{
		cout << "������� ������� ��������, ��� �������� ������ ��������: ";
		cin >> current_surname;
		to_be = false;
		for (int i = 0; i < Students->quantity; i++)
		{
			if (current_surname == Students[i].surname)
			{
				current_student = i;
				to_be = true;
			}
		}
		if (to_be == false) cout << "�������� � ����� ������� ������� �� ����������." << endl;
	} while ((to_be == false));

	do
	{
		system("cls");
		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << Students[current_student].surname << " " << Students[current_student].name << endl << endl;

		for (int i = 0; i < topics; i++)
		{
			cout << i + 1 << ". ������ �� ���� �� ���� \"" << themes[i] << "\": ";
			if (Students[current_student].tmark[i] == 0) cout << "���� �� �������" << endl;
			else cout << Students[current_student].tmark[i] << endl;
		}
		cout << "9. ������ �� �������� ����: ";
		if (Students[current_student].fmark == 0) cout << "���� �� �������" << endl;
		else cout << Students[current_student].fmark << endl;
		cout << "10. ������� ����: " << Students[current_student].average << endl << endl;

		cout << "���� �� ������ �����, ������� ������ ��������� 0." << endl;
		do
		{
			cout << "������� ��������, ������� ������ ��������: ";
			IntInputValidation(parameter);
			if ((parameter < 0) || (parameter > 10)) cout << "������! ��������� ������� ��������." << endl;
			else if (parameter == 10) cout << "������� ���� �������� ����������� �������������." << endl;
		} while ((parameter < 0) || (parameter > 9));

		if (parameter == 9)
		{
			cout << endl << "���� �� ������ ������� ��������� ������, ������� 0." << endl;
			do
			{
				cout << "������� ����� ������ �� �������� ����: ";
				IntInputValidation(Students[current_student].fmark);
				if (((Students[current_student].fmark < 2) || (Students[current_student].fmark > 5)) && (Students[current_student].fmark != 0)) cout << "������! ��������� ������� ��������." << endl;
			} while (((Students[current_student].fmark < 2) || (Students[current_student].fmark > 5)) && (Students[current_student].fmark != 0));
		}
		else if (parameter != 0)
		{
			cout << endl << "���� �� ������ ������� ��������� ������, ������� 0." << endl;
			do
			{
				cout << "������� ����� ������ �� ���� �� ���� \"" << themes[parameter - 1] << "\": ";
				IntInputValidation(Students[current_student].tmark[parameter - 1]);
				if (((Students[current_student].tmark[parameter - 1] < 2) || (Students[current_student].tmark[parameter - 1] > 5)) && (Students[current_student].fmark != 0)) cout << "������! ��������� ������� ��������." << endl;
			} while (((Students[current_student].tmark[parameter - 1] < 2) || (Students[current_student].tmark[parameter - 1] > 5)) && (Students[current_student].fmark != 0));
		}

		if (parameter != 0)
		{
			sum = 0;
			count = 0;
			for (int i = 0; i < topics; i++)
			{
				if (Students[current_student].tmark[i] != 0)
				{
					sum += Students[current_student].tmark[i];
					count += 1;
				}
			}
			if (Students[current_student].fmark != 0)
			{
				sum += Students[current_student].fmark;
				count += 1;
			}
			Students[current_student].average = round(sum / count * 100) / 100;
		}

	} while (parameter != 0);

	PrintStudentsDataFile(Students);

	cout << endl;
	system("pause");
	system("cls");

	delete[]Students;
}

void ListOutput(struct Account *Professors, int current_professor)
{
	int work;

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "�������� ��������: " << endl;
	cout << "1. ����� ������ ��������� � �������� �� ���� �����" << endl;
	cout << "2. ����� ������ ��������� � �������� �� ���������� ����" << endl;
	cout << "3. ����� ������ ��������� � �������� �� ��������� �����" << endl;
	cout << "4. ����� ������ ��������� �� ������� ������" << endl;
	cout << "(��� ������ �� ������ ������� 0)" << endl << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(work);
		if ((work < 0) || (work > 4)) cout << "������! ��������� ������� ��������." << endl;
	} while ((work < 0) || (work > 4));

	system("cls");

	switch (work)
	{
	case 1: AllTopics(Professors, current_professor); break;
	case 2: SpecificTopic(Professors, current_professor); break;
	case 3: FinalTest(Professors, current_professor); break;
	case 4: AverageMark(Professors, current_professor);;
	}
}

void AllTopics(struct Account *Professors, int current_professor)
{
	int work, method, way, current_student, current_mark, k, current_position, i;
	double min_mark, max_mark, glass;
	struct Data* Students = NULL;
	bool flag;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "�������� �������������� �����: " << endl;
	cout << "1. ����������" << endl;
	cout << "2. ����������" << endl;
	cout << "3. ������ �� ������������������" << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "������! ��������� ������� ��������." << endl;
	} while ((work < 1) || (work > 3));

	system("cls");

	switch(work)
	{
	case 1:

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "�������� �������� ����������: " << endl;
		cout << "1. �� ������ �� ���� �� ���� 1" << endl;
		cout << "2. �� ������ �� ���� �� ���� 2" << endl;
		cout << "3. �� ������ �� ���� �� ���� 3" << endl;
		cout << "4. �� ������ �� ���� �� ���� 4" << endl;
		cout << "5. �� ������ �� ���� �� ���� 5" << endl; 
		cout << "6. �� ������ �� ���� �� ���� 6" << endl;
		cout << "7. �� ������ �� ���� �� ���� 7" << endl;
		cout << "8. �� ������ �� ���� �� ���� 8" << endl;
		cout << "9. �� ������ �� �������� ����" << endl;
		cout << "10. �� �������� �����" << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(method);
			if ((method < 1) || (method > 10)) cout << "������! ��������� ������� ��������." << endl;
		} while ((method < 1) || (method > 10));

		cout <<  endl;

		if (method != 10)
		{
			cout << "���� �� ������ ������� ������ ���������, �� ������� ��������� ����, ������� 0. " << endl;
			do
			{
				cout << "������� ������: ";
				IntInputValidation(current_mark);
				if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "������! ��������� ������� ��������." << endl;
			} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));
		}
		else
		{
			do
			{
				cout << "������� ����������� �������� �������� �����: ";
				DoubleInputValidation(min_mark);
				cout << "������� ������������ �������� �������� �����: ";
				DoubleInputValidation(max_mark);
				if ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5)) cout << "������! ��������� ������� ��������." << endl;
			} while ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5));
			if (min_mark > max_mark)
			{
				glass = min_mark;
				min_mark = max_mark;
				max_mark = glass;
			}
		}

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ����1 | ����2 | ����3 | ����4 | ����5 | ����6 | ����7 | ����8 | �������� ���� | ������� ���� |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			if (((method >= 1) && (method <= 8) && (Students[i].tmark[method - 1] == current_mark)) || ((method == 9) && (Students[i].fmark == current_mark)) || ((method == 10) && (Students[i].average >= min_mark) && (Students[i].average <= max_mark)))
			{
				k += 1;
				cout << "|";
				if (k < 10) cout << setw(3) << k << setw(3) << "|";
				else cout << setw(4) << k << setw(2) << "|";
				cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
				cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
				for (int j = 0; j < topics; j++)
				{
					if (Students[i].tmark[j] == 0) cout << setw(8) << "|";
					else cout << setw(4) << Students[i].tmark[j] << setw(4) << "|";
				}
				if (Students[i].fmark == 0) cout << setw(16) << "|";
				else cout << setw(8) << Students[i].fmark << setw(8) << "|";
				if (Students[i].average == 0) cout << setw(15) << "|";
				else cout << setw(9) << Students[i].average << setw(6) << "|";
				cout << endl;
			}
		}
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;

		break;

	case 2:

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "�������� �������� ����������: " << endl;
		cout << "1. �� ������ �� ���� �� ���� 1" << endl;
		cout << "2. �� ������ �� ���� �� ���� 2" << endl;
		cout << "3. �� ������ �� ���� �� ���� 3" << endl;
		cout << "4. �� ������ �� ���� �� ���� 4" << endl;
		cout << "5. �� ������ �� ���� �� ���� 5" << endl;
		cout << "6. �� ������ �� ���� �� ���� 6" << endl;
		cout << "7. �� ������ �� ���� �� ���� 7" << endl;
		cout << "8. �� ������ �� ���� �� ���� 8" << endl;
		cout << "9. �� ������ �� �������� ����" << endl;
		cout << "10. �� �������� �����" << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(method);
			if ((method < 1) || (method > 10)) cout << "������! ��������� ������� ��������." << endl;
		} while ((method < 1) || (method > 10));

		cout << endl;
		cout << "�������� ������ ����������: " << endl;
		cout << "1. �� ������� ���������� � �������" << endl;
		cout << "2. �� ������� ���������� � �������" << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "������! ��������� ������� ��������." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ����1 | ����2 | ����3 | ����4 | ����5 | ����6 | ����7 | ����8 | �������� ���� | ������� ���� |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		if (method != 10)
		{
			if (way == 1) current_position = 5;
			else current_position = 0;
			while (k < Students->quantity)
			{
				for (int i = 0; i < Students->quantity; i++)
				{
					if (((method >= 1) && (method <= 8) && (Students[i].tmark[method - 1] == current_position)) || ((method == 9) && (Students[i].fmark == current_position)))
					{
						k += 1;
						cout << "|";
						if (k < 10) cout << setw(3) << k << setw(3) << "|";
						else cout << setw(4) << k << setw(2) << "|";
						cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
						cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
						for (int j = 0; j < topics; j++)
						{
							if (Students[i].tmark[j] == 0) cout << setw(8) << "|";
							else cout << setw(4) << Students[i].tmark[j] << setw(4) << "|";
						}
						if (Students[i].fmark == 0) cout << setw(16) << "|";
						else cout << setw(8) << Students[i].fmark << setw(8) << "|";
						if (Students[i].average == 0) cout << setw(15) << "|";
						else cout << setw(9) << Students[i].average << setw(6) << "|";
						cout << endl;
					}
				}
				if (way == 1) current_position -= 1;
				else current_position += 1;
			}
		}
		else
		{
			if (way == 1) max_mark = Students[0].average;
			else min_mark = Students[0].average;
			while (k < Students->quantity)
			{
				if (way == 1)
				{
					for (int i = 0; i < Students->quantity; i++)
					{
						if (Students[i].average > max_mark)
						{
							max_mark = Students[i].average;
							current_student = i;
						}
					}
				}
				else
				{
					for (int i = 0; i < Students->quantity; i++)
					{
						if (Students[i].average < min_mark)
						{
							min_mark = Students[i].average;
							current_student = i;
						}
					}
				}
				k += 1;
				cout << "|";
				if (k < 10) cout << setw(3) << k << setw(3) << "|";
				else cout << setw(4) << k << setw(2) << "|";
				cout << setw(Students[current_student].surname.length() + 1) << Students[current_student].surname << setw(15 - Students[current_student].surname.length()) << "|";
				cout << setw(Students[current_student].name.length() + 1) << Students[current_student].name << setw(13 - Students[current_student].name.length()) << "|";
				for (int j = 0; j < topics; j++)
				{
					if (Students[current_student].tmark[j] == 0) cout << setw(8) << "|";
					else cout << setw(4) << Students[current_student].tmark[j] << setw(4) << "|";
				}
				if (Students[current_student].fmark == 0) cout << setw(16) << "|";
				else cout << setw(8) << Students[current_student].fmark << setw(8) << "|";
				if (Students[current_student].average == 0) cout << setw(15) << "|";
				else cout << setw(9) << Students[current_student].average << setw(6) << "|";
				cout << endl;
				flag = false;
				if (way == 1)
				{
					Students[current_student].average = 0;
					i = 0;
					while (flag == false)
					{
						if (Students[i].average != 0)
						{
							max_mark = Students[i].average;
							current_student = i;
							flag = true;
						}
						else i += 1;
					}
				}
				else 
				{
					Students[current_student].average = 6;
					i = 0;
					while (flag == false)
					{
						if (Students[i].average != 6)
						{
							min_mark = Students[i].average;
							current_student = i;
							flag = true;
						}
						else i += 1;
					}
				}
			}
		}
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;

		break;

	case 3:

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ����1 | ����2 | ����3 | ����4 | ����5 | ����6 | ����7 | ����8 | �������� ���� | ������� ���� |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			cout << "|";
			if (i < 9) cout << setw(3) << i + 1 << setw(3) << "|";
			else cout << setw(4) << i + 1 << setw(2) << "|";
			cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
			cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
			for (int j = 0; j < topics; j++)
			{
				if (Students[i].tmark[j] == 0) cout << setw(8) << "|";
				else cout << setw(4) << Students[i].tmark[j] << setw(4) << "|";
			}
			if (Students[i].fmark == 0) cout << setw(16) << "|";
			else cout << setw(8) << Students[i].fmark << setw(8) << "|";
			if (Students[i].average == 0) cout << setw(15) << "|";
			else cout << setw(9) << Students[i].average << setw(6) << "|";
			cout << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;

	}

	system("pause");
	system("cls");
	 
	delete[]Students;
}

void SpecificTopic(struct Account *Professors, int current_professor)
{
	int work, way, current_topic, current_mark, k, current_position;
	struct Data* Students = NULL;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "�������� ����, �� ������� ������ ������ ������: " << endl;
	cout << "1. �����" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������" << endl;
	cout << "4. ��������" << endl;
	cout << "5. ���������" << endl;
	cout << "6. �����" << endl;
	cout << "7. ������ � ���������" << endl;
	cout << "8. ������������ ������" << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > 8)) cout << "������! ��������� ������� ��������." << endl;
	} while ((current_topic < 1) || (current_topic > 8));

	cout << endl;
	cout  << "�������� �������������� �����: " << endl;
	cout << "1. ����������" << endl;
	cout << "2. ����������" << endl;
	cout << "3. ������ �� ������������������" << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "������! ��������� ������� ��������." << endl;
	} while ((work < 1) || (work > 3));

	switch (work)
	{
	case 1:

		cout << endl << "���� �� ������ ������� ������ ���������, �� ������� ��������� ����, ������� 0. " << endl;
		do
		{
			cout << "������� ������: ";
			IntInputValidation(current_mark);
			if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "������! ��������� ������� ��������." << endl;
		} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "---------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ����" << current_topic << " |" << endl;
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			if (Students[i].tmark[current_topic - 1] == current_mark)
			{
				k += 1;
				cout << "|";
				if (k < 10) cout << setw(3) << k << setw(3) << "|";
				else cout << setw(4) << k << setw(2) << "|";
				cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
				cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
				if (Students[i].tmark[current_topic - 1] == 0) cout << setw(8) << "|";
				else cout << setw(4) << Students[i].tmark[current_topic - 1] << setw(4) << "|";
				cout << endl;
			}
		}
		cout << "---------------------------------------------" << endl;
		cout << endl;

		break;

	case 2:

		cout << endl;
		cout << "�������� ������ ����������: " << endl;
		cout << "1. �� ������� ���������� � �������" << endl;
		cout << "2. �� ������� ���������� � �������" << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "������! ��������� ������� ��������." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "---------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ����" << current_topic << " |" << endl;
		cout << "---------------------------------------------" << endl;
		if (way == 1) current_position = 5;
		else current_position = 0;
		while (k < Students->quantity)
		{
			for (int i = 0; i < Students->quantity; i++)
			{
				if (Students[i].tmark[current_topic - 1] == current_position)
				{
					k += 1;
					cout << "|";
					if (k < 10) cout << setw(3) << k << setw(3) << "|";
					else cout << setw(4) << k << setw(2) << "|";
					cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
					cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
					if (Students[i].tmark[current_topic - 1] == 0) cout << setw(8) << "|";
					else cout << setw(4) << Students[i].tmark[current_topic - 1] << setw(4) << "|";
					cout << endl;
				}
			}
			if (way == 1) current_position -= 1;
			else current_position += 1;
		}
		cout << "---------------------------------------------" << endl;
		cout << endl;

		break;

	case 3:

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "---------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ����" << current_topic << " |" << endl;
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			cout << "|";
			if (i < 9) cout << setw(3) << i + 1 << setw(3) << "|";
			else cout << setw(4) << i + 1 << setw(2) << "|";
			cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
			cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
			if (Students[i].tmark[current_topic - 1] == 0) cout << setw(8) << "|";
			else cout << setw(4) << Students[i].tmark[current_topic - 1] << setw(4) << "|";
			cout << endl;
		}
		cout << "---------------------------------------------" << endl;
		cout << endl;

	}

	system("pause");
	system("cls");

	delete[]Students;
}

void FinalTest(struct Account *Professors, int current_professor)
{
	int work, way, current_mark, k, current_position;
	struct Data* Students = NULL;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "�������� �������������� �����: " << endl;
	cout << "1. ����������" << endl;
	cout << "2. ����������" << endl;
	cout << "3. ������ �� ������������������" << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "������! ��������� ������� ��������." << endl;
	} while ((work < 1) || (work > 3));

	switch (work)
	{
	case 1:

		cout << endl << "���� �� ������ ������� ������ ���������, �� ������� �������� ����, ������� 0. " << endl;
		do
		{
			cout << "������� ������: ";
			IntInputValidation(current_mark);
			if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "������! ��������� ������� ��������." << endl;
		} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "-----------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | �������� ���� |" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			if (Students[i].fmark == current_mark)
			{
				k += 1;
				cout << "|";
				if (k < 10) cout << setw(3) << k << setw(3) << "|";
				else cout << setw(4) << k << setw(2) << "|";
				cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
				cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
				if (Students[i].fmark == 0) cout << setw(16) << "|";
				else cout << setw(8) << Students[i].fmark << setw(8) << "|";
				cout << endl;
			}
		}
		cout << "-----------------------------------------------------" << endl;
		cout << endl;

		break;

	case 2:

		cout << endl;
		cout << "�������� ������ ����������: " << endl;
		cout << "1. �� ������� ���������� � �������" << endl;
		cout << "2. �� ������� ���������� � �������" << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "������! ��������� ������� ��������." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "-----------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | �������� ���� |" << endl;
		cout << "-----------------------------------------------------" << endl;
		if (way == 1) current_position = 5;
		else current_position = 0;
		while (k < Students->quantity)
		{
			for (int i = 0; i < Students->quantity; i++)
			{
				if (Students[i].fmark == current_position)
				{
					k += 1;
					cout << "|";
					if (k < 10) cout << setw(3) << k << setw(3) << "|";
					else cout << setw(4) << k << setw(2) << "|";
					cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
					cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
					if (Students[i].fmark == 0) cout << setw(16) << "|";
					else cout << setw(8) << Students[i].fmark << setw(8) << "|";
					cout << endl;
				}
			}
			if (way == 1) current_position -= 1;
			else current_position += 1;
		}
		cout << "-----------------------------------------------------" << endl;
		cout << endl;

		break;

	case 3:

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "-----------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | �������� ���� |" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			cout << "|";
			if (i < 9) cout << setw(3) << i + 1 << setw(3) << "|";
			else cout << setw(4) << i + 1 << setw(2) << "|";
			cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
			cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
			if (Students[i].fmark == 0) cout << setw(16) << "|";
			else cout << setw(8) << Students[i].fmark << setw(8) << "|";
			cout << endl;
		}
		cout << "-----------------------------------------------------" << endl;
		cout << endl;

	}

	system("pause");
	system("cls");

	delete[]Students;
}

void AverageMark(struct Account *Professors, int current_professor)
{
	int work, method, way, current_student, current_mark, k, current_position, i;
	double min_mark, max_mark, glass;
	struct Data* Students = NULL;
	bool flag;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "�������� �������������� �����: " << endl;
	cout << "1. ����������" << endl;
	cout << "2. ����������" << endl;
	cout << "3. ������ �� ������������������" << endl;

	do
	{
		cout << "��� �����: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "������! ��������� ������� ��������." << endl;
	} while ((work < 1) || (work > 3));

	switch (work)
	{
	case 1:

		cout << endl;

		do
		{
			cout << "������� ����������� �������� �������� �����: ";
			DoubleInputValidation(min_mark);
			cout << "������� ������������ �������� �������� �����: ";
			DoubleInputValidation(max_mark);
			if ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5)) cout << "������! ��������� ������� ��������." << endl;
		} while ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5));

		if (min_mark > max_mark)
		{
			glass = min_mark;
			min_mark = max_mark;
			max_mark = glass;
		}

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "----------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ������� ���� |" << endl;
		cout << "----------------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			if ((Students[i].average >= min_mark) && (Students[i].average <= max_mark))
			{
				k += 1;
				cout << "|";
				if (k < 10) cout << setw(3) << k << setw(3) << "|";
				else cout << setw(4) << k << setw(2) << "|";
				cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
				cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
				if (Students[i].average == 0) cout << setw(15) << "|";
				else cout << setw(9) << Students[i].average << setw(6) << "|";
				cout << endl;
			}
		}
		cout << "----------------------------------------------------" << endl;
		cout << endl;

		break;

	case 2:

		cout << endl;
		cout << "�������� ������ ����������: " << endl;
		cout << "1. �� ������� ���������� � �������" << endl;
		cout << "2. �� ������� ���������� � �������" << endl;

		do
		{
			cout << "��� �����: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "������! ��������� ������� ��������." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "----------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ������� ���� |" << endl;
		cout << "----------------------------------------------------" << endl;
		if (way == 1) max_mark = Students[0].average;
		else min_mark = Students[0].average;
		while (k < Students->quantity)
		{
			if (way == 1)
			{
				for (int i = 0; i < Students->quantity; i++)
				{
					if (Students[i].average > max_mark)
					{
						max_mark = Students[i].average;
						current_student = i;
					}
				}
			}
			else
			{
				for (int i = 0; i < Students->quantity; i++)
				{
					if (Students[i].average < min_mark)
					{
						min_mark = Students[i].average;
						current_student = i;
					}
				}
			}
			k += 1;
			cout << "|";
			if (k < 10) cout << setw(3) << k << setw(3) << "|";
			else cout << setw(4) << k << setw(2) << "|";
			cout << setw(Students[current_student].surname.length() + 1) << Students[current_student].surname << setw(15 - Students[current_student].surname.length()) << "|";
			cout << setw(Students[current_student].name.length() + 1) << Students[current_student].name << setw(13 - Students[current_student].name.length()) << "|";
			if (Students[current_student].average == 0) cout << setw(15) << "|";
			else cout << setw(9) << Students[current_student].average << setw(6) << "|";
			cout << endl;
			flag = false;
			if (way == 1)
			{
				Students[current_student].average = 0;
				i = 0;
				while (flag == false)
				{
					if (Students[i].average != 0)
					{
						max_mark = Students[i].average;
						current_student = i;
						flag = true;
					}
					else i += 1;
				}
			}
			else
			{
				Students[current_student].average = 6;
				i = 0;
				while (flag == false)
				{
					if (Students[i].average != 6)
					{
						min_mark = Students[i].average;
						current_student = i;
						flag = true;
					}
					else i += 1;
				}
			}
		}

	    cout << "----------------------------------------------------" << endl;
	    cout << endl;

	    break;

	case 3:

		cout << "������� ������� ������: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "----------------------------------------------------" << endl;
		cout << "|  �  |    �������    |     ���     | ������� ���� |" << endl;
		cout << "----------------------------------------------------" << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			cout << "|";
			if (i < 9) cout << setw(3) << i + 1 << setw(3) << "|";
			else cout << setw(4) << i + 1 << setw(2) << "|";
			cout << setw(Students[i].surname.length() + 1) << Students[i].surname << setw(15 - Students[i].surname.length()) << "|";
			cout << setw(Students[i].name.length() + 1) << Students[i].name << setw(13 - Students[i].name.length()) << "|";
			if (Students[i].average == 0) cout << setw(15) << "|";
			else cout << setw(9) << Students[i].average << setw(6) << "|";
			cout << endl;
		}
		cout << "----------------------------------------------------" << endl;
		cout << endl;

	}

	system("pause");
	system("cls");

	delete[]Students;
}