#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
const int MAXR = 3.18e4, MAXC = 1.12e3;
int d[MAXC][MAXR];
int main()
{
	int R, C, K;
	scanf("%d%d%d", &R, &C, &K);
	REP(i,0,K) {
		int c, r, l, b;
		scanf("%d%d%d%d", &c, &r, &l, &b);
		REP(j,max(1, c - l),min(C, c + l) + 1) {
			int dx = abs(c - j);
			int dy = sqrt(l * l - dx * dx);
			d[j][max(1, r - dy)] += b;
			d[j][min(R, r + dy) + 1] -= b;
		}
	}
	int ans = 0, cnt = 0;
	REP(c,1,C+1)
		REP(r,1,R+1)
			if ((d[c][r] += d[c][r-1]) > ans) {
				ans = d[c][r];
				cnt = 1;
			} else if (d[c][r] == ans) {
				++cnt;
			}
	printf("%d\n%d\n", ans, cnt);
}
