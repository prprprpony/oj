#include<bits/stdc++.h>
using namespace std;
const int N = 87, inf = 1e9;
int a[N][N];
void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			a[i][j] += a[i-1][j];
		}
	int ans = -inf;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) {
			{
				int s = 0, u = 0, v = 0, mv = 0;
				for (int k = 1; k <= n; ++k) {
					int b = a[j][k] - a[i-1][k];
					u += b;
					if (s < 0)
						s = 0;
					s += b;
					ans = max(ans, s);
					if (v < 0)
						v = 0;
					v += -b;
					if (k != n)
						mv = max(mv, v);
				}
				ans = max(ans, u + mv);
			}
			if (j != n) {
				int s = 0, u = 0, v = 0, mv = 0;
				for (int k = 1; k <= n; ++k) {
					int b = a[n][k] - (a[j][k] - a[i-1][k]);
					u += b;
					if (s < 0)
						s = 0;
					s += b;
					ans = max(ans, s);
					if (v < 0)
						v = 0;
					v += -b;
					if (k != n)
						mv = max(mv, v);
				}
				ans = max(ans, u + mv);
			}
		}
	cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin >> T;
	while(T--)solve();
}
