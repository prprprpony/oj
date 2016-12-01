#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 2;
int pri[maxn], st[maxn], pa[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pri[x] = i;
	}
	int tp = 0, la;
	for (int i = 1; i <= n; ++i) {
		la = 0;
		while (tp && pri[st[tp-1]] > pri[i]) {
			pa[la] = st[tp - 1];
			la = st[--tp];
		}
		pa[la] = i;
		st[tp++] = i;
	}
	la = 0;
	while (tp) {
		pa[la] = st[tp-1];
		la = st[--tp];
	}
	for (int i = 1; i <= n; ++i)
		cout << pa[i] << '\n';
}
