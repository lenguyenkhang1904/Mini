#pragma once
#include "Choice.h"
#define C_MAX 6
#include <stdint.h>
#include<vector>
class Question
{
private:
    int type;
    string content;
   int RandomC[6];
public:
   Choice choice[100];
    Question();
    Question(int, string);

    int getType() const;
    string getContent() const;

    void setType(int);
    void setContent(string);

    void addChoice(Choice);
    void removeChoice(int);
    void updateChoice(int, Choice);
    float checkAnswers(string);

  
    int randomQ(int, int);
   int ArrayRandomChoice(int);

    void operator+(Choice);
    void operator-(int);

    friend ostream& operator<<(ostream&, Question&);
    friend istream& operator>>(istream&, Question&);
};

