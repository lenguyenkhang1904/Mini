#pragma once
#include "Quiz.h"
#include <stdlib.h>
class Student{
private:
	string name;
	string id;
	string group;
	string birthday;
	float score;
public:
	Student(string id = "", string name = "",  string birthday = "", string group="", float score = -1);
	Student(Student& st, float score);
	string getID();
	string getName();
	string getBirthday();
	float getScore();
	string getGroup();
	void setAll(string name, string group, string birthday);

	friend istream& operator>>(istream& is, Student& student);
	friend ostream& operator<<(ostream& os, Student& student);
	friend bool operator>(Student st1, Student st2);
	friend bool operator<(Student st1, Student st2);
	friend bool operator==(Student st1, Student st2);


};
