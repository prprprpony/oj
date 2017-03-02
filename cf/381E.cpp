#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) for (int i = (a), __e = (b); i <= __e; ++i)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,s,e) for (int i = (s), __e = (e); i >= __e; --i)
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
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

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
const int N = 1.12e6;
char s[N];
struct node
{
	int s,x,y;
	node () : s(0), x(0), y(0) {} 
	node (int a,int b,int c) : s(a), x(b), y(c) {} 
} t[N<<2];
#define RT 0,0,n
#define AG int o, int l, int r
#define LC o+o+1,l,m
#define RC o+o+2,m,r
#define T t[o]
#define L t[o+o+1]
#define R t[o+o+2]
inline node meld(const node & a, const node & b)
{
	int v = min(a.x,b.y);
	return node(a.s + b.s + v, a.x + b.x - v,a.y + b.y - v);
}
void build(AG)
{
	if (r - l == 1) {
		if (s[l] == '(')
			++T.x;
		else
			++T.y;
		return;
	}
	int m = (l + r) / 2;
	build(LC);
	build(RC);
	T = meld(L,R);
}
node qry(AG,int i,int j)
{
	if (r <= i || l >= j)
		return node();
	if (i <= l && r <= j)
		return T;
	int m = (l + r) / 2;
	return meld(qry(LC,i,j),qry(RC,i,j));
}
int main()
{
	int m;
	RD(s,m);
	int n = strlen(s);
	build(RT);
	DO(m) {
		DRII(l,r);
		--l;
		PL(qry(RT,l,r).s<<1);
	}
}
