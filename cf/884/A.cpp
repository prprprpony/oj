#include <bits/stdc++.h>
using namespace std;
const int S = 86400;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,t;
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		t -= (S - a);
		if (t <= 0) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
}
