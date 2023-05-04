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

	cout << "Если вы хотите выйти из режима студента, введите вместо логина 0." << endl;

	do
	{
		cout << "Введите логин: ";
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
			if (ToBe == false) cout << "Такой учётной записи не существует." << endl;
		}
	} while ((ToBe == false) && (CurrentLogin != "0"));

	if (CurrentLogin == "0") system("cls");

	else
	{
		do
		{
			cout << "Введите пароль: ";
			cin >> CurrentPassword;
			if (CurrentPassword != Students[CurrentUser].password) cout << "Введённый пароль неверный." << endl;
		} while (CurrentPassword != Students[CurrentUser].password);

		system("cls");

		do
		{
			cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

			cout << "Выберите действие: " << endl;
			cout << "1. Пройти треннинг по теме" << endl;
			cout << "2. Пройти тестирование по теме" << endl;
			cout << "3. Пройти итоговый тест" << endl;
			cout << "(Для выхода из учётной записи введите 0)" << endl << endl;

			do
			{
				cout << "Ваш выбор: ";
				IntInputValidation(menu);
				if ((menu < 0) || (menu > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
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

	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "Тренинг по теме.\n";
	cout << "Необходимо выполнить тест, который состоит из 10 вопросов по выбранной теме.\nПереход к следующему вопросу не происходит до тех пор, пока не дан правильный ответ на предыдущий.\n\n";

	cout << "Выберите тему: " << endl;
	cout << "1. Циклы" << endl;
	cout << "2. Массивы" << endl;
	cout << "3. Строки" << endl;
	cout << "4. Рекурсия" << endl;
	cout << "5. Структуры" << endl;
	cout << "6. Файлы" << endl;
	cout << "7. Адреса и указатели" << endl;
	cout << "8. Динамическая память" << endl;
	cout << "(Для выхода из режима введите 0)" << endl << endl;

	do 
	{
		cout << "Ваш выбор: ";
		IntInputValidation(theme);
		if ((theme < 0) || (theme > 8)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((theme < 0) || (theme > 8));

	system("cls");

	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

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
				cout << "Введите ответ: ";
				IntInputValidation(o);
				if (o < 1 || o > 4) cout << "Ошибка! Проверьте входное значение. ";
				else if (o != Questions[ThemeNum].rightanswer[RandQuestions[i]]) cout << "Введен неверный ответ. ";
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

	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "Тестирование по теме.\n";
	cout << "Необходимо выполнить тест, который состоит из 10 вопросов по выбранной теме.\nПо окончании теста будет подсчитано количество ошибок, будут выведены неправильно отвеченные вопросы.\nТакже будет выставлена оценка\n\n";
	cout << "Критерии оценивания: \n";
	cout << "10 - 9 правильных ответов на вопросы (0 - 1 ошибки) - 5 баллов\n";
	cout << "8 - 7 правильных ответов на вопросы (2 - 3 ошибки) - 4 балла\n";
	cout << "6 - 5 правильных ответов на вопросы (4 - 5 ошибок) - 3 балла\n";
	cout << "4 и менее правильных ответов на вопросы (6 и более ошибок) - 2 балла\n\n";

	cout << "Выберите тему: " << endl;
	cout << "1. Циклы" << endl;
	cout << "2. Массивы" << endl;
	cout << "3. Строки" << endl;
	cout << "4. Рекурсия" << endl;
	cout << "5. Структуры" << endl;
	cout << "6. Файлы" << endl;
	cout << "7. Адреса и указатели" << endl;
	cout << "8. Динамическая память" << endl;
	cout << "(Для выхода из режима введите 0)" << endl << endl;

	do 
	{
		cout << "Ваш выбор: ";
		IntInputValidation(theme);
		if ((theme < 0) || (theme > 8)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((theme < 0) || (theme > 8));

	system("cls");

	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

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
				cout << "Введите ответ: ";
				IntInputValidation(o);
				if (o < 1 || o > 4) cout << "Ошибка! Проверьте входное значение. ";
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

		cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

		cout << Questions[ThemeNum].theme << endl;
		cout << "Количество ошибок: " << mistakes << " / " << test << endl;
		cout << "Оценка : ";
		if (mistakes == 0 || mistakes == 1)
		{
			mark = 5;
			cout << "5 баллов (отлично)";
		}
		else if (mistakes == 2 || mistakes == 3)
		{
			mark = 4;
			cout << "4 балла (хорошо)";
		}
		else if (mistakes == 4 || mistakes == 5)
		{
			mark = 3;
			cout << "3 балла (удовлетворительно)";
		}
		else if (mistakes > 5)
		{
			mark = 2;
			cout << "2 балла (неудовлетворительно)";
		}

		if (mistakes != 0)
		{
			cout << "\n\nВопросы, на которые были даны неверные ответы:";
			for (int i = 0; i < mistakes; i++)
			{
				cout << "\n\n" << i + 1 << ". " << Questions[ThemeNum].question[FailedQuestions[i]] << endl;
				for (int k = 0; k < variants; k++) cout << Questions[ThemeNum].answers[FailedQuestions[i]][k] << endl;
				cout << "Правильный ответ: " << Questions[ThemeNum].rightanswer[FailedQuestions[i]];
				cout << "\nВаш ответ: " << MistakeAnswers[i];
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
	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "Итоговый тест.\n";
	cout << "Необходимо выполнить тест, который состоит из 40 вопросов по всем темам.\nПо окончании теста будет подсчитано количество ошибок, также будет выставлена оценка.\n\n";
	cout << "Критерии оценивания: \n";
	cout << "40 - 37 правильных ответов на вопросы (0 - 3 ошибки) - 5 баллов\n";
	cout << "36 - 30 правильных ответов на вопросы (4 - 10 ошибок) - 4 балла\n";
	cout << "29 - 21 правильных ответов на вопросы (11 - 19 ошибок) - 3 балла\n";
	cout << "20 и менее правильных ответов на вопросы (20 и более ошибок) - 2 балла\n\n";

	system("pause");
	system("cls");

	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "Итоговый тест по всем темам: " << endl;

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
			cout << "Введите ответ: ";
			IntInputValidation(o);
			if (o < 1 || o > 4) cout << "Ошибка! Проверьте входное значение. ";
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

	cout << "Текущая учётная запись: " << Students[CurrentUser].name << " " << Students[CurrentUser].surname << endl << endl;

	cout << "Итоговый тест по всем темам: " << endl;
	cout << "Количество ошибок: " << mistakes << " / " << ftest * topics << endl;
	cout << "Оценка : ";
	if (mistakes >= 0 && mistakes <= 3)
	{
		mark = 5;
		cout << "5 баллов (отлично)";
	}
	else if (mistakes >= 4 && mistakes <= 10)
	{
		mark = 4;
		cout << "4 балла (хорошо)";
	}
	else if (mistakes >= 11 && mistakes <= 19)
	{
		mark = 3;
		cout << "3 балла (удовлетворительно)";
	}
	else if (mistakes >= 20)
	{
		mark = 2;
		cout << "2 балла (неудовлетворительно)";
	}

	if (mistakes != 0)
	{
		cout << "\n\nВопросы, на которые были даны неверные ответы:";
		for (int i = 0; i < mistakes; i++)
		{
			cout << "\n\n" << i + 1 << ". " << FailedQuestions[i] << endl;
			for (int k = 0; k < variants; k++)
			{
				cout << FailedAnswers[i][k] << endl;
			}
			cout << "Правильный ответ: " << FailedRightAnswers[i];
			cout << "\nВаш ответ: " << MistakeAnswers[i];
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