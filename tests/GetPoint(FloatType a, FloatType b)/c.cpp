#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int a, b, pa, pb;
	cin >> a >> b;
	cin >> pa >> pb;
	if (abs(a - pa) < 1e-9 and abs(b - pb) < 1e-9)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}


