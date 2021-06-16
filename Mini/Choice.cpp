#include "Choice.h"

Choice::Choice(string content = "", float score = -1, int order = -1) {
    this->content = content;
    this->score = score;
    this->order = order;
}

Choice::Choice() {
    this->content = "";
    this->score = -1;
    this->order = -1;
}

string Choice::getContentC() const {
    return this->content;
}

float Choice::getScore() const {
    return this->score;
}

int Choice::getOrder() const {
    return this->order;
}

void Choice::setContentC(string content) {
    this->content = content;
}

void Choice::setScore(float score) {
    this->score = score;
}

void Choice::setOrder(int order) {
    this->order = order;
}


