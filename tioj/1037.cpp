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
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */

const int N = 106, K = 10006;
bool dp[2][N][N];
inline int add(int a, int b, int m) {return (a += b) >= m ? a - m : a;}
inline int sub(int a, int b, int m) {return (a -= b) < 0 ? a + m : a;}
int main()
{
	int n,m;
	RD(n,m);
	int x,y;
	RD(x,y);
	dp[1][x][y] = true;
	RD(x,y);
	int k;
	RD(k);
	RP(i,k) {
		int j = i & 1, d;
		RD(d);
		RP(a,n)
			RP(b,m) 
				dp[j][a][b] = dp[j^1][add(a,d%n,n)][b] 
							|| dp[j^1][sub(a,d%n,n)][b]
							|| dp[j^1][a][add(b,d%m,m)]
							|| dp[j^1][a][sub(b,d%m,m)];
	}
	puts(dp[k & 1 ^ 1][x][y] ? "YES" : "NO");
}
