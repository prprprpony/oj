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

/* For it's time for you to fulfill your output */
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */

const int N = 1e5 + 42, M = 1e9 + 7;
char s[N];
int p25[N], f[N], inv[N], fi[N];
vi ans[N];
inline int add(int a, int b) {return (a+=b) >= M ? a - M : a;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
void precalc()
{
	p25[0] = f[0] = inv[0] = inv[1] = fi[0] = 1;
	REP(i,1,N) p25[i] = mul(p25[i-1], 25);
	REP(i,1,N) f[i] = mul(f[i-1], i);
	REP(i,2,N) inv[i] = mul(M - M/i, inv[M%i]);
	REP(i,1,N) fi[i] = mul(inv[i], fi[i-1]);
}
int main()
{
	precalc();
	int m;
	RD(m);
	RD(s);
	int l = strlen(s), n;
	while (m--) {
		int t;
		RD(t);
		switch (t) {
		case 1:
			RD(s);
			l = strlen(s);
			break;
		case 2:
			RD(n);
			if (!SZ(ans[l])) {
				ans[l].resize(N);
				ans[l][l] = 1;
				REP(k,l+1,N)
					ans[l][k] = add(mul(ans[l][k-1],26),mul(p25[k-l], mul(f[k-1], mul(fi[l-1], fi[k-l]))));
			}
			PL(ans[l][n]);
			break;
		}
	}
}
