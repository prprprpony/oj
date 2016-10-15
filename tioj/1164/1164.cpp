#include <bits/stdc++.h>
#include "lib1164.h"
#define eb emplace_back
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1.12e6;
vector<pii> g[maxn];
int N;
int mv;
int md;
void dfs(int dis, int p, int u)
{
	if (dis > md) {
		mv = u;
		md = dis;
	}
	for (auto x : g[u]) if (x.F != p)
		dfs(dis + x.S, u, x.F);
}
int calc(const MAP & p)
{
	N = p.m;
	for (int i = 0; i < N; ++i)
		g[i].clear();
	for (int i = 0; i < N - 1; ++i) {
		g[p.x[i]].eb(p.y[i], p.len[i]);
		g[p.y[i]].eb(p.x[i], p.len[i]);
	}
	md = 0;
	dfs(0, -1, 0);
	md = 0;
	dfs(0, -1, mv);
	return md;
}
int main()
{
	int n = init();
	int l, s;
	if (query(0, 1))
		l = 0, s = 1;
	else
		l = 1, s = 0;
	int i;
	for (i = 2; i + 1 < n; i += 2) {
		int a, b;
		if (query(i, i + 1))
			a = i, b = i + 1;
		else
			b = i, a = i + 1;
		if (query(a, l))
			l = a;
		if (query(s, b))
			s = b;
	}
	if (i < n) {
		if (query(i, l))
			l = i;
		else if (query(s, i))
			s = i;
	}
	answer(calc(getct(l)), calc(getct(s)));
}
