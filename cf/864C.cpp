#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, f, k;
	cin >> a >> b >> f >> k;
	if (b < f) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0, v = b - f, w;
	for (int i = 1; i <= k - 1; ++i) {
		w = 2 * ((i&1) ? a - f : f);
		if (v < w) {
			if (b < w) {
				cout << -1 << endl;
				return 0;
			}
			v = b;
			++ans;
		}
		v -= w;
	}
	w = ((k&1) ? a - f : f);
	if (v < w) {
		if (b < w) {
			cout << -1 << endl;
			return 0;
		}
		++ans;
	}
	cout << ans << endl;
}
