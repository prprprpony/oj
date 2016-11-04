#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
const int LEN = 1.12e6;
int l[2];
int w[2][LEN];
int ct[LEN];
int main()
{
	int n, c, k = 0;
	scanf("%d%d", &n, &c);
	rep(i,0,n) {
		int now = i & 1;
		scanf("%d", l + now);
		rep(j,0,l[now]) scanf("%d",w[now] + j), --w[now][j];
		if (!i) continue;
		int flag = 0;
		rep(j,0,min(l[now^1], l[now]))
			if (w[now^1][j] != w[now][j]) {
				flag = 1;
				++k;
				int a = w[now^1][j], b = w[now][j];
				if (a < b) {
					// x not in [c - b, c - a - 1]
					++ct[0];
					--ct[c-b];
					++ct[c-a];
				} else {
					// x in [c - a, c - b - 1]
					++ct[c-a];
					--ct[c-b];
				}
				break;
			}
		if (!flag && l[now] < l[now^1]) {
			puts("-1");
			return 0;
		}
	}
	if (!k || ct[0] == k) {
		puts("0");
		return 0;
	}
	rep(i,1,c) 
		if ((ct[i] += ct[i-1]) == k) {
			printf("%d\n", i);
			return 0;
		}
	puts("-1");
}
