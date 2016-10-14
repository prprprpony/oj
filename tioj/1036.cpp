#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
bitset<maxn + 1> sev;
vector<int> p;
int main()
{
	sev[0] = sev[1] = 1;
	for (int i = 2; i <= maxn; ++i) {
		if (!sev[i])
			p.push_back(i);
		for (auto x : p) {
			if (i * x > maxn)
				break;
			sev[i * x] = 1;
			if (i % x == 0)
				break;
		}
	}


	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		cout << upper_bound(p.begin(), p.end(), n) - p.begin() << '\n';
	}
}
