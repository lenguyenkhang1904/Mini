#include "Student.h"
Student::Student(string id, string name,  string birthday,string group, float score)
{
	this->name = name;
	this->id = id;
	this->birthday = birthday;
	this->score = score;
	this->group = group;
}

Student::Student(Student& st, float score)
{
	this->name = st.name;
	this->id = st.id;
	this->birthday = st.birthday;
	this->score = score;
	this->group = st.group;
}



string Student::getID()
{
	return this->id;
}

string Student::getName()
{
	return this->name;
}

string Student::getBirthday()
{
	return this->birthday;
}

float Student::getScore()
{
	return this->score;
}

string Student::getGroup()
{
	return this->group;
}
void Student::setAll(string name, string group, string birthday)
{
	this->group = group;
	this->birthday = birthday;
	this->name = name;
	
	
}

istream& operator>>(istream& is, Student& student)
{
	gotoXY(40, 4);
	cout << "Enter your id student: "; getline(is,student.id);
	gotoXY(40, 5);
	cout << "Enter your name: "; getline(is,student.name);
	gotoXY(40, 6);
	cout << "Enter your group: "; getline(is,student.group);
	gotoXY(40, 7);
	cout << "Enter your birtday: "; getline(is, student.birthday);
	gotoXY(40, 8);
	return is;
}

ostream& operator<<(ostream& os, Student& student)
{

	return os;
}

bool operator>(Student st1, Student st2)
{
	return st1.score>st2.score;
}

bool operator<(Student st1, Student st2)
{
	return st1.score<st2.score;
}

bool operator==(Student st1, Student st2)
{
	return st1.id==st2.id;
}
