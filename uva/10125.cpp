#include<bits/stdc++.h>
using namespace std;
const int N = 1087, inf = 536870912 + 87;
int a[N];
map<int,int> m;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	while ((cin >> n) && n) {
		int ans = inf;
		if (n < 4)
			goto opt;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a,a+n);
		m.clear();
		for (int j = n - 1; j > 0; --j)
			for (int i = j - 1; i >= 0; --i)
				m[a[i] + a[j]] = a[j];
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < n; ++j) if (i != j) {
				auto it = m.find(a[i] - a[j]);
				if (it != m.end() && it->second < a[j]) {
					ans = a[i];
					goto opt;
				}
			}
		}
opt:
		if (ans != inf)
			cout << ans << '\n';
		else
			cout << "no solution\n";
	}
}
