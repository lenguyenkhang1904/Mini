#pragma once
#include "Question.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#define Q_MAX 20
#include <direct.h>
#include<iostream>
#include"Student.h"
class Quiz : public Question
{
	string name;
	int duration;

public:
	Question question[Q_MAX];//danh sách câu hỏi
	Quiz();
	Quiz(string, int);

	string getName() const;
	int getDuration() const;

	void setName(string);
	void setDuration(int);

	//overriding
	void addQuestion(Question);
	void removeQuestion(int);
	void updateQuestion(int, Question);

	void operator+(Question);
	void operator-(int);

	char show();

	void exportToFile(string);
	void importFromFile(string);


	string Scanfile();



};


