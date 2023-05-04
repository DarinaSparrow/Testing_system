#include "Students.h"

void StudentsMenu()
{
	srand(time(NULL));

	int menu, CurrentUser;
	string CurrentLogin, CurrentPassword;
	struct Data *Students = NULL;
	struct List Questions[topics];
	bool ToBe = true;

	Students = StudentsMemoryAllocation(Students);

	ReadStudentsDataFile(Students);
	ReadQuestionsDataFile(Questions);

	cout << "���� �� ������ ����� �� ������ ��������, ������� ������ ������ 0." << endl;

	do
	{
		cout << "������� �����: ";
		cin >> CurrentLogin;
		if (CurrentLogin != "0")
		{
			ToBe = false;
			for (int i = 0; i < Students->quantity; i++)
			{
				if (CurrentLogin == Students[i].login)
				{
					CurrentUser = i;
					ToBe = true;
				}
			}
			if (ToBe == false) cout << "����� ������� ������ �� ����������." << endl;
		}
	} while ((ToBe == false) && (CurrentLogin != "0"));

	if (CurrentLogin == "0") system("cls");

	else
	{
		do
		{
			cout << "������� ������: ";
			cin >> CurrentPassword;
			if (CurrentPassword != Students[CurrentUser].password) cout << "�������� ������ ��������." << endl;
		} while (CurrentPassword != Students[CurrentUser].password);

		system("cls");

		do
		{
			cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

			cout << "�������� ��������: " << endl;
			cout << "1. ������ �������� �� ����" << endl;
			cout << "2. ������ ������������ �� ����" << endl;
			cout << "3. ������ �������� ����" << endl;
			cout << "(��� ������ �� ������� ������ ������� 0)" << endl << endl;

			do
			{
				cout << "��� �����: ";
				IntInputValidation(menu);
				if ((menu < 0) || (menu > 3)) cout << "������! ��������� ������� ��������." << endl;
			} while ((menu < 0) || (menu > 3));
			system("cls");

			switch (menu)
			{
			case 1: TopicTraining(Students, Questions, CurrentUser); break;
			case 2: TopicTesting(Students, Questions, CurrentUser); break;
			case 3: FinalTest(Students, Questions, CurrentUser);
			}

			if (menu != 0) system("cls");

		} while (menu != 0);
	}

	delete[]Students;
}

void TopicTraining(Data *Students, const List Questions[], const int CurrentUser)
{
	int theme;

	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "������� �� ����.\n";
	cout << "���������� ��������� ����, ������� ������� �� 10 �������� �� ��������� ����.\n������� � ���������� ������� �� ���������� �� ��� ���, ���� �� ��� ���������� ����� �� ����������.\n\n";

	cout << "�������� ����: " << endl;
	cout << "1. �����" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������" << endl;
	cout << "4. ��������" << endl;
	cout << "5. ���������" << endl;
	cout << "6. �����" << endl;
	cout << "7. ������ � ���������" << endl;
	cout << "8. ������������ ������" << endl;
	cout << "(��� ������ �� ������ ������� 0)" << endl << endl;

	do 
	{
		cout << "��� �����: ";
		IntInputValidation(theme);
		if ((theme < 0) || (theme > 8)) cout << "������! ��������� ������� ��������." << endl;
	} while ((theme < 0) || (theme > 8));

	system("cls");

	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	if (theme != 0)
	{
		int ThemeNum = theme - 1;
		int RandQuestions[test];

		TopicGenerate(RandQuestions, ThemeNum, Questions);

		cout << Questions[ThemeNum].theme << endl;
		for (int i = 0; i < test; i++)
		{
			int o;
			cout << endl << i + 1 << ". " << Questions[ThemeNum].question[RandQuestions[i]] << endl;
			for (int k = 0; k < variants; k++) cout << Questions[ThemeNum].answers[RandQuestions[i]][k] << endl;
			do
			{
				cout << "������� �����: ";
				IntInputValidation(o);
				if (o < 1 || o > 4) cout << "������! ��������� ������� ��������. ";
				else if (o != Questions[ThemeNum].rightanswer[RandQuestions[i]]) cout << "������ �������� �����. ";
			} while (o != Questions[ThemeNum].rightanswer[RandQuestions[i]]);
		}

		cout << endl;
		system("pause");
		system("cls");
	}
}

void TopicTesting(Data *Students, const List Questions[], const int CurrentUser)
{
	int theme;

	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "������������ �� ����.\n";
	cout << "���������� ��������� ����, ������� ������� �� 10 �������� �� ��������� ����.\n�� ��������� ����� ����� ���������� ���������� ������, ����� �������� ����������� ���������� �������.\n����� ����� ���������� ������\n\n";
	cout << "�������� ����������: \n";
	cout << "10 - 9 ���������� ������� �� ������� (0 - 1 ������) - 5 ������\n";
	cout << "8 - 7 ���������� ������� �� ������� (2 - 3 ������) - 4 �����\n";
	cout << "6 - 5 ���������� ������� �� ������� (4 - 5 ������) - 3 �����\n";
	cout << "4 � ����� ���������� ������� �� ������� (6 � ����� ������) - 2 �����\n\n";

	cout << "�������� ����: " << endl;
	cout << "1. �����" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������" << endl;
	cout << "4. ��������" << endl;
	cout << "5. ���������" << endl;
	cout << "6. �����" << endl;
	cout << "7. ������ � ���������" << endl;
	cout << "8. ������������ ������" << endl;
	cout << "(��� ������ �� ������ ������� 0)" << endl << endl;

	do 
	{
		cout << "��� �����: ";
		IntInputValidation(theme);
		if ((theme < 0) || (theme > 8)) cout << "������! ��������� ������� ��������." << endl;
	} while ((theme < 0) || (theme > 8));

	system("cls");

	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	if (theme != 0)
	{
		int ThemeNum = theme - 1;
		int RandQuestions[test];

		TopicGenerate(RandQuestions, ThemeNum, Questions);

		int FailedQuestions[test];
		int MistakeAnswers[test];
		int mistakes = 0;
		int n = 0;
		int mark;

		cout << Questions[ThemeNum].theme << endl;
		for (int i = 0; i < test; i++)
		{
			int o;
			cout << endl << i + 1 << ". " << Questions[ThemeNum].question[RandQuestions[i]] << endl;
			for (int k = 0; k < variants; k++) cout << Questions[ThemeNum].answers[RandQuestions[i]][k] << endl;
			do
			{
				cout << "������� �����: ";
				IntInputValidation(o);
				if (o < 1 || o > 4) cout << "������! ��������� ������� ��������. ";
			} while (o < 1 || o > 4);
			if (o != Questions[ThemeNum].rightanswer[RandQuestions[i]])
			{
				mistakes += 1;
				FailedQuestions[n] = RandQuestions[i];
				MistakeAnswers[n] = o;
				n += 1;
			}
		}

		system("cls");

		cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

		cout << Questions[ThemeNum].theme << endl;
		cout << "���������� ������: " << mistakes << " / " << test << endl;
		cout << "������ : ";
		if (mistakes == 0 || mistakes == 1)
		{
			mark = 5;
			cout << "5 ������ (�������)";
		}
		else if (mistakes == 2 || mistakes == 3)
		{
			mark = 4;
			cout << "4 ����� (������)";
		}
		else if (mistakes == 4 || mistakes == 5)
		{
			mark = 3;
			cout << "3 ����� (�����������������)";
		}
		else if (mistakes > 5)
		{
			mark = 2;
			cout << "2 ����� (�������������������)";
		}

		if (mistakes != 0)
		{
			cout << "\n\n�������, �� ������� ���� ���� �������� ������:";
			for (int i = 0; i < mistakes; i++)
			{
				cout << "\n\n" << i + 1 << ". " << Questions[ThemeNum].question[FailedQuestions[i]] << endl;
				for (int k = 0; k < variants; k++) cout << Questions[ThemeNum].answers[FailedQuestions[i]][k] << endl;
				cout << "���������� �����: " << Questions[ThemeNum].rightanswer[FailedQuestions[i]];
				cout << "\n��� �����: " << MistakeAnswers[i];
			}
		}

		Students[CurrentUser].tmark[ThemeNum] = mark;
		GradesRewriting(Students, CurrentUser);
		PrintStudentsDataFile(Students);

		cout << endl << endl;
		system("pause");
		system("cls");
	}
}

void FinalTest(Data *Students, const List Questions[], const int CurrentUser)
{
	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "�������� ����.\n";
	cout << "���������� ��������� ����, ������� ������� �� 40 �������� �� ���� �����.\n�� ��������� ����� ����� ���������� ���������� ������, ����� ����� ���������� ������.\n\n";
	cout << "�������� ����������: \n";
	cout << "40 - 37 ���������� ������� �� ������� (0 - 3 ������) - 5 ������\n";
	cout << "36 - 30 ���������� ������� �� ������� (4 - 10 ������) - 4 �����\n";
	cout << "29 - 21 ���������� ������� �� ������� (11 - 19 ������) - 3 �����\n";
	cout << "20 � ����� ���������� ������� �� ������� (20 � ����� ������) - 2 �����\n\n";

	system("pause");
	system("cls");

	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "�������� ���� �� ���� �����: " << endl;

	string RandQuestions[ftest * topics];
	string RandAnswers[ftest * topics][variants];
	int RandRightAnswers[ftest * topics];
	int RandQuestionsNum[ftest * topics];
	int t, rq;

	for (int i = 0; i < topics; i++)
	{
		for (int j = 0; j < ftest; j++)
		{
			if (j == 0) RandQuestionsNum[i * ftest + j] = rand() % Questions->n[i];
			else
			{
				do
				{
					t = 0;
					rq = rand() % Questions->n[i];
					for (int k = i * ftest; k < i * ftest + j; k++) if (rq == RandQuestionsNum[k]) t += 1;
				} while (t > 0);
				RandQuestionsNum[i * ftest + j] = rq;
			}
		}
	}
	int n = 0;
	for (int i = 0; i < ftest; i++)
	{
		for (int j = 0; j < topics; j++)
		{
			RandQuestions[n] = Questions[j].question[RandQuestionsNum[j * ftest + i]];
			for (int k = 0; k < variants; k++) RandAnswers[n][k] = Questions[j].answers[RandQuestionsNum[j * ftest + i]][k];
			RandRightAnswers[n] = Questions[j].rightanswer[RandQuestionsNum[j * ftest + i]];
			n += 1;
		}
	}

	string FailedQuestions[topics * ftest];
	string FailedAnswers[topics * ftest][variants];
	int FailedRightAnswers[topics * ftest];
	int MistakeAnswers[topics * ftest];
	int mistakes = 0;
	int mark;
	int o, l = 0;

	for (int i = 0; i < topics * ftest; i++)
	{
		cout << endl << i + 1 << ". " << RandQuestions[i] << endl;
		for (int j = 0; j < variants; j++) cout << RandAnswers[i][j] << endl;
		do
		{
			cout << "������� �����: ";
			IntInputValidation(o);
			if (o < 1 || o > 4) cout << "������! ��������� ������� ��������. ";
		} while (o < 1 || o > 4);
		if (o != RandRightAnswers[i])
		{
			mistakes += 1;
			FailedQuestions[l] = RandQuestions[i];
			for (int j = 0; j < variants; j++) FailedAnswers[l][j] = RandAnswers[i][j];
			FailedRightAnswers[l] = RandRightAnswers[i];
			MistakeAnswers[l] = o;
			l += 1;
		}
	}

	system("cls");

	cout << "������� ������� ������: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "�������� ���� �� ���� �����: " << endl;
	cout << "���������� ������: " << mistakes << " / " << ftest * topics << endl;
	cout << "������ : ";
	if (mistakes >= 0 && mistakes <= 3)
	{
		mark = 5;
		cout << "5 ������ (�������)";
	}
	else if (mistakes >= 4 && mistakes <= 10)
	{
		mark = 4;
		cout << "4 ����� (������)";
	}
	else if (mistakes >= 11 && mistakes <= 19)
	{
		mark = 3;
		cout << "3 ����� (�����������������)";
	}
	else if (mistakes >= 20)
	{
		mark = 2;
		cout << "2 ����� (�������������������)";
	}

	if (mistakes != 0)
	{
		cout << "\n\n�������, �� ������� ���� ���� �������� ������:";
		for (int i = 0; i < mistakes; i++)
		{
			cout << "\n\n" << i + 1 << ". " << FailedQuestions[i] << endl;
			for (int k = 0; k < variants; k++)
			{
				cout << FailedAnswers[i][k] << endl;
			}
			cout << "���������� �����: " << FailedRightAnswers[i];
			cout << "\n��� �����: " << MistakeAnswers[i];
		}
	}

	Students[CurrentUser].fmark = mark;
	GradesRewriting(Students, CurrentUser);
	PrintStudentsDataFile(Students);

	cout << endl << endl;
	system("pause");
}

void TopicGenerate(int RandQuestions[], const int ThemeNum, const List Questions[])
{
	int t;
	int rq;

	for (int i = 0; i < test; i++)
	{
		if (i == 0) RandQuestions[i] = rand() % Questions->n[ThemeNum];
		else
		{
			do
			{
				t = 0;
				rq = rand() % Questions->n[ThemeNum];
				for (int j = 0; j < i; j++) if (rq == RandQuestions[j]) t += 1;
			} while (t > 0);
			RandQuestions[i] = rq;
		}
	}
}

void GradesRewriting(Data *Students, const int CurrentUser)
{
	int Marks = 0;
	int count = 1;

	for (int i = 0; i < topics; i++)
	{
		if (Students[CurrentUser].tmark[i] != 0)
		{
			Marks += Students[CurrentUser].tmark[i];
			count += 1;
		}
	}

	Marks += Students[CurrentUser].fmark;

	Students[CurrentUser].average = round((double(Marks) / double(count)) * 100) / 100;
}