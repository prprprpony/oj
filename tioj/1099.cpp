#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int maxn = 3001 * 3;
int s[3], t[3];
bitset<maxn> vis[maxn];

template<typename T>
int RI(T & a)
{
	int c;
	while (!isdigit(c = getchar()));
	a = 0;
	do {
		a = 10 * a + (c - '0');
	} while (isdigit(c = getchar()));
	return 1;
}

int main()
{
	int n;
	while (RI(n) && n) {
		int sum = 0;
		for (int i = 0; i < 3; ++i) {
			RI(s[i]);
			sum += s[i];
		}
		int ts = 0;
		for (int i = 0; i < 3; ++i) {
			RI(t[i]);
			ts += t[i];
		}
		if (sum != ts) {
			puts("No");
			continue;
		}
		sort(s, s + 3);
		sort(t, t + 3);
		for (int i = 0; i * 3 <= sum; ++i)
			vis[i].reset();
		queue<pii> q;
		vis[s[0]][s[1]] = 1;
		q.push({s[0], s[1]});
		while (q.size() && !vis[t[0]][t[1]]) {
			pii v = q.front();
			q.pop();
			int p[3] = {v.F, v.S, sum - v.F - v.S};
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) if (i != j) {
					int nxt[3] = {2 * p[i] - p[j] + 1, 2 * p[j] - p[i] - 1, p[3 - i - j]};
					sort(nxt, nxt + 3);
					if (nxt[0] >= 0 && nxt[2] <= n && !vis[nxt[0]][nxt[1]]) {
						vis[nxt[0]][nxt[1]] = 1;
						q.push({nxt[0], nxt[1]});
					}
				}
		}
		puts(vis[t[0]][t[1]] ? "Yes" : "No");
	}
}
