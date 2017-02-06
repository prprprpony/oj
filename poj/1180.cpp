#include <cstdio>
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

typedef long long ll;
// STL container
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

/* For it's time for you to fulfill your output */
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}

/* Good Luck && Have Fun ! */
const int N = 1e4 + 87;
int n,s;
ll a[N], b[N], dp[N];
struct line
{
	ll m, k;
	line() {}
	line(ll a, ll b) : m(a), k(b) {}
	ll operator () (ll x)
	{
		return m * x + k;
	}
} dk[N];
bool kill(const line & p, const line & q, const line & r)
{
	return (r.k - p.k) * (p.m - q.m) <= (q.k - p.k) * (p.m - r.m);
}
int main()
{
	RD(n), RD(s);
	REP(i,1,n+1) RD(a[i]), RD(b[i]);
	REP(i,1,n+1) a[i] += a[i-1];
	PER(i,n+1,1) b[i] += b[i+1];
	int l = 0, r = 0;
	dk[0] = line(b[1], s * b[1]);
	REP(i,1,n+1) {
		ll x = a[i];
		while (l < r && dk[l](x) >= dk[l+1](x))
			++l;
		dp[i] = dk[l](x);
		line now(b[i+1], (s - a[i]) * b[i+1] + dp[i]);
		while (l < r && kill(dk[r-1], dk[r], now))
			--r;
		dk[++r] = now;
	}
	PT(dp[n]), PT('\n');
}
