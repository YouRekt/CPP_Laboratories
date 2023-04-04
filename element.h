#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

// 0-black, 15-white
// example colors: 8-gray,9-blue,10-green,12-red,14-yellow

class element	
{
		char sign;
		int color;
public:
		element(int color =0, char sign ='*'):sign(sign), color(color){}

		friend ostream& operator<<(ostream& out, const element& e)
		{	
			//prints a character in the given color
			 HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
			 SetConsoleTextAttribute(hconsole,e.color);

			 out<<e.sign;

			 SetConsoleTextAttribute(hconsole,15);	//white
			 return out;
		}
	};

