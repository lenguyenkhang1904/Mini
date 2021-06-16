#pragma once
#include "Quiz.h"
#include "Graphic.h"
#include<string>
#include"Student.h"
void menu()
{	
	
	openingAnimation();
	Quiz Qz1;
	Qz1.importFromFile(Qz1.Scanfile());
	Qz1.show();
	
}
