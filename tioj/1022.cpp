#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int maxn = 106;
int h[maxn][maxn];
int d[maxn][maxn];
const int dr[] = {0, 1, -1, 0};
const int dc[] = {-1, 0, 0, 1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	while (k--) {
		int R, C;
		cin >> R >> C;
		for (int r = 1; r <= R; ++r)
			for (int c = 1; c <= C; ++c)
				cin >> h[r][c];
		fill_n(h[0], C + 2, maxn);
		fill_n(h[R + 1], C + 2, maxn);
		for (int r = 1; r <= R; ++r)
			h[r][0] = h[r][C+1] = maxn;
		for (int r = 1; r <= R; ++r)
			fill_n(d[r]+1, C, -1);
		queue<pii> q;
		d[1][1] = 0;
		q.push({1,1});
		while (d[R][C] == -1) {
			pii u = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				pii v(u.F + dr[i], u.S + dc[i]);
				if (abs(h[u.F][u.S] - h[v.F][v.S]) <= 5 && d[v.F][v.S] == -1) {
					d[v.F][v.S] = d[u.F][u.S] + 1;
					q.push(v);
				}
			}
		}
		cout << d[R][C] << '\n';
	}
}
