#include <bits/stdc++.h>
using namespace std;
const int maxn = 3233;
bool tl[maxn];
int p[maxn], st[maxn];
vector<int> c[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	cin >> m;
	copy(p + 1, p + n + 1, st + 1);
	int k = 0;
	for (int i = 1; i <= n; ++i)
		while (st[i] != i) {
			tl[st[i]] = true;
			swap(st[i], st[st[i]]);
			++k;
		}
	k -= m;
	cout << abs(k) << '\n';
	if (k > 0) {
		for (int i = 1; i <= n && k; ++i) {
			if (!c[i].size()) {
				for (int v = p[i]; v != i; v = p[v]) {
					int tp = c[i].size();
					while (tp && c[i][tp-1] > v)
						--tp;
					copy(c[i].begin() + tp, c[i].end(), back_inserter(c[v]));
					c[i].resize(tp);
					c[i].push_back(v);
				}
			}
			for (auto j : c[i]) {
				cout << i << ' ' << j <<  " \n"[--k == 0];
				swap(p[i], p[j]);
				if (!k)
					break;
			}
		}
	} else if (k < 0) {
		for (int i = 2; i <= n && k; ++i)
			if (!tl[i])
				cout << "1 " << i << " \n"[++k == 0];
	}
}
