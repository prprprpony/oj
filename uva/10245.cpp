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
void PT(const double a) {printf("%.4f", a);}
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */
const int maxn = 1.12e4;
const double eps = 1e-6, inf = 1e9;
typedef pair<double,double> pff;
pff p[maxn], tmp[maxn];
inline bool ls(double a, double b) {return b - a > eps;}
bool cmp(const pff & a, const pff & b) {return a.S < b.S;}
inline double dist(pff a, pff b) {return sqrt(pow(a.F-b.F,2.0)+pow(a.S-b.S,2.0));}
double DC(int l, int r)
{
	double ans = inf;
	if (r - l <= 3) {
		REP(i,l,r-1)
			REP(j,i+1,r)
				cmin(ans, dist(p[i], p[j]));
		sort(p+l,p+r,cmp);
		return ans;
	}
	int m = (l + r) / 2;
	int mx = p[m].F;
	cmin(ans, min(DC(l,m), DC(m,r)));
	copy(p + l, p + r, tmp);
	merge(tmp, tmp + m - l, tmp + m - l, tmp + r - l, p + l, cmp);
	int tp = 0;
	REP(i,l,r)
		if (ls(fabs(mx - p[i].F), ans))
			tmp[tp++] = p[i];
	RP(i,tp-1)
		for (int j = i + 1; j < tp && tmp[j].S - tmp[i].S < ans; ++j)
			cmin(ans, dist(tmp[i], tmp[j]));
	return ans;
}
int main()
{
	int n;
	while (RD(n) && n) {
		RP(i,n)
			RD(p[i].F, p[i].S);
		sort(p, p + n);
		double ans = DC(0,n);
		if (!ls(ans,1e4))
			PL("INFINITY");
		else
			PL(ans);
	}
}
