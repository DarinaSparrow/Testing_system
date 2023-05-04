//Ушенин Евгений
#pragma once

#include <ctime>

#include "Files.h"

void StudentsMenu();

void TopicTraining(Data *Students, const List Questions[], const int CurrentUser);
void TopicTesting(Data *Students, const List Questions[], const int CurrentUser);
void FinalTest(Data *Students, const List Questions[], const int CurrentUser);

void TopicGenerate(int RandQuestions[], const int ThemeNum, const List Questions[]);
void GradesRewriting(Data* Students, const int CurrentUser);