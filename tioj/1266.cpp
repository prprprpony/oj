#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int maxn = 1.12e3;
int N;
int FT[maxn][maxn];
pii p[maxn * maxn];
void add(int r, int c, int v)
{
	for (int i = r; i <= N; i += i & -i)
		for (int j = c; j <= N; j += j & -j)
			FT[i][j] = max(FT[i][j], v);
}
int qry(int r, int c)
{
	int ret = 0;
	for (int i = r; i; i ^= i & -i)
		for (int j = c; j; j ^= j & -j)
			ret = max(ret, FT[i][j]);
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int r = 1; r <= N; ++r)
		for (int c = 1; c <= N; ++c) {
			int v;
			cin >> v;
			p[v].F = r;
			p[v].S = c;
		}
	int ans = 0;
	for (int i = 1; i <= N * N; ++i) {
		int a = qry(p[i].F, p[i].S) + 1;
		ans = max(ans, a);
		add(p[i].F, p[i].S, a);
	}
	cout << ans << '\n';
}
