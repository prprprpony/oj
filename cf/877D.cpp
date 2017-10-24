#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
typedef pair<int,int> pii;
#define F first
#define S second
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}
/*>_<*/
const int N = 1087, inf = 0x3f3f3f3f;
char g[N][N];
int n,m,k,d[N][N], dir;
bool vis[N][N][4];
bool ok(int r,int c)
{
	bool ret = 0 <= r && r < n && 0 <= c && c < m && g[r][c] == '.' && !vis[r][c][dir];
	if (ret)
		vis[r][c][dir] = 1;
	return ret;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> g[i];
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	--x1, --y1, --x2, --y2;
	memset(d,0x3f,sizeof(d));
	d[x1][y1] = 0;
	queue<pii> q;
	q.push({x1,y1});
	while (SZ(q)) {
		int x, y;
		tie(x,y) = q.front();
		q.pop();
		dir = 0;
		for (int r = x + 1; r - x <= k && ok(r,y); ++r)
			if (cmin(d[r][y], d[x][y] +1))
				q.push({r,y});
		++dir;
		for (int r = x - 1; x - r <= k && ok(r,y); --r)
			if (cmin(d[r][y], d[x][y] +1))
				q.push({r,y});
		++dir;
		for (int c = y + 1; c - y <= k && ok(x,c); ++c)
			if (cmin(d[x][c], d[x][y] +1))
				q.push({x,c});
		++dir;
		for (int c = y - 1; y - c <= k && ok(x,c); --c)
			if (cmin(d[x][c], d[x][y] +1))
				q.push({x,c});
	}
	cout << (d[x2][y2] == inf ? -1 : d[x2][y2]) << '\n';
}
