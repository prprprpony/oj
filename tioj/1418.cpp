#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int R[21][21];
int d[1 << 21];
int T, N;
int dp(int S)
{
	if (d[S] != inf)
		return d[S];
	int i = S & -S;
	int ii = __lg(i);
	int SS = S ^ i;
	for (int j = SS & -SS; SS; SS ^= j, j = SS & -SS) {
		int jj = __lg(j);
		int SSS = SS ^ j;
		for (int k = SSS & -SSS; SSS; SSS ^= k, k = SSS & -SSS) {
			int kk = __lg(k);
			d[S] = min(d[S], dp(S ^ i ^ j ^ k) + R[ii][jj] + R[ii][kk] + R[jj][kk]);
		}
	}
	return d[S];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> R[i][j];
		fill_n(d, 1 << N, inf);
		d[0] = 0;
		cout << dp((1 << N) - 1) << '\n';
	}
}
