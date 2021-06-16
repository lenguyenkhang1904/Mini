#include "Quiz.h"
#include <ctime>
#include <windows.h> 
#include <sstream>
#include "dirent.h"
#include<cstdlib>
#include "Student.h"
#include <algorithm>
#include"Graphic.h"
using namespace std;
string checkInput(string s) {   //chuẩn hóa câu trả lời
	string temp1;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] < 65 || s[i] > 102) continue;//mã anscii mã in hoa A-Z
		else if (s[i] < 97 && s[i] > 70) continue;//mã thường a-z
		else {
			string temp2(1, s[i]); 
			if (s[i] < 69) {
				temp1.append(temp2);
			}
			switch (s[i]) {
			case 'a': {
				temp1.append("A");
				break;
			}
			case 'b': {
				temp1.append("B");
				break;
			}
			case 'c': {
				temp1.append("C");
				break;
			}
			case 'd': {
				temp1.append("D");
				break;
			}
			}
		}
	}
	return temp1;
}

string simplify(string s) { 
	s = checkInput(s);
	string temp1;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int count = 0;
		int m = temp1.length();
		for (int j = 0; j < m + 1; j++) {
			if (s[i] == temp1[j]) {
				count++;
			}
		}
		if (count == 0) {
			string temp2(1, s[i]);
			temp1.append(temp2);
		}
	}
	return temp1;
}

Quiz::Quiz(string name = "", int duration = 0) {
	Question temp(2, "");
	this->name = name;
	this->duration = duration;
	for (int i = 0; i < Q_MAX; i++) question[i] = temp;
}

Quiz::Quiz() {
	this->name = "";
	this->duration = 0;
}

string Quiz::getName() const {
	return this->name;
}

int Quiz::getDuration() const {
	return this->duration;
}

void Quiz::setName(string name) {
	this->name = name;
}

void Quiz::setDuration(int duration) {
	this->duration = duration;
}

void Quiz::addQuestion(Question c) {
	for (int i = 0; i < Q_MAX; i++) {
		if (question[i].getType() == 2) {      //getType 
			question[i] = c;
			break;
		}
	}
}

void Quiz::updateQuestion(int i, Question c) {
	question[i] = c;
}

void Quiz::removeQuestion(int i) {
	question[i].setType(2);
}

void Quiz::operator+(Question c) {
	for (int i = 0; i < Q_MAX; i++) {
		if (question[i].getType() == 2) {
			question[i] = c;
			break;
		}
	}
}

void Quiz::operator-(int i) {
	question[i].setType(2);
}



string Quiz::Scanfile() { //quét tất cả các file 
	system("cls");
	TextColor(4);
	Quiz quiz = *this;//tao ban sao
	DIR* d;//lis danh sach file
	char* p1, * p2;
	int result;
	int temp = 0;
	string ArFile[10];
	struct dirent* dir;
	d = opendir(".");
	int count = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			
			p1 = strtok(dir->d_name, ".");//tách chuỗi ra 
			p2 = strtok(NULL, ".");
			if (p2 != NULL)
			{
				result = strcmp(p2, "quiz");
				if (result == 0)
				{
					temp++;
					gotoXY(50, temp + 1);
					cout << temp << " - " << p1 << endl;
					ArFile[temp] = p1;
					count++;
				}
			}
		}
		closedir(d);
	}

	string num;
	do {
		gotoXY(40, temp + 4);//đi đến tọa độ trên cái console góc tọa độ bên phải góc cuối cùng phần dường
		cout << "Enter subject to select the test: ";
		getline(cin, num);
	} while (stoi(num, 0) < 1 || stoi(num, 0) > (char)count); //stoi là để ép kiểu từ chuỗi sáng  1 số nguyên
	int n = stoi(num, 0);
	string fileName = ArFile[n] + ".quiz";
	return fileName;
}

char Quiz::show() {
	vector<Student> studentList;
	char luachon;
	int a[Q_MAX];
	while (true)
	{
		system("cls");

		gotoXY(40, 3);
		cout << "*** Welcome to the TEST ***";
		TextColor(10);
		gotoXY(40, 4);
		cout << "a.Start to do Test";
		gotoXY(40, 5);
		cout << "b.ShowDashBoard";
		gotoXY(40, 6);
		cout << "c.Update Student'information";
		gotoXY(40, 7);
		cout << "d.Rank score of student";
		gotoXY(40, 8);
		cout << "e.Exit";
		gotoXY(40, 9);
		cout << "Please choice "; cin >> luachon;
		gotoXY(51, 10);
		switch (luachon)
		{
		case 'a':
		{
			cin.ignore();
			system("cls");
			int CountQuestion = 0;
			for (int i = 0; i < Q_MAX; i++) {
				if ((question[i].getType() == 1) || (question[i].getType() == 0)) {
					CountQuestion++;
				}
			}
			for (int i = 0; i < CountQuestion; i++) {
				a[i] = randomQ(i, CountQuestion);
			}
			string examinee;
			string answers;
			float score[Q_MAX];
			float sumScore = 0;
			int count = 0;
			int Answered = 0;
			gotoXY(40, 3);
			cout << "*** Welcome to the Quiz ***";
			TextColor(10);
			Student student;
			cin >> student;
			//gotoXY(40, );
			cout << "Name: " << getName();
			gotoXY(40, 9);
			cout << "Duration: " << getDuration() << " (Minutes)";
			gotoXY(40, 10);
			cout << "Examinee: ";
			getline(cin, examinee);
			gotoXY(51, 10);
			cout << "\n";
			time_t now = time(0);
			tm* getTime = localtime(&now);
			int hour = getTime->tm_hour;
			int min = getTime->tm_min;
			int sec = getTime->tm_sec;
			int year = 1900 + getTime->tm_year;
			int month = 1 + getTime->tm_mon;
			int day = getTime->tm_mday;
			tm* getTime1;
			int minCountDown = min + getDuration();
			ostringstream convert_hour;
			convert_hour << hour;
			string str_hour = convert_hour.str();
			ostringstream convert_min;
			convert_min << min;
			string str_min = convert_min.str();
			ostringstream convert_sec;
			convert_sec << sec;
			string str_sec = convert_sec.str();
			ostringstream convert_year;
			convert_year << year;
			string str_year = convert_year.str();
			ostringstream convert_month;
			convert_month << month;
			string str_month = convert_month.str();
			ostringstream convert_day;
			convert_day << day;
			string str_day = convert_day.str();
			char luaChon;
			for (int i = 0; i < CountQuestion; i++) {
				system("cls");
				score[i] = 0;
				count++;
				TextColor(14);
				cout << "Question " << count << ": ";
				TextColor(11);
				cout << question[a[i]];
				if (i == 0) {
					cout << "Answer/Skip: (A/S)?";
					cin >> luaChon;
				}
				else {
					cout << "Back/Answer/Skip: (B/A/S)?";
					cin >> luaChon;
				}
				if (luaChon == 'A' || luaChon == 'a') {
					TextColor(14);
					cout << "\nInput your answers: ";
					cin >> answers;
					cout << "\n";
					answers = simplify(answers);
					//cout << "Your answers: " << answers << "\n";
					cout << "Your answers: " << answers << "\n";

					time_t now1 = time(0);
					getTime1 = localtime(&now1);
					if (getTime1->tm_min >= minCountDown) {
						cout << "Time up!\n\n";
						break;
					}

					else {
						score[i] = question[a[i]].checkAnswers(answers);
						Answered++;
						cout << score[i];
						TextColor(12);
						cout << "Your remaining time: " << minCountDown - getTime1->tm_min - 1 << "(Minutes)\n\n";
					}
					system("pause");
				}
				else if (luaChon == 'B' || luaChon == 'b') {
					count -= 2;
					i -= 2;
					Answered--;

				}


			}
			for (int i = 0; i < count; i++) {
				sumScore += score[i];
			}
			char choice;
			system("cls");
			TextColor(11);
			TextColor(4);
			gotoXY(45, 3);
			cout << "*** Quiz result ***\n";
			TextColor(10);
			gotoXY(40, 4);
			cout << "Name: " << getName();
			gotoXY(40, 5);
			cout << "Duration: " << getDuration() << " (Minutes)\n";
			gotoXY(40, 6);
			cout << "Examinee: " << examinee << "\n";
			gotoXY(40, 7);
			cout << "            ---\n";
			TextColor(14);
			gotoXY(40, 8);
			cout << "Number of question: " << count << "\n";
			gotoXY(40, 9);
			cout << "Number of answered questions: " << Answered << "\n";
			TextColor(12);
			gotoXY(40, 10);
			cout << "Total score: " << sumScore << "\n";
			gotoXY(40, 11);
			TextColor(14);
			cout << "Begin at: " << hour << ":" << min << ":" << sec << "\n";
			gotoXY(40, 12);
			cout << "End at: " << getTime->tm_hour << ":" << getTime->tm_min << ":" << getTime->tm_sec << "\n";
			gotoXY(40, 13);
			if (getTime->tm_min > min && getTime->tm_sec < sec) cout << "Total time: " << getTime->tm_min - min << ":" << getTime->tm_sec + 60 - sec << "s (Minutes:Sec)\n\n";
			else cout << "Total time: " << getTime->tm_min - min << ":" << getTime->tm_sec - sec << "s (Minutes:Sec)\n\n";
			gotoXY(28, 18);
			TextColor(11);
			cout << "Press 'S' to save your result: \n"; cin >> choice;
			gotoXY(40, 19);
			//truyền tham số
			Student studentAfter(student, sumScore);//truyền tham số vào constructor
			system("cls");
			if (choice == 's' || choice == 'S') {
				string FileExportTime = studentAfter.getName() + "-" + studentAfter.getID() + ".txt";
				cout << FileExportTime << endl;
				ofstream FileSaveReSult(FileExportTime.c_str());
				FileSaveReSult << "*** Quiz result ***\n";
				FileSaveReSult << "\nName: " << getName();
				FileSaveReSult << "\nID-STudent: " << studentAfter.getID();
				FileSaveReSult << "\nFULL-Name: " << studentAfter.getName();
				FileSaveReSult << "\nGroup: " << studentAfter.getGroup();
				FileSaveReSult << "\nBirthDay: " << studentAfter.getBirthday();
				FileSaveReSult << "\nDuration: " << getDuration() << " (Minutes)\n";
				FileSaveReSult << "Examinee: " << examinee << "\n";
				FileSaveReSult << "---\n";
				FileSaveReSult << "Number of question: " << count << "\n";
				FileSaveReSult << "Number of answered questions: " << Answered << "\n";
				FileSaveReSult << "Total score: " << studentAfter.getScore() << "\n";
				FileSaveReSult << "Begin at: " << hour << ":" << min << ":" << sec << "\n";
				FileSaveReSult << "End at: " << getTime->tm_hour << ":" << getTime->tm_min << ":" << getTime->tm_sec << "\n";
				if (getTime->tm_min > min && getTime->tm_sec < sec)
                FileSaveReSult << "Total time: " << getTime->tm_min - min << ":" << getTime->tm_sec + 60 - sec << "s (Minutes:Sec)\n\n";
				else FileSaveReSult << "Total time: " << getTime->tm_min - min << ":" << getTime->tm_sec - sec << "s (Minutes:Sec)\n\n";
				FileSaveReSult.close();
			}
			studentList.push_back(studentAfter);
			break;
		}
		case 'b':
		{
			system("cls");
			if (!studentList.empty()) {
				for (auto kq : studentList) {
					cout << "ID: " << kq.getID() << endl;
					cout << "Name: " << kq.getName() << endl;
					cout << "Group: " << kq.getGroup() << endl;
					cout << "Birthday: " << kq.getBirthday() << endl;
					cout << "Score: " << kq.getScore() << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else {
				cout << "Nothing here!" << endl;
			}
			system("pause");
			break;
		}
		case 'c':
		{
			cin.ignore();
			system("cls");
			string id;
			string name;
			string group;
			string birthday;
			gotoXY(40, 8);
			cout << "------------------------------------" << endl;
			gotoXY(40, 9);
			cout << "Enter Your id need to update: ";
			gotoXY(40, 10);
			getline(cin, id);//nhập id
			gotoXY(40, 12);
			Student obj(id);
			vector<Student>::iterator it;
			it = find(studentList.begin(), studentList.end(), obj);
			if (it == studentList.end())
			{

				cout << "khong ton tai!!!!" << endl;
				system("pause");
				gotoXY(40, 12);
				break;//quay trở về menu
			}
			else
			{
				do
				{
					gotoXY(40, 13);
					cout << "Edit your name: ";
					getline(cin, name);
					gotoXY(40, 14);
					cout << "Edit your birthday ";
					getline(cin, birthday);
					gotoXY(40, 15);
					cout << "Edit your group: ";
					getline(cin, group);
					//truyền tham số vào phần tử vừa tìm
					it->setAll(name, group, birthday);
				} while (_strcmpi(group.c_str(), " ") == 0 || _strcmpi(birthday.c_str(), " ") == 0 || _strcmpi(name.c_str(), " ") == 0);
					//để không cho người dùng nhập chuỗi rỗng

			}

			gotoXY(41, 18);
			system("pause");
			break;
		}
		case 'd':
		{
			system("cls");
			sort(studentList.begin(), studentList.end(), greater<Student>());
			if (!studentList.empty()) {
				for (auto kq : studentList) {
					cout << "ID: " << kq.getID() << endl;
					cout << "Name: " << kq.getName() << endl;
					cout << "Group: " << kq.getGroup() << endl;
					cout << "Birthday: " << kq.getBirthday() << endl;
					cout << "Score: " << kq.getScore() << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else {
				cout << "Nothing here!" << endl;
			}

			system("pause");
		}
		case 'e':
		{

			endingAnimation();
			exit(0);
			break;
		}
		default:
			gotoXY(40, 13);
			cout << "invalid choice";
			break;
		}
	}


	return luachon;
}
void Quiz::exportToFile(string filename) {
	Quiz quiz = (*this);
	ofstream out;
	out.open(filename.c_str());
	out << quiz.getName() << endl;
	out << quiz.getDuration() << endl;
	for (int i = 0; i < Q_MAX; i++) {
		out << quiz.question[i].getType() << endl;
		out << quiz.question[i].getContent() << endl;
		for (int j = 0; j < C_MAX; j++) {
			out << quiz.question[i].choice[j].getContentC() << endl;
			out << quiz.question[i].choice[j].getScore() << endl;
			out << quiz.question[i].choice[j].getOrder() << endl;
		}
	}
	out.close();
}

void Quiz::importFromFile(string filename) {
	string data;
	fstream in;
	in.open(filename.c_str());
	getline(in, name);

	getline(in, data);
	this->duration = stoi(data.c_str());
	for (int i = 0; i < Q_MAX; i++) {
		getline(in, data);
		question[i].setType(stoi(data.c_str()));

		getline(in, data);
		question[i].setContent(data);
		for (int j = 0; j < C_MAX; j++) {
			getline(in, data);
			question[i].choice[j].setContentC(data);
			getline(in, data);
			question[i].choice[j].setScore(atof(data.c_str()));
			getline(in, data);
			question[i].choice[j].setOrder(atoi(data.c_str()));
		}
	}

	in.close();
}

