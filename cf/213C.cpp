#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
template<typename T>
void cmax(T & a, T b) {a = max(a, b);}

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<typename T, typename ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		for (char x : "([{") c += *s == x;
		for (char x : ")]}") c -= *s == x;
	}
	cerr<<" = "<<a;
	if (*s) {
		cerr<<", ";
		_BG(++s,b...);
	} else
		cerr<<endl;
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DR(T,...) T __VA_ARGS__; RD(__VA_ARGS__)
#define RI(...) DR(int,__VA_ARGS__)

/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const double a) {printf("%.16f", a);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
const int N = 305, inf = 1e9;
int n,a[N][N],dp[2][N][N];
pii fi[N*2];
pii operator + (const pii & x,const pii & y)
{
	return pii(x.F+y.F,x.S+y.S);
}
bool ok(pii x)
{
	return 0 <= x.F && x.F < n && 0 <= x.S && x.S < n;
}
int wd(int k)
{
	if (k > n)
		k = n - (k - n);
	return k;
}
int main()
{
	RD(n);
	RP(i,n)
		RP(j,n)
			RD(a[i][j]);
	RP(i,n) fi[i+1] = {i,0};
	REP(i,1,n) fi[i+n] = {n-1,i};
	dp[1][0][0] = a[0][0];
	REP(len,1,2*n-1) {
		int i = len & 1;
		int t = wd(len);
		int k = wd(len + 1);
		RP(x,k)
			fill(dp[i^1][x] + x,dp[i^1][x] + k,-inf);
		RP(x,t)
			REP(y,x,t) {
				RP(b,4) {
					pii p(fi[len] + pii(-x,x) + pii(b&1,b&1^1));
					pii q(fi[len] + pii(-y,y) + pii(b>>1,b>>1^1));
					if (ok(p) && ok(q)) {
						int l = p.S - fi[len+1].S;
						int r = q.S - fi[len+1].S;
						if (l > r)
							swap(l,r);
						cmax(dp[i^1][l][r], dp[i][x][y] + a[p.F][p.S] + (q==p?0:a[q.F][q.S]));
					}
				}
			}
	}
	PL(dp[1][0][0]);
}
