#include "Question.h"
#include<string>
#include <ctime>
#include <windows.h> 

Question::Question(int type = 0, string content = "") {
	Choice temp;
	this->type = type;
	this->content = content;
	for (int i = 0; i < C_MAX; i++) choice[i] = temp;
}
Question::Question() {
	this->type = 0;
	this->content = "";
}

int Question::getType() const {
	return this->type;
}

string Question::getContent() const {
	return this->content;
}

void Question::setType(int type) {
	this->type = type;
}

void Question::setContent(string content) {
	this->content = content;
}

void Question::addChoice(Choice c) {
	if (choice[c.getOrder()].getOrder() == -1)
		choice[c.getOrder()] = c;
	else cout << "Vi tri nay da co cau tra loi.\n";
}

void Question::removeChoice(int i) {
	choice[i].setOrder(-1);
}

void Question::updateChoice(int i, Choice c) {
	choice[i] = c;
	choice[i].setOrder(i);
}

void Question::operator+(Choice c) {
	if (choice[c.getOrder()].getOrder() == -1)
		choice[c.getOrder()] = c;
	else cout << "Vi tri nay da co cau tra loi.\n";
}

void Question::operator-(int i) {
	choice[i].setOrder(-1);
}
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}
int Question::randomQ(int pos, int n) {
	srand(time(NULL));//cstdlib ctime
	int  a[100];
	for (int i = 0; i < n; i++)
	{
		a[i] =random(0,n-1);
		for (int j = i - 1; j >= 0; j--) //kiem tra xem a[i] = a[i + 1] hay ko
		{
			if (a[i] != a[j])
				continue;
			else //nêu trung thi gan lai a[i]
			{
				a[i] = random(0, n - 1);
				j = i;
			}
		}
	}
	return a[pos];
}


int Question::ArrayRandomChoice(int i) {
	Question q = *this;
	int ArrayRandom[6];
	int CountChoice = 0;
	for (int z = 0; z < C_MAX; z++) {
		ArrayRandom[z] = q.randomQ(z, C_MAX);
	}
	return ArrayRandom[i];
}

ostream& operator<<(ostream& cout, Question& q) {
	int temp = 0;
	cout << q.getContent();
	for (int i = 0; i < C_MAX; i++) {
		q.RandomC[i] = q.ArrayRandomChoice(i);
		if (q.choice[q.RandomC[i]].getOrder() == -1) continue;
		q.choice[q.RandomC[i]].setOrder(i);
	}
	if (q.getType() == 0) cout << " [Choose an answer]\n";
	else cout << " [Choose multiple answer]\n";
	for (int i = 0; i < C_MAX; i++) {
		if (q.choice[q.RandomC[i]].getOrder() == -1) continue;
		cout << static_cast<char>(65 + temp) << ". " << q.choice[q.RandomC[i]].getContentC() << endl;
		temp++;
	}
	return cout;
}

float Question::checkAnswers(string answers) {
	Question q = *this;
	int score = 0;
	if (q.getType() == 0)
		
	for (int i = 0; i < answers.length(); i++) {
		int temp = 0;
		for (int j = 0; j < C_MAX; j++) {
			if (q.choice[RandomC[j]].getOrder() == -1) continue;
			else {
				if (static_cast<int16_t>(answers[i]) == (65 + temp) && q.choice[RandomC[j]].getScore() == 0) {
					return 0;
				}
				else if (static_cast<int16_t>(answers[i]) == (65 + temp) && q.choice[RandomC[j]].getScore() != 0) {
					score += q.choice[RandomC[j]].getScore();
					temp++;
					continue;
				}
				else {
					temp++;
					continue;
				}
				return 0;
			}

		}
	}
	return score;
}

istream& operator>>(istream& cin, Question& q) {
	int temp;
	cout << "\nEnter question content: "; getline(cin, q.content);

	cout << "Enter question type (0/1) [One answer/Multiple answer]: "; cin >> q.type;

	cout << "Number of answer choices (1..6): "; cin >> temp;


	for (int i = 0; i < temp; i++) {
		fflush(stdin);
		cout << "\n - Answer content: "; getline(cin, q.choice[i].content);
		cout << " - Score (float): "; cin >> q.choice[i].score;
		cout << " - Display order (0..5): "; cin >> q.choice[i].order;
		cout << endl;
	}
	return cin;
}





