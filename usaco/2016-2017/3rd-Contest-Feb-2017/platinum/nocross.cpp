#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define REP1(i,a,b) for (int i = (a), __e = (b); i <= __e; ++i)
#define RP1(i,n) REP1(i,1,n)
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

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)

/* For it's time for you to fulfill your output. */
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
const int N = 1.12e5;
int a[N],idx[N],c[9];
pii t[N<<2];
#define RT 0,0,n+1
#define TARG int o,int l,int r
#define RARG int i,int j
#define T t[o]
#define L t[o+o+1]
#define R t[o+o+2]
#define LC o+o+1,l,m
#define RC o+o+2,m,r
void ckm(int o,int v)
{
	cmax(T.F,v);
	cmax(T.S,v);
}
void push(int o)
{
	ckm(o+o+1,T.S);
	ckm(o+o+2,T.S);
}
void pull(int o)
{
	cmax(T.F,max(L.F,R.F));
}
void upd(TARG,RARG,int v)
{
	if (r <= i || j <= l)
		return ;
	if (i <= l && r <= j) {
		ckm(o,v);
		return;
	}
	int m = (l+r)/2;
	push(o);
	upd(LC,i,j,v);
	upd(RC,i,j,v);
	pull(o);
}
int qry(TARG,RARG)
{
	if (r <= i || j <= l)
		return 0;
	if (i <= l && r <= j)
		return T.F;
	int m = (l+r)/2;
	push(o);
	return max(qry(LC,i,j),qry(RC,i,j));
}
int main()
{
	freopen("nocross.in","r",stdin);
	freopen("nocross.out","w",stdout);
	DRI(n);
	RP1(i,n) {
		RD(a[i]);
		idx[a[i]] = i;
	}
	DO(n) {
		DRI(x);
		int tp = 0;
		REP1(i,max(1,x-4),min(n,x+4))
			c[tp++] = idx[i];
		sort(c,c+tp);
		PR(i,tp) 
			upd(RT,c[i],n+1,qry(RT,0,c[i])+1);
	}
	PL(qry(RT,0,n+1));
}
