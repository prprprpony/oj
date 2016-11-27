#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,b) REP(i,0,b)
#define SZ(a) ((int)a.size())
#define CLR(a) a.clear()
#define EB emplace_back
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
typedef vector<int> vi;

const int maxn = 2025;
const int dr[] = {1, 0};
const int dc[] = {0, 1};
char g[maxn][maxn];
char ans[maxn * 2];
bool vis[maxn][maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	RP(i,n)
		cin >> g[i];
	ans[0] = g[0][0];
	vis[0][0] = true;
	vector<pii> v[2];
	v[1].EB(0,0);
	REP(i, 1, n + m - 1) {
		int now = i & 1;
		char mn = 'z';
		while (SZ(v[now])) {
			pii p = v[now].back();
			v[now].pop_back();
			RP(j,2) {
				int x = p.F + dr[j], y = p.S + dc[j];
				if (x >= n || y >= m || vis[x][y])
					continue;
				vis[x][y] = true;
				if (g[x][y] <= mn) {
					if (g[x][y] < mn) {
						mn = g[x][y];
						CLR(v[now^1]);
					}
					v[now^1].EB(x, y);
				}
			}
		}
		ans[i] = mn;
	}
	ans[n+m-1] = '\0';
	cout << ans << '\n'; 
}
