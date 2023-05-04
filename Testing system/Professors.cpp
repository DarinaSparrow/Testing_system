#include "Professors.h"

void ProfessorMenu()
{
	int work, current_professor;
	string current_login, current_password;
	struct Account Professors[profes];
	bool to_be = true;

	ReadProfessorsDataFile(Professors);

	cout << "Если вы хотите выйти из режима преподавателя, введите вместо логина 0." << endl;

	do
	{
		cout << "Введите логин: ";
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
			if (to_be == false) cout << "Такой учётной записи не существует." << endl;
		}
	} while ((to_be == false) && (current_login != "0"));

	if (current_login == "0") system("cls");

	else
	{
		do
		{
			cout << "Введите пароль: ";
			cin >> current_password;
			if (current_password != Professors[current_professor].password) cout << "Введённый пароль неверный." << endl;
		} while (current_password != Professors[current_professor].password);

		system("cls");

		do
		{
			cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

			cout << "Выберите действие: " << endl;
			cout << "1. Редактирование вопросов" << endl;
			cout << "2. Работа со списком студентов" << endl;
			cout << "(Для выхода из учётной записи введите 0)" << endl << endl;

			do
			{
				cout << "Ваш выбор: ";
				IntInputValidation(work);
				if ((work < 0) || (work > 2)) cout << "Ошибка! Проверьте входное значение." << endl;
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
		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "Редактирование вопросов: " << endl;
		cout << "1. Удаление" << endl;
		cout << "2. Добавление" << endl;
		cout << "3. Изменение" << endl;
		cout << "(Для выхода из режима введите 0)" << endl << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(work);
			if ((work < 0) || (work > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	ReadQuestionsDataFile(Questions);

	cout << "Список имеющихся тем: " << endl;
	cout << "Тема 1. Циклы" << endl;
	cout << "Тема 2. Массивы" << endl;
	cout << "Тема 3. Строки" << endl;
	cout << "Тема 4. Рекурсия" << endl;
	cout << "Тема 5. Структуры" << endl;
	cout << "Тема 6. Файлы" << endl;
	cout << "Тема 7. Адреса и указатели" << endl;
	cout << "Тема 8. Динамическая память" << endl;
	cout << "Введите тему, в которой хотите удалить вопрос: ";

	do
	{
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > topics))
		{
			cout << "Ошибка! Проверьте входное значение." << endl;
			cout << "Введите тему, в которой хотите удалить вопрос: ";
		}
	} while ((current_topic < 1) || (current_topic > topics));
	current_topic -= 1;

	cout << endl;
	cout << Questions[current_topic].theme << ":" << endl;
	for (int i = 0; i < Questions->n[current_topic]; i++) cout << i + 1 << ". " << Questions[current_topic].question[i] << endl;
	cout << endl;

	do
	{
		cout << "Введите вопрос, который хотите удалить: ";
		IntInputValidation(current_question);
		if ((current_question < 1) || (current_question > Questions->n[current_topic])) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((current_question < 1) || (current_question > Questions->n[current_topic]));
	current_question -= 1;

	cout << endl << "Вопрос \"" << Questions[current_topic].question[current_question] << "\" был удалён." << endl << endl;

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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	ReadQuestionsDataFile(Questions);

	cout << "Список имеющихся тем: " << endl;
	cout << "Тема 1. Циклы" << endl;
	cout << "Тема 2. Массивы" << endl;
	cout << "Тема 3. Строки" << endl;
	cout << "Тема 4. Рекурсия" << endl;
	cout << "Тема 5. Структуры" << endl;
	cout << "Тема 6. Файлы" << endl;
	cout << "Тема 7. Адреса и указатели" << endl;
	cout << "Тема 8. Динамическая память" << endl;
	cout << "Введите тему, в которую хотите добавить вопрос: ";

	do
	{
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > topics))
		{
			cout << "Ошибка! Проверьте входное значение." << endl;
			cout << "Введите тему, в которую хотите добавить вопрос: ";
		}
	} while ((current_topic < 1) || (current_topic > topics));
	current_topic -= 1;

	cout << endl;

	cout << "Введите вопрос: ";
	getchar();
	getline(cin, Questions[current_topic].question[Questions->n[current_topic]], '\n');
	for (int k = 0; k < variants; k++)
	{
		cout << "Введите " << k + 1 << " вариант ответа: ";
		std::string part1 = std::to_string(k + 1);
		getline(cin, part2, '\n');
		Questions[current_topic].answers[Questions->n[current_topic]][k] = part1 + ") " + part2;
	}
	do
	{
		cout << "Введите номер правильного ответа: ";
		IntInputValidation(Questions[current_topic].rightanswer[Questions->n[current_topic]]);
		if ((Questions[current_topic].rightanswer[Questions->n[current_topic]] < 1) || (Questions[current_topic].rightanswer[Questions->n[current_topic]] > variants)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((Questions[current_topic].rightanswer[Questions->n[current_topic]] < 1) || (Questions[current_topic].rightanswer[Questions->n[current_topic]] > variants));
	Questions->n[current_topic] += 1;

	PrintQuestionsDataFile(Questions);

	cout << endl << "Вопрос был добавлен в раздел \"" << Questions[current_topic].theme << "\"." << endl << endl;

	system("pause");
	system("cls");
}

void Change(struct Account *Professors, int current_professor)
{
	int current_topic, current_question;
	string part2, old_question;
	struct List Questions[topics];

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	ReadQuestionsDataFile(Questions);

	cout << "Список имеющихся тем: " << endl;
	cout << "Тема 1. Циклы" << endl;
	cout << "Тема 2. Массивы" << endl;
	cout << "Тема 3. Строки" << endl;
	cout << "Тема 4. Рекурсия" << endl;
	cout << "Тема 5. Структуры" << endl;
	cout << "Тема 6. Файлы" << endl;
	cout << "Тема 7. Адреса и указатели" << endl;
	cout << "Тема 8. Динамическая память" << endl;
	cout << "Введите тему, в которой хотите изменить вопрос: ";

	do
	{
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > topics))
		{
			cout << "Ошибка! Проверьте входное значение." << endl;
			cout << "Введите тему, в которой хотите изменить вопрос: ";
		}
	} while ((current_topic < 1) || (current_topic > topics));
	current_topic -= 1;

	cout << endl;
	cout << Questions[current_topic].theme << ":" << endl;
	for (int i = 0; i < Questions->n[current_topic]; i++)
	{
		cout << i + 1 << ". " << Questions[current_topic].question[i] << endl;
		for (int j = 0; j < variants; j++) cout << Questions[current_topic].answers[i][j] << endl;
		cout << "Правиьный ответ: " << Questions[current_topic].rightanswer[i]<< endl << endl;
	}

	do
	{
		cout << "Введите вопрос, который хотите изменить: ";
		IntInputValidation(current_question);
		if ((current_question < 1) || (current_question > Questions->n[current_topic])) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((current_question < 1) || (current_question > Questions->n[current_topic]));
	current_question -= 1;

	old_question = Questions[current_topic].question[current_question];

	cout << "Введите новый вопрос: ";
	getchar();
	getline(cin, Questions[current_topic].question[current_question], '\n');
	for (int k = 0; k < variants; k++)
	{
		cout << "Введите " << k + 1 << " вариант ответа: ";
		std::string part1 = std::to_string(k + 1);
		getline(cin, part2, '\n');
		Questions[current_topic].answers[current_question][k] = part1 + ") " + part2;
	}
	do
	{
		cout << "Введите номер правильного ответа: ";
		IntInputValidation(Questions[current_topic].rightanswer[current_question]);
		if ((Questions[current_topic].rightanswer[current_question] < 1) || (Questions[current_topic].rightanswer[current_question] > variants)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((Questions[current_topic].rightanswer[current_question] < 1) || (Questions[current_topic].rightanswer[current_question] > variants));

	PrintQuestionsDataFile(Questions);

	cout << endl << "Вопрос \"" << old_question << "\" был изменён на \"" << Questions[current_topic].question[current_question] << "\"." << endl << endl;

	system("pause");
	system("cls");
}

void WorkWithStudents(struct Account* Professors, int current_professor)
{
	int work;

	do
	{
		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "Работа со списком студентов: " << endl;
		cout << "1. Удаление и регистрация студентов" << endl;
		cout << "2. Изменение прогресса студентов" << endl;
		cout << "3. Вывод списка студентов с оценками" << endl;
		cout << "(Для выхода из режима введите 0)" << endl << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(work);
			if ((work < 0) || (work > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Выберите действие: " << endl;
	cout << "1. Удаление учётной записи студента" << endl;
	cout << "2. Создание новой учётной записи студента" << endl;
	cout << "(Для выхода из режима введите 0)" << endl << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(work);
		if ((work < 0) || (work > 2)) cout << "Ошибка! Проверьте входное значение." << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	do
	{
		cout << "Вы хотите ознакомится со списком студентов? ";
		cin >> list;
if ((list == "Да") || (list == "да"))
{
	cout << endl;
	for (int i = 0; i < Students->quantity; i++) cout << Students[i].surname << " " << Students[i].name << endl;
}
else if ((list != "Нет") && (list != "нет")) cout << "Пожалуйста, введите только да или нет!" << endl;
	} while ((list != "Да") && (list != "да") && (list != "Нет") && (list != "нет"));
	cout << endl;

	do
	{
		cout << "Введите фамилию студента, чью учётную запись хотите удалить: ";
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
		if (to_be == false) cout << "Студента с такой учётной записью не существует." << endl;
	} while (to_be == false);

	system("cls");
	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Существует учётная запись студента с именем " << Students[current_student].surname << " " << Students[current_student].name << "." << endl;
	do
	{
		cout << "Вы дейтвительно хотите её удалить? ";
		cin >> confirmation;
		if ((confirmation == "Да") || (confirmation == "да"))
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
			cout << endl << "Учётная запись удалена." << endl << endl;
			system("pause");
			system("cls");
		}
		else if ((confirmation == "Нет") || (confirmation == "нет"))
		{
			cout << endl;
			system("pause");
			system("cls");
		}
		else cout << "Пожалуйста, введите только да или нет!" << endl;
	} while ((confirmation != "Да") && (confirmation != "да") && (confirmation != "Нет") && (confirmation != "нет"));

	PrintStudentsDataFile(Students);

	delete[]Students;
}

void StudentRegistration(struct Account* Professors, int current_professor)
{
	int current_mark, i, current_position;
	double sum, count;
	string glass_surname, glass_name;
	string themes[topics] = { "Циклы", "Массивы", "Строки", "Рекурсия", "Структуры", "Файлы", "Адреса и указатели", "Динамическая память", };
	struct Data* Students = NULL;
	bool flag1, flag2, FLAG, flag_name;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Для создания новой учётной записи студента введите все необходимые данные." << endl << endl;

	Students->quantity += 1;

	cout << "Фамилия: ";
	cin >> glass_surname;

	FLAG = true;
	flag_name = false;
	flag1 = false;
	i = 0;
	while (flag1 == false)
	{
		if (glass_surname == Students[i].surname)
		{
			cout << "Имя: ";
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
					cout << endl << "Учётная запись студента уже сучществует." << endl << endl;
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
			cout << "Имя: ";
			cin >> Students[current_position].name;
		}
		else Students[current_position].name = glass_name;
		sum = 0;
		count = 0;
		cout << endl << "Оценки по тестам (в случае, если студент не проходил тест, введите 0):" << endl;
		for (int i = 0; i < topics; i++)
		{
			do
			{
				cout << "Оценка за тест по теме \"" << themes[i] << "\": ";
				IntInputValidation(current_mark);
				if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
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
			cout << "Оценка за итоговый тест: ";
			IntInputValidation(Students[current_position].fmark);
			if (((Students[current_position].fmark < 2) || (Students[current_position].fmark > 5)) && (Students[current_position].fmark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while (((Students[current_position].fmark < 2) || (Students[current_position].fmark > 5)) && (Students[current_position].fmark != 0));
		if (Students[current_position].fmark != 0)
		{
			sum += Students[current_position].fmark;
			count += 1;
		}
		Students[current_position].average = round(sum / count * 100) / 100;
		cout << endl << "Придумайте логин и пароль для новой учётной записи студента." << endl;
		do
		{
			cout << "Логин: ";
			cin >> Students[current_position].login;
			if (Students[current_position].login.length() < 7) cout << "Логин должен состоять минимум из 7 символов." << endl;
		} while (Students[current_position].login.length() < 7);
		do
		{
			cout << "Пароль: ";
			cin >> Students[current_position].password;
			if (Students[current_position].password.length() < 10) cout << "Пароль должен состоять минимум из 10 символов." << endl;
		} while (Students[current_position].password.length() < 10);

		PrintStudentsDataFile(Students);
		cout << endl << "Учётная запись создана." << endl << endl;
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
	string themes[topics] = { "Циклы", "Массивы", "Строки", "Рекурсия", "Структуры", "Файлы", "Адреса и указатели", "Динамическая память", };
	struct Data* Students = NULL;
	bool to_be = true;

	Students = StudentsMemoryAllocation(Students);
	ReadStudentsDataFile(Students);

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	do
	{
		cout << "Вы хотите ознакомится со списком студентов? ";
		cin >> list;
		if ((list == "Да") || (list == "да"))
		{
			cout << endl;
			for (int i = 0; i < Students->quantity; i++) cout << Students[i].surname << " " << Students[i].name << endl;
		}
		else if ((list != "Нет") && (list != "нет")) cout << "Пожалуйста, введите только да или нет!" << endl;
	} while ((list != "Да") && (list != "да") && (list != "Нет") && (list != "нет"));
	cout << endl;

	do
	{
		cout << "Введите фамилию студента, чей прогресс хотите изменить: ";
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
		if (to_be == false) cout << "Студента с такой учётной записью не существует." << endl;
	} while ((to_be == false));

	do
	{
		system("cls");
		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << Students[current_student].surname << " " << Students[current_student].name << endl << endl;

		for (int i = 0; i < topics; i++)
		{
			cout << i + 1 << ". Оценка за тест по теме \"" << themes[i] << "\": ";
			if (Students[current_student].tmark[i] == 0) cout << "тест не пройден" << endl;
			else cout << Students[current_student].tmark[i] << endl;
		}
		cout << "9. Оценка за итоговый тест: ";
		if (Students[current_student].fmark == 0) cout << "тест не пройден" << endl;
		else cout << Students[current_student].fmark << endl;
		cout << "10. Средний балл: " << Students[current_student].average << endl << endl;

		cout << "Если вы хотите выйти, введите вместо параметра 0." << endl;
		do
		{
			cout << "Введите параметр, который хотите изменить: ";
			IntInputValidation(parameter);
			if ((parameter < 0) || (parameter > 10)) cout << "Ошибка! Проверьте входное значение." << endl;
			else if (parameter == 10) cout << "Средний балл студента вычисляется автоматически." << endl;
		} while ((parameter < 0) || (parameter > 9));

		if (parameter == 9)
		{
			cout << endl << "Если вы хотите удалить имеющуюся оценку, введите 0." << endl;
			do
			{
				cout << "Введите новую оценку за итоговый тест: ";
				IntInputValidation(Students[current_student].fmark);
				if (((Students[current_student].fmark < 2) || (Students[current_student].fmark > 5)) && (Students[current_student].fmark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
			} while (((Students[current_student].fmark < 2) || (Students[current_student].fmark > 5)) && (Students[current_student].fmark != 0));
		}
		else if (parameter != 0)
		{
			cout << endl << "Если вы хотите удалить имеющуюся оценку, введите 0." << endl;
			do
			{
				cout << "Введите новую оценку за тест по теме \"" << themes[parameter - 1] << "\": ";
				IntInputValidation(Students[current_student].tmark[parameter - 1]);
				if (((Students[current_student].tmark[parameter - 1] < 2) || (Students[current_student].tmark[parameter - 1] > 5)) && (Students[current_student].fmark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Выберите действие: " << endl;
	cout << "1. Вывод списка студентов с оценками по всем темам" << endl;
	cout << "2. Вывод списка студентов с оценками по конкретной теме" << endl;
	cout << "3. Вывод списка студентов с оценками по итоговому тесту" << endl;
	cout << "4. Вывод списка студентов со средним баллом" << endl;
	cout << "(Для выхода из режима введите 0)" << endl << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(work);
		if ((work < 0) || (work > 4)) cout << "Ошибка! Проверьте входное значение." << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Выберите дополнительную опцию: " << endl;
	cout << "1. Фильтрация" << endl;
	cout << "2. Сортировка" << endl;
	cout << "3. Ничего из вышеперечисленного" << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((work < 1) || (work > 3));

	system("cls");

	switch(work)
	{
	case 1:

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "Выберите критерий фильтрации: " << endl;
		cout << "1. По оценке за тест по теме 1" << endl;
		cout << "2. По оценке за тест по теме 2" << endl;
		cout << "3. По оценке за тест по теме 3" << endl;
		cout << "4. По оценке за тест по теме 4" << endl;
		cout << "5. По оценке за тест по теме 5" << endl; 
		cout << "6. По оценке за тест по теме 6" << endl;
		cout << "7. По оценке за тест по теме 7" << endl;
		cout << "8. По оценке за тест по теме 8" << endl;
		cout << "9. По оценке за итоговый тест" << endl;
		cout << "10. По среднему баллу" << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(method);
			if ((method < 1) || (method > 10)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((method < 1) || (method > 10));

		cout <<  endl;

		if (method != 10)
		{
			cout << "Если вы хотите увидеть список студентов, не сдавших выбранный тест, введите 0. " << endl;
			do
			{
				cout << "Введите оценку: ";
				IntInputValidation(current_mark);
				if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
			} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));
		}
		else
		{
			do
			{
				cout << "Введите минимальное значение среднего балла: ";
				DoubleInputValidation(min_mark);
				cout << "Введите максимальное значение среднего балла: ";
				DoubleInputValidation(max_mark);
				if ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5)) cout << "Ошибка! Проверьте входное значение." << endl;
			} while ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5));
			if (min_mark > max_mark)
			{
				glass = min_mark;
				min_mark = max_mark;
				max_mark = glass;
			}
		}

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Тема1 | Тема2 | Тема3 | Тема4 | Тема5 | Тема6 | Тема7 | Тема8 | Итоговый тест | Средний балл |" << endl;
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

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "Выберите критерий сортировки: " << endl;
		cout << "1. По оценке за тест по теме 1" << endl;
		cout << "2. По оценке за тест по теме 2" << endl;
		cout << "3. По оценке за тест по теме 3" << endl;
		cout << "4. По оценке за тест по теме 4" << endl;
		cout << "5. По оценке за тест по теме 5" << endl;
		cout << "6. По оценке за тест по теме 6" << endl;
		cout << "7. По оценке за тест по теме 7" << endl;
		cout << "8. По оценке за тест по теме 8" << endl;
		cout << "9. По оценке за итоговый тест" << endl;
		cout << "10. По среднему баллу" << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(method);
			if ((method < 1) || (method > 10)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((method < 1) || (method > 10));

		cout << endl;
		cout << "Выберите способ сортировки: " << endl;
		cout << "1. От лучшего результата к худшему" << endl;
		cout << "2. От хужшего результата к лучшему" << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Тема1 | Тема2 | Тема3 | Тема4 | Тема5 | Тема6 | Тема7 | Тема8 | Итоговый тест | Средний балл |" << endl;
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

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Тема1 | Тема2 | Тема3 | Тема4 | Тема5 | Тема6 | Тема7 | Тема8 | Итоговый тест | Средний балл |" << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Выберите тему, по которой хотите видеть оценки: " << endl;
	cout << "1. Циклы" << endl;
	cout << "2. Массивы" << endl;
	cout << "3. Строки" << endl;
	cout << "4. Рекурсия" << endl;
	cout << "5. Структуры" << endl;
	cout << "6. Файлы" << endl;
	cout << "7. Адреса и указатели" << endl;
	cout << "8. Динамическая память" << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(current_topic);
		if ((current_topic < 1) || (current_topic > 8)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((current_topic < 1) || (current_topic > 8));

	cout << endl;
	cout  << "Выберите дополнительную опцию: " << endl;
	cout << "1. Фильтрация" << endl;
	cout << "2. Сортировка" << endl;
	cout << "3. Ничего из вышеперечисленного" << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((work < 1) || (work > 3));

	switch (work)
	{
	case 1:

		cout << endl << "Если вы хотите увидеть список студентов, не сдавших выбранный тест, введите 0. " << endl;
		do
		{
			cout << "Введите оценку: ";
			IntInputValidation(current_mark);
			if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "---------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Тема" << current_topic << " |" << endl;
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
		cout << "Выберите способ сортировки: " << endl;
		cout << "1. От лучшего результата к худшему" << endl;
		cout << "2. От хужшего результата к лучшему" << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "---------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Тема" << current_topic << " |" << endl;
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

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "---------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Тема" << current_topic << " |" << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Выберите дополнительную опцию: " << endl;
	cout << "1. Фильтрация" << endl;
	cout << "2. Сортировка" << endl;
	cout << "3. Ничего из вышеперечисленного" << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((work < 1) || (work > 3));

	switch (work)
	{
	case 1:

		cout << endl << "Если вы хотите увидеть список студентов, не сдавших итоговый тест, введите 0. " << endl;
		do
		{
			cout << "Введите оценку: ";
			IntInputValidation(current_mark);
			if (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while (((current_mark < 2) || (current_mark > 5)) && (current_mark != 0));

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "-----------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Итоговый тест |" << endl;
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
		cout << "Выберите способ сортировки: " << endl;
		cout << "1. От лучшего результата к худшему" << endl;
		cout << "2. От хужшего результата к лучшему" << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "-----------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Итоговый тест |" << endl;
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

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "-----------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Итоговый тест |" << endl;
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

	cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

	cout << "Выберите дополнительную опцию: " << endl;
	cout << "1. Фильтрация" << endl;
	cout << "2. Сортировка" << endl;
	cout << "3. Ничего из вышеперечисленного" << endl;

	do
	{
		cout << "Ваш выбор: ";
		IntInputValidation(work);
		if ((work < 1) || (work > 3)) cout << "Ошибка! Проверьте входное значение." << endl;
	} while ((work < 1) || (work > 3));

	switch (work)
	{
	case 1:

		cout << endl;

		do
		{
			cout << "Введите минимальное значение среднего балла: ";
			DoubleInputValidation(min_mark);
			cout << "Введите максимальное значение среднего балла: ";
			DoubleInputValidation(max_mark);
			if ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((min_mark < 2) || (min_mark > 5) || (max_mark < 2) || (max_mark > 5));

		if (min_mark > max_mark)
		{
			glass = min_mark;
			min_mark = max_mark;
			max_mark = glass;
		}

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "----------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Средний балл |" << endl;
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
		cout << "Выберите способ сортировки: " << endl;
		cout << "1. От лучшего результата к худшему" << endl;
		cout << "2. От хужшего результата к лучшему" << endl;

		do
		{
			cout << "Ваш выбор: ";
			IntInputValidation(way);
			if ((way < 1) || (way > 2)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((way < 1) || (way > 2));

		system("cls");

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		k = 0;

		cout << "----------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Средний балл |" << endl;
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

		cout << "Текущая учётная запись: " << Professors[current_professor].name << " " << Professors[current_professor].surname << endl << endl;

		cout << "----------------------------------------------------" << endl;
		cout << "|  №  |    Фамилия    |     Имя     | Средний балл |" << endl;
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