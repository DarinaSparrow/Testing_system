//Корниенко Дарина
#pragma once

#include <iomanip>
#include <algorithm>

#include "Files.h"

void ProfessorMenu();

void QuestionEditor(struct Account *Professors, int current_professor);
void Deletion(struct Account *Professors, int current_professor);
void Adding(struct Account *Professors, int current_professor);
void Change(struct Account *Professors, int current_professor);

void WorkWithStudents(struct Account *Professors, int current_professor);
void DeletionAndRegistration(struct Account *Professors, int current_professor);
void DeletionOfStudent(struct Account *Professors, int current_professor);
void StudentRegistration(struct Account *Professors, int current_professor);
void ChangingProgress(struct Account *Professors, int current_professor);
void ListOutput(struct Account *Professors, int current_professor);
void AllTopics(struct Account *Professors, int current_professor);
void SpecificTopic(struct Account *Professors, int current_professor);
void FinalTest(struct Account *Professors, int current_professor);
void AverageMark(struct Account *Professors, int current_professor);