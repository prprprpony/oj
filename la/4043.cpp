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
const int maxn = 106;
int n;
pii a[maxn], b[maxn];
const double eps = 1e-10, inf = 1e9;
double w[maxn][maxn];
double lx[maxn], ly[maxn], slack[maxn], sx[maxn];
int my[maxn];
bool vx[maxn], vy[maxn];
inline double dist(pii a, pii b) {return sqrt(pow(a.F - b.F, 2.0) + pow(a.S - b.S, 2.0));}
bool match(int i, bool aug = true)
{
	vx[i] = true;
	RP(j,n) {
		double d = lx[i] + ly[j] - w[i][j];
		if (!vy[j] && fabs(d) < eps) {
			vy[j] = true;
			if (my[j] == -1 || match(my[j])) {
				if (aug) my[j] = i;
				return true;
			}
		} else {
			cmin(slack[j], d);
		}
	}
	return false;
}
void KM()
{
	fill_n(ly,n,0.0);
	fill_n(lx,n,0.0);
	fill_n(my,n,-1);
	RP(i,n) {
		lx[i] = w[i][0];
		REP(j,1,n)
			cmax(lx[i], w[i][j]);
	}
	RP(j,n) {
		slack[j] = lx[0] + ly[j] - w[0][j];
		REP(i,1,n)
			cmin(slack[j], lx[i] + ly[j] - w[i][j]);
	}
	RP(i,n) {
		fill_n(vx, n, false);
		fill_n(vy, n, false);
		fill_n(slack, n, inf);
		if (match(i)) continue;
		for (;;) {
			double a = inf;
			RP(j,n) if (!vy[j]) cmin(a, slack[j]);
			RP(i,n) if (vx[i]) lx[i] -= a;
			RP(j,n) if (vy[j]) ly[j] += a;
					else slack[j] -= a;
			RP(j,n) if (!vy[j] && fabs(slack[j]) < eps) {
				vy[j] = true;
				if (my[j] == -1 || match(my[j], 0))
					goto aug;
			}
		}
		aug:
		fill_n(vx, n, false);
		fill_n(vy, n, false);
		match(i);
	}
}
int main()
{
	while (RD(n)) {
		RP(i,n) RD(b[i].F, b[i].S);
		RP(i,n) RD(a[i].F, a[i].S);
		RP(i,n)
			RP(j,n)
				w[i][j] = -dist(a[i], b[j]);
		KM();
		static bool first = true;
		if (first)
			first = false;
		else
			PL();
		RP(i,n) PL(my[i] + 1);
	}
}
