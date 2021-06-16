#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graphic.h"
#include <string>
#include<cstdlib>
#include<ctime>
#include"Quiz.h"
using namespace std;

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}



void openingAnimation()
{


	resizeConsole(1000, 700);

	for (int i = 1; i < 54; i++)
	{
	
		srand(time(NULL));
		TextColor(rand() % 15 + 1);
		if (i < 31) {
			gotoXY(i + 1, 8);
			cout << "      ________     __      __    __    __________\n";
			gotoXY(i + 1, 9);
			cout << "     |  ____  |   |  |    |  |  |  |  |_______   |\n";
			gotoXY(i + 1, 10);
			cout << "    |  |    |  |  |  |    |  |  |  |      ____|__|\n";
			gotoXY(i + 1, 11);
			cout << "    |  | __ |  |  |  |    |  |  |  |   __|____|\n";
			gotoXY(i + 1, 12);
			cout << "    |  ||  ||  |  |  |____|  |  |  |  |  |_______\n";
			gotoXY(i + 1, 13);
			cout << "     |__|  |__|    |________|   |__|  |__________|\n";
			gotoXY(i + 1, 14);
			cout << "        |__|\n";
			gotoXY(63 - i, 15);
			cout << " __________    __________      ________    __________\n";
			gotoXY(63 - i, 16);
			cout << "|___    ___|  |   _______|   _| _______|  |___    ___|\n";
			gotoXY(63 - i, 17);
			cout << "    |  |      |  |____      |_ |_____         |  |\n";
			gotoXY(63 - i, 18);
			cout << "    |  |      |   ____|       |_____ |_       |  |\n";
			gotoXY(63 - i, 19);
			cout << "    |  |      |  |_______    _______| _|      |  |\n";
			gotoXY(63 - i, 20);
			cout << "    |__|      |__________|  |________|        |__|\n";
		}
		else {
			gotoXY(32, 8);
			cout << "      ________     __      __    __    __________\n";
			gotoXY(32, 9);
			cout << "     |  ____  |   |  |    |  |  |  |  |_______   |\n";
			gotoXY(32, 10);
			cout << "    |  |    |  |  |  |    |  |  |  |      ____|__|\n";
			gotoXY(32, 11);
			cout << "    |  | __ |  |  |  |    |  |  |  |   __|____|\n";
			gotoXY(32, 12);
			cout << "    |  ||  ||  |  |  |____|  |  |  |  |  |_______\n";
			gotoXY(32, 13);
			cout << "     |__|  |__|    |________|   |__|  |__________|\n";
			gotoXY(32, 14);
			cout << "        |__|\n";
			gotoXY(32, 15);
			cout << " __________    __________      ________    __________\n";
			gotoXY(32, 16);
			cout << "|___    ___|  |   _______|   _| _______|  |___    ___|\n";
			gotoXY(32, 17);
			cout << "    |  |      |  |____      |_ |_____         |  |\n";
			gotoXY(32, 18);
			cout << "    |  |      |   ____|       |_____ |_       |  |\n";
			gotoXY(32, 19);
			cout << "    |  |      |  |_______    _______| _|      |  |\n";
			gotoXY(32, 20);
			cout << "    |__|      |__________|  |________|        |__|\n";
		}
		Sleep(1);
		system("cls");
		if (i == 53)
		{
			

			for (int j = 1; j < 54; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					
					gotoXY(j + 31, 23);
					cout << "*";
				}
				Sleep(10);
			}
			gotoXY(15, 25);
			cout << "By nhom Cua Nguyen Khang Phu Loc Minh Hoang Cong Tan Duong Doan";
			gotoXY(15, 26);
			
			
		}
	}
	system("pause");
	gotoXY(45, 27);
	cout << "\n\n";
	TextColor(16);
}

void endingAnimation() {
	gotoXY(60, 28);
	cout << "*";
	for (int i = 1; i < 10; i++)
	{
		TextColor(rand() % 15 + 1);
		gotoXY(60, 28 - i);
		cout << "*";
		gotoXY(60 - i, 28);
		cout << "*";
		gotoXY(60, i + 28);
		cout << "*";
		gotoXY(60 + i, 28);
		cout << "*";
		if (i < 7) {
			gotoXY(60 - i, 28 - i);
			cout << "*";
			gotoXY(60 + i, 28 + i);
			cout << "*";
			gotoXY(60 + i, 28 - i);
			cout << "*";
			gotoXY(60 - i, 28 + i);
			cout << "*";
		}
		Sleep(100);
	}
	srand(time(NULL));
	TextColor(rand() % 15 + 1);
	gotoXY(56, 43);
	cout << "WELL DONE\n\n\n";
}
