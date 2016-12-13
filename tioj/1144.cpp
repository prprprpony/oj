#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,s,e) for (int i = (s), __e = (e); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
#define DO(n) REP(__i,0,n)
template<typename T>
void cmax(T & a, T b) {a = max(a, b);}
template<typename T>
void cmin(T & a, T b) {a = min(a, b);}

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define CLR(a) a.clear()
#define BK(a) (a.back())
#define FT(a) (a.front())
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

/* reading input is now 20% cooler */
bool RD(void) {return true;}
bool RD(int & a)
{
	int c;
	while (!isdigit(c = getchar()) && c != EOF);
	if (c == EOF) return false;
	for (a = 0; isdigit(c); a = 10 * a + c - '0', c = getchar());
	return true;
}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */

const int M = 201, inf = 1e9;
int g[M][M];
int dp[2][M][M];
int main()
{
	int m;
	RD(m);
	RP(i,m)
		RP(j,m)
			RD(g[i][j]);
	RP(i,m)
		fill_n(dp[0][i], i+1, inf);
	dp[0][1][0] = 0;
	int a[2] = {2,87}, i;
	for (i = 1; RD(a[i]); i ^= 1) {
		if (--a[i] == a[i^1]) {
			i ^= 1;
			continue;
		}
		RP(j,m)
			fill_n(dp[i][j], j+1, inf);
		RP(j,m)
			RP(k,j+1) {
				int x = j, y = k;
				cmin(dp[i][x][y], dp[i^1][j][k] + g[a[i^1]][a[i]]);
				x = a[i^1];
				if (x < y)
					swap(x, y);
				cmin(dp[i][x][y], dp[i^1][j][k] + g[j][a[i]]);
				x = a[i^1], y = j;
				if (x < y)
					swap(x, y);
				cmin(dp[i][x][y], dp[i^1][j][k] + g[k][a[i]]);
			}
	}
	i ^= 1;
	int ans = inf;
	RP(j,m)
		RP(k,j+1)
			cmin(ans, dp[i][j][k]);
	printf("%d\n", ans);
}
