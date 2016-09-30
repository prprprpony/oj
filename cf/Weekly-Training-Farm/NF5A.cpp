#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[2][3];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];
		sort(a[i], a[i] + 3);
	}
	for (int i = 0; i < 3; ++i)
		if (a[0][i] > a[1][i]) {
			cout << "No\n";
			return 0;
		}
	cout << "Yes\n";
}
