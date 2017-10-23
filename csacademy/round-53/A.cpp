#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans = 0;
	for (int i = 0; i < 3; ++i) {
		int x = 1e9;
		for (int j = 0; j < 3; ++j) {
			int y;
			cin >> y;
			x = min(x, y);
		}
		ans += x;
	}
	cout << ans << '\n';
}
