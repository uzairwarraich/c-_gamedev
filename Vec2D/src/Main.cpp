//============================================================================
// Name        : Vec2D.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Vec2d.h"
using namespace std;



int main() {

	/*
	Vec2d vec(3,7);

	Vec2d resultvec;

	resultvec = vec * 3 ;


	cout << vec;

	cout << -vec;
	cout << resultvec;

*/

	int a = 10;
	int &p = a;
	p=20;
	cout << &p << endl << &a << endl;
	cout << a;

	return 0;
}
