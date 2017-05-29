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

const int maxn = 314;
int len[maxn];
int w[maxn][maxn];
int main()
{
	int n,m,r;
	RD(n,m,r);
	REP(i,1,n+1)
		REP(j,1,m+1) {
			RD(w[i][j]);
			w[i][j] += w[i][j-1];
		}
	RP(i,min(n-1,r)+1)
		len[i] = sqrt(r * r - i * i);
	int ans = 0;
	REP(i,1,n+1)
		REP(j,1,m+1) {
			int v = 0;
			RP(k,min(i-1,r)+1)
				v += w[i-k][min(j+len[k],m)] - w[i-k][max(j-len[k]-1,0)];
			REP(k,1,min(n-i,r)+1)
				v += w[i+k][min(j+len[k],m)] - w[i+k][max(j-len[k]-1,0)];
			ans ^= v;
		}
	printf("%d\n", ans);
}
