#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;
/*
	a + b = x
	2a + 4b = y
	4a+4b=4x
	(4x-y)/2=a
*/
	cout << (4*x-y)/2 << '\n';
}
