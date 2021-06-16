#pragma once
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Graphic.h"

using namespace std;

class Question;

class Choice {
private:
    string content;
    float score;
    int order;
public:

    Choice();
    Choice(string, float, int);
    string getContentC() const;
    float getScore() const;
    int getOrder() const;

    void setContentC(string);
    void setScore(float);
    void setOrder(int);

    friend istream& operator>>(istream& in, Question&);
};



