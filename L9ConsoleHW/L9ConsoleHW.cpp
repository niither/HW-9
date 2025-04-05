#include <iostream>
#include <windows.h>
using namespace std;

enum Color : short {
	BLACK, DARKBLUE, DARKGREEN, TURQUOISE, DARKRED, PURPLE, DARKYELLOW, GREY,
	DARKGREY, BLUE, GREEN, CYAN, RED, PINK, YELLOW, WHITE
};

// Task 1
void line(short lenght, char symbol, short color, bool direction)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
	for (int i = 0; i < lenght; i++)
	{
		cout << symbol;
		if (!direction)
		{
			cout << "\n";
		}
	}
}

// Task 2
void rechtangle(short width, short height, char frameChar, char fillChar, Color frameColor, Color fillColor, short X, short Y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < height; y++)
	{
		COORD position = { X, Y + y };
		SetConsoleCursorPosition(h, position);
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
				SetConsoleTextAttribute(h, frameColor);
				cout << frameChar;
			}
			else
			{
				SetConsoleTextAttribute(h, fillColor);
				cout << fillChar;
			}
		}
		cout << "\n";
	}
}

// Task 3
double cube(int number)
{
	return pow(number, 3);
}

// Task 4
bool primeNum(int number)
{
	if (number <= 1)
	{
		return false;
	}
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	line(20, '@', 12, true);
	rechtangle(15, 10, '%', '#', RED, BLUE, 7, 6);
	cout << cube(2) << "\n";
	cout << boolalpha << primeNum(1);
}