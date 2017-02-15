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
const int N = 106,inf=1e9;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
int g[N][N],d[N][N][3];
typedef pair<pii,int> pos;
typedef pair<int,pos> node;
int main()
{
#ifndef PP
	freopen("visitfj.in","r",stdin);
	freopen("visitfj.out","w",stdout);
#endif
	DRII(n,t);
	RP(i,n) RP(j,n) RD(g[i][j]);
	RP(i,n) RP(j,n) RP(k,3) d[i][j][k] = inf;
	d[0][0][0] = 0;
	priority_queue<node, vector<node>, greater<node> > pq;
	pq.push({0,{{0,0},0}});
	while (pq.size()) {
		auto u = pq.top();
		pq.pop();
		auto p = u.S.F;
		int m = u.S.S;
		if (u.F != d[p.F][p.S][m])
			continue;
		if (p == pii{n-1,n-1})
			break;
		RP(i,4) {
			int x = p.F + dx[i];
			int y = p.S + dy[i];
			int r = (m + 1) % 3;
			if (0 <= x && x < n && 0 <= y && y < n) {
				int v = u.F + t + (r ? 0 : g[x][y]);
				if (v < d[x][y][r]) {
					d[x][y][r] = v;
					pq.push({v,{{x,y},r}});
				}
			}
		}
	}
	int ans = inf;
	RP(k,3) cmin(ans, d[n-1][n-1][k]);
	PL(ans);
}
