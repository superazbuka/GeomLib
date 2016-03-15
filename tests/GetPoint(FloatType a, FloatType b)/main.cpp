#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../../library.h"

using namespace std;

int main()
{
	FloatType a, b;
	cin >> a >> b;
	Point p = GetPoint(a, b);
	cout << p.x << " " << p.y << endl;
	return 0;
}


