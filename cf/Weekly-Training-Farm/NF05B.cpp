#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	for (int x = -100; x <= 100; ++x)
		if (a * x * x + b * x + c == 0) {
			cout << x << '\n';
			return 0;
		}
	cout << "No solution\n";
}
