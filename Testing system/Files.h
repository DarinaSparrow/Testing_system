//Ушенин Евгений
#pragma once

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define profes 5
#define topics 8
#define variants 4
#define msq 50
#define test 10
#define ftest 5
#define ces 4

#if defined(max)
#undef max
#endif

struct Account
{
	string login;
	string password;
	string name;
	string surname;
};

struct List
{
	int n[topics];
	string theme;
	string question[msq];
	string answers[msq][variants];
	int rightanswer[msq];
};

struct Data
{
	int quantity;
	string login;
	string password;
	string name;
	string surname;
	int tmark[topics];
	int fmark;
	double average;
};

Data *StudentsMemoryAllocation(Data *Students);

void ReadProfessorsDataFile(Account *Professors);
void ReadQuestionsDataFile(List Questions[]);
void ReadStudentsDataFile(Data *Students);

void PrintQuestionsDataFile(const List Questions[]);
void PrintStudentsDataFile(const Data *Students);

string Encryption(string text);
string Decryption(string text);

void IntInputValidation(int &data);
void DoubleInputValidation(double &data);