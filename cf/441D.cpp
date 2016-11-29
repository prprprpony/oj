#include <bits/stdc++.h>
using namespace std;
const int maxn = 3233;
bool tl[maxn];
int p[maxn], st[maxn];
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
			int tp = 0;
			for (int v = p[i]; v != i; v = p[v]) {
				while (tp && st[tp-1] > v)
					--tp;
				st[tp++] = v;
			}
			for (int j = 0; j < tp && k; ++j) {
				cout << i << ' ' << st[j] <<  " \n"[--k == 0];
				swap(p[i], p[st[j]]);
			}
		}
	} else if (k < 0) {
		for (int i = 2; i <= n && k; ++i)
			if (!tl[i])
				cout << "1 " << i << " \n"[++k == 0];
	}
}
