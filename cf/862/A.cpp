#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	int ans = x;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k < x)
			--ans;
		if (k == x)
			++ans;
	}
	cout << ans << '\n';
}
