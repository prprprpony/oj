#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
/* */
const int N = 1027;
char g[N][N];
int n,sg[N][N],me[4];
bool ok(int x,int y)
{
	return 0 <= x && x < n && 0 <= y && y < n && g[x][y] != 'X';
}
void solve()
{
	cin >> n;
	vector<pii> vk;
	int sa = 0;
	RP(i,n) {
		cin >> g[i];
		RP(j,n) {
			int x, y;
			tie(x,y) = tie(i,j);
			if (g[i][j] != 'X') {
				fill_n(me,4,0);
				if (ok(x-1,y))
					++me[sg[x-1][y]];
				if (ok(x,y-1))
					++me[sg[x][y-1]];
				if (ok(x-1,y-1))
					++me[sg[x-1][y-1]];
				RP(k,4) if (!me[k]) {sg[i][j] = k; break;}
			}
			if (g[i][j] == 'K') {
				vk.PB({i,j});
				sa ^= sg[i][j];
			}
		}
	}
	int ans = 0;
	for (const pii & p : vk) {
		int x,y;
		tie(x,y) = p;
		if (ok(x-1,y) && (sa ^ sg[x][y] ^ sg[x-1][y]) == 0)
			++ans;
		if (ok(x,y-1) && (sa ^ sg[x][y] ^ sg[x][y-1]) == 0)
			++ans;
		if (ok(x-1,y-1) && (sa ^ sg[x][y] ^ sg[x-1][y-1]) == 0)
			++ans;
	}
	if (ans)
		cout << "WIN " << ans << '\n';
	else
		cout << "LOSE\n";
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int q;
	cin >> q;
	while(q--)
		solve();
}
