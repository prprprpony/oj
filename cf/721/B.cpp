#include <bits/stdc++.h>
using namespace std;
int cnt[125];
int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		++cnt[s.size()];
	}
	string p;
	cin >> p;
	int a1 = 0;
	for (int i = 1; i < p.size(); ++i)
		a1 += cnt[i];
	int a2 = a1 + cnt[p.size()];
	++a1;
	a1 += ((a1 + k - 1) / k - 1) * 5;
	a2 += ((a2 + k - 1) / k - 1) * 5;
	cout << a1 << ' ' << a2 << '\n';
}
