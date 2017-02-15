#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)(a.size()))

template <typename T>
T cmin(T & a, T b) {return a = min(a,b);}
template <typename T>
T cmax(T & a, T b) {return a = max(a,b);}

#define REP(i,a,b) for (int i(a),__e(b);i<__e;++i)
#define RP(i,n) REP(i,0,n)
#define DO(n) RP(__i,n)

bool RD(void) {return 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a,stdout);}
void PT(const int a) {printf("%d",a);}

void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ... b) {PT(a);if (sizeof...(b)) PT(' '); PL(b...);}
/**************************/
const int N = 106;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
inline int dir(int x1,int y1,int x2,int y2)
{
	RP(i,4) if (x2-x1 == dx[i] && y2 - y1 == dy[i]) return i;
	assert(2+2==5);
}
bool b[N][N][4];
bool vis[N][N], g[N][N];
int bfs(int n,int i,int j)
{
	int cnt = 0;
	queue<pii> q;
	vis[i][j] = true;
	q.push({i,j});
	while (SZ(q)) {
		pii u = q.front();
		q.pop();
		if (g[u.F][u.S])
			++cnt;
		RP(i,4) {
			int x = u.F + dx[i];
			int y = u.S + dy[i];
			if (!b[u.F][u.S][i] && 1 <= x && x <= n && 1 <= y && y <= n && !vis[x][y]) {
				vis[x][y] = true;
				q.push({x,y});
			}
		}
	}
	return cnt;
}
int main()
{
#ifndef PP
	freopen("countcross.in","r",stdin);
	freopen("countcross.out","w",stdout);
#endif
	DRIII(n,k,r);
	DO(r) {
		DRIIII(x1,y1,x2,y2);
		int d = dir(x1,y1,x2,y2);
		b[x1][y1][d] = true;
		b[x2][y2][3-d] = true;
	}
	DO(k) {
		DRII(x,y);
		g[x][y] = true;
	}
	int ans = 0, cnt = 0;
	REP(i,1,n+1)
		REP(j,1,n+1) 
		if (!vis[i][j]) {
			int v = bfs(n,i,j);
			ans += v * cnt;
			cnt += v;
		}
	PL(ans);
}
