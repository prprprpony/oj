#include <bits/stdc++.h>
using namespace std;
const int maxn = 106;
int cntr[maxn];
int cntc[maxn];
int pr[maxn];
int pc[maxn];
int sc[maxn];
int sr[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int r = 1; r <= n; ++r)
		for (int c = 1; c <= m; ++c) {
			int v;
			cin >> v;
			cntr[r] += v;
			cntc[c] += v;
		}
	for (int r = 1; r <= n; ++r)
		pr[r] = cntr[r] + pr[r - 1];
	for (int c = 1; c <= m; ++c)
		pc[c] = cntc[c] + pc[c - 1];
	for (int c = m - 1; c >= 1; --c)
		sc[1] += pc[m] - pc[c];
	for (int c = 2; c <= m; ++c)
		sc[c] = sc[c - 1] - pc[m] + 2 * pc[c - 1];
	for (int r = n - 1; r >= 1; --r)
		sr[1] += pr[n] - pr[r];
	for (int r = 2; r <= n; ++r)
		sr[r] = sr[r - 1] - pr[n] + 2 * pr[r - 1];
	int x = 1, y = 1;
	int mn = sr[1] + sc[1];
	for (int r = 1; r <= n; ++r)
		for (int c = 1; c <= m; ++c) {
			int v = sr[r] + sc[c];
			if (v < mn) {
				mn = v;
				x = r;
				y = c;
			}
		}
	cout << x << ' ' << y << '\n';
}
