#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a), _B(b); i < _B; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1), _B(b); i >= _B; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
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
#define RI(a) int a; RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {ll x=a*100+0.5; PT(x/100), PT('.'), printf("%02lld",x%100);}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
typedef double db;
#define MT make_tuple 
const int N = 1008.7;
tuple<db,int,db,db> x[N * 2];
db y[N * 2];
tuple<int,db,db> t[N * 2 * 4];
int n;
int gy(db v)
{
	return lower_bound(y,y+n,v) - y;
}
db qry1(int o,int l,int r)
{
	return get<0>(t[o]) ? y[r] - y[l] : get<1>(t[o]);
}
db qry2(int o,int l,int r)
{
	return get<0>(t[o]) >= 2 ? y[r] - y[l] : get<0>(t[o]) ? get<1>(t[o]) : get<2>(t[o]);
}
#define LC o+o+1,l,m
#define RC o+o+2,m,r
void pull(int o,int l,int m,int r)
{
	get<1>(t[o]) = qry1(LC) + qry1(RC);
	get<2>(t[o]) = qry2(LC) + qry2(RC);
}
void upd(int o,int l,int r,int i,int j,int v)
{
	if (i <= l && r <= j) {
		get<0>(t[o]) += v;
		return;
	}
	int m = (l + r) / 2;
	if (i < m)
		upd(LC,i,j,v);
	if (m < j)
		upd(RC,i,j,v);
	pull(o,l,m,r);
}
int main()
{
	RI(T);
	while (T-- && RD(n)) {
		RP(i,n) {
			db x1,y1,x2,y2;
			RD(x1,y1,x2,y2);
			y[i<<1]=y1;
			y[i<<1|1]=y2;
			x[i<<1]=MT(x1,1,y1,y2);
			x[i<<1|1]=MT(x2,-1,y1,y2);
		}
		n*=2;
		sort(y,y+n);
		sort(x,x+n);
		db la = -87, ans = 0;
		RP(i,n) {
			ans += qry2(0,0,n-1) * (get<0>(x[i]) - la);
			la = get<0>(x[i]);
			upd(0,0,n-1,gy(get<2>(x[i])),gy(get<3>(x[i])),get<1>(x[i]));
		}
		PL(ans);
	}
}
