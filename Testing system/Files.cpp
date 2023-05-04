#include "Files.h"

Data *StudentsMemoryAllocation(Data *Students)
{
	int size;
	string container;

	ifstream file_students;
	file_students.open("Students.txt", ios_base::in);

	if (!file_students.is_open()) cout << "Îøèáêà îòêğûòèÿ ôàéëà! " << endl;
	else
	{
		file_students >> container;
		size = stoi(Decryption(container));
	}

	file_students.close();

	Students = new Data[size + 1];

	return Students;
}

void ReadProfessorsDataFile(struct Account *Professors)
{
	string container;

	ifstream file_professors;
	file_professors.open("Professors.txt", ios_base::in);

	for (int i = 0; i < profes; i++)
	{
		file_professors >> container;
		Professors[i].login = Decryption(container);
		file_professors >> container;
		Professors[i].password = Decryption(container);
		file_professors >> container;
		Professors[i].name = Decryption(container);
		file_professors >> container;
		Professors[i].surname = Decryption(container);
	}

	file_professors.close();
}

void ReadQuestionsDataFile(struct List *Questions)
{
	string container;
	string garbage;

	ifstream file_questions;
	file_questions.open("Questions.txt", ios_base::in);

	if (!file_questions.is_open()) cout << "Îøèáêà îòêğûòèÿ ôàéëà! " << endl;
	else
	{
		for (int i = 0; i < topics; i++)
		{
			file_questions >> container;
			Questions->n[i] = stoi(Decryption(container));
		}
		getline(file_questions, garbage);
		for (int i = 0; i < topics; i++)
		{
			getline(file_questions, container);
			Questions[i].theme = Decryption(container);
			for (int j = 0; j < Questions->n[i]; j++)
			{
				getline(file_questions, container);
				Questions[i].question[j] = Decryption(container);
				for (int k = 0; k < variants; k++)
				{
					getline(file_questions, container);
					Questions[i].answers[j][k] = Decryption(container);
				}
				file_questions >> container;
				Questions[i].rightanswer[j] = stoi(Decryption(container));
				getline(file_questions, garbage);
			}
		}
	}

	file_questions.close();
}

void ReadStudentsDataFile(Data *Students)
{
	string container;

	ifstream file_students;
	file_students.open("Students.txt", ios_base::in);

	if (!file_students.is_open()) cout << "Îøèáêà îòêğûòèÿ ôàéëà! " << endl;
	else
	{
		file_students >> container;
		Students->quantity = stoi(Decryption(container));
		for (int i = 0; i < Students->quantity; i++)
		{
			file_students >> container;
			Students[i].login = Decryption(container);
			file_students >> container;
			Students[i].password = Decryption(container);
			file_students >> container;
			Students[i].name = Decryption(container);
			file_students >> container;
			Students[i].surname = Decryption(container);
			for (int j = 0; j < topics; j++)
			{
				file_students >> container;
				Students[i].tmark[j] = stoi(Decryption(container));
			}
			file_students >> container;
			Students[i].fmark = stoi(Decryption(container));
			file_students >> container;
			Students[i].average = stod(Decryption(container));
		}
	}

	file_students.close();
}

void PrintQuestionsDataFile(const List Questions[])
{
	string container;

	ofstream file_questions;
	file_questions.open("Questions.txt", ios_base::out);

	if (!file_questions.is_open()) cout << "Îøèáêà îòêğûòèÿ ôàéëà! " << endl;
	else
	{
		for (int i = 0; i < topics; i++)
		{
			if (i != 7)
			{
				container = Encryption(to_string(Questions->n[i]));
				file_questions << container << " ";
			}
			else
			{
				container = Encryption(to_string(Questions->n[i]));
				file_questions << container << endl;
			}
		}
		for (int i = 0; i < topics; i++)
		{
			container = Encryption(Questions[i].theme);
			file_questions << container << endl;
			for (int j = 0; j < Questions->n[i]; j++)
			{
				container = Encryption(Questions[i].question[j]);
				file_questions << container << endl;
				for (int k = 0; k < variants; k++)
				{
					container = Encryption(Questions[i].answers[j][k]);
					file_questions << container << endl;
				}
				container = Encryption(to_string(Questions[i].rightanswer[j]));
				file_questions << container << endl;
			}
		}
	}

	file_questions.close();
}

void PrintStudentsDataFile(const Data *Students)
{
	string container;

	ofstream file_students;
	file_students.open("Students.txt", ios_base::out);

	if (!file_students.is_open()) cout << "Îøèáêà îòêğûòèÿ ôàéëà!" << endl;
	else
	{
		container = Encryption(to_string(Students->quantity));
		file_students << container << endl;
		for (int i = 0; i < Students->quantity; i++)
		{
			container = Encryption(Students[i].login);
			file_students << container << endl;
			container = Encryption(Students[i].password);
			file_students << container << endl;
			container = Encryption(Students[i].name);
			file_students << container << endl;
			container = Encryption(Students[i].surname);
			file_students << container << endl;
			for (int j = 0; j < 8; j++)
			{
				if (j != 7)
				{
					container = Encryption(to_string(Students[i].tmark[j]));
					file_students << container << " ";
				}
				else
				{
					container = Encryption(to_string(Students[i].tmark[j]));
					file_students << container << endl;
				}
			}
			container = Encryption(to_string(Students[i].fmark));
			file_students << container << endl;
			container = Encryption(to_string(Students[i].average));
			file_students << container << endl;
		}
	}

	file_students.close();
}

string Encryption(string text)
{
	string Alf = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzÀàÁáÂâÃãÄäÅå¨¸ÆæÇçÈèÉéÊêËëÌìÍíÎîÏïĞğÑñÒòÓóÔôÕõÖö×÷ØøÙùúÛûüİıŞşßÿ1234567890.,-+:;=?<>#(){}[]/*&_'\"%$! ";
	string res = "";

	for (int i = 0; i < text.length(); i++)
	{
		for (int j = 0; j < Alf.length(); j++)
		{
			if (text[i] == Alf[j])
			{
				if (j + ces > Alf.length()) res += Alf[j + ces - Alf.length()];
				else res += Alf[j + ces];
			}
		}
	}

	return res;
}

string Decryption(string text)
{
	string Alf = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzÀàÁáÂâÃãÄäÅå¨¸ÆæÇçÈèÉéÊêËëÌìÍíÎîÏïĞğÑñÒòÓóÔôÕõÖö×÷ØøÙùúÛûüİıŞşßÿ1234567890.,-+:;=?<>#(){}[]/*&_'\"%$! ";
	string res = "";

	for (int i = 0; i < text.length(); i++)
	{
		for (int j = 0; j < Alf.length(); j++)
		{
			if (text[i] == Alf[j])
			{
				if (j - ces < 0) res += Alf[j - ces + Alf.length()];
				else res += Alf[j - ces];
			}
		}
	}

	return res;
}

void IntInputValidation(int &data)
{
	bool input;

	do
	{
		input = true;
		cin >> data;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ïîæàëóéñòà, ââåäèòå öåëîå ÷èñëî: ";
			input = false;
		}
	} while (!input);
}

void DoubleInputValidation(double &data)
{
	bool input;

	do
	{
		input = true;
		cin >> data;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ïîæàëóéñòà, ââåäèòå öåëîå ÷èñëî: ";
			input = false;
		}
	} while (!input);
}