#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x = 0, y = 0;
	char c;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> c) {
		c == 'N' ? ++y :
		c == 'E' ? ++x :
		c == 'S' ? --y :
		c == 'W' ? --x :
		87;
	}
	cout << abs(x) + abs(y) << '\n';
}
