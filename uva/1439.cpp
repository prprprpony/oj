#include <bits/stdc++.h>
using namespace std;
const int N = 15;
const int MAXM = 112;
bool connected[1 << N];
int dp[1 << N];
int choice[1 << N];
char x[MAXM], y[MAXM];
int lvl[N];
int main()
{
	int M;
	while (scanf("%d", &M) == 1) {
		fill_n(connected, 1 << N, false);
		fill_n(dp, 1 << N, N + 426);
		for (int i = 0; i < M; ++i) {
			scanf(" %c %c", x + i, y + i);
			x[i] -= 'L';
			y[i] -= 'L';
			connected[(1 << x[i]) | (1 << y[i])] = true;
		}
		for (int S = 0; S < (1 << N); ++S) {
			int i = S;
			int j = i & -i;
			for (int k = j; k && !connected[S]; i ^= k, k = i & -i)
				connected[S] = connected[S ^ (j | k)] || connected[j | k];
		}
		dp[0] = 0;
		for (int S = 1; S < (1 << N); ++S)
			for (int SS = S; SS; SS = (SS - 1) & S)
				if (!connected[SS] && dp[S] > dp[S ^ SS] + 1) {
					dp[S] = dp[S ^ SS] + 1;
					choice[S] = SS;
				}
		for (int S = (1 << N) - 1; S; S ^= choice[S]) {
			for (int i = choice[S], j = 0; i; i ^= (1 << j)) {
				while (!(i & (1 << j)))
					++j;
				lvl[j] = dp[S];
			}
		}
		printf("%d\n", dp[(1 << N)-1] - 2);
		for (int i = 0; i < M; ++i) {
			if (lvl[x[i]] > lvl[y[i]])
				swap(x[i], y[i]);
			printf("%c %c\n", 'L' + x[i], 'L' + y[i]);
		}
	}
}
