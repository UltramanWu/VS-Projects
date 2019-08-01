#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <windows.h>
using namespace std;

typedef void(*PFON)(int, int);

typedef void(*pFunx)(PFON);


void function_1(int, int){
	printf("%s\n", "function_1");
}



int main()
{
	//PFON a = function_1;
	//a(1, 2);
	//pFunx b[10];   /* 声明一个数组成员为函数指针的数组 */
	//int *p = new int[5];
	//assert(p != NULL);
	cout << "Hello World!" << endl;
	HANDLE hout;
	COORD coord;
	coord.X = 5;
	coord.Y = 1;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);

	cout << "Hello World!" << endl;
	system("pause");
	return 0;
}