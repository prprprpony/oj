#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1); i >= (b); --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) RP(__i,n)
template<class T>
void cmax(T & a, T b) {a = max(a, b);}
template<class T>
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
	template<class T, class ... TT>
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
bool RD() {return 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<class T, class ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DR(T,...) T __VA_ARGS__; RD(__VA_ARGS__)
#define RI(...) DR(int,__VA_ARGS__)

/* For it's time for you to fulfill your output. */
void PT(const char & a) {putchar(a);}
void PT(char const * const & a) {fputs(a, stdout);}
void PT(const double & a) {printf("%.16f", a);}
void PT(const int & a) {printf("%d", a);}
void PT(const ll & a) {printf("%lld", a);}

/* The line will last forever! */
template<char s = ' ', char e = '\n'>
void PL() {if (e) PT(e);}
	template<char s = ' ', char e = '\n', class T, class ... TT>
void PL(const T & a, const TT & ... b)
{PT(a); if (sizeof...(b) && s) PT(s); PL<s,e>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e5 + 87;
int n,a[N];
set<int> p[N];
struct node
{
	ll s;
	node * lc, * rc;
} * ver[N];
void upd(node *& t,int l,int r,int i,int x)
{
	if (!t)
		t = new node();
	t->s += x;
	if (r - l == 1) {
/*
		if (!t->s) {
			delete t;
			t = nullptr;
		}
*/
		return;
	}
	int m = l + (r - l) / 2;
	if (i < m)
		upd(t->lc, l, m, i, x);
	else
		upd(t->rc, m, r, i, x);
/*
	if (!t->s && !t->lc && !t->rc) {
		delete t;
		t = nullptr;
	}
*/
}
ll qry(node * t,int l, int r,int i,int j)
{
	if (!t || r <= i || j <= l)
		return 0;
	if (i <= l && r <= j)
		return t->s;
	int m = (l + r) / 2;
	return qry(t->lc, l, m, i, j) + qry(t->rc, m, r, i, j);
}
void upd(int i,int j,int x)
{
	if (!i || !j)
		return;
	for (;i<=n;i+=i&-i)
		upd(ver[i],1,n+1,j,x);
}
ll qry(int i,int l,int r)
{
	ll x = 0;
	for (;i;i^=i&-i)
		x += qry(ver[i], 1, n+1, l, r);
	return x;
}
ll qry(int i,int j)
{
	return qry(j,i,j+1);
}
void del(int i)
{
	int v = a[i];
	auto it = p[v].upper_bound(i);
	int l=0,r=0;
	if (it != p[v].end())
		r = *it;
	it = prev(it);
	if (it != p[v].begin())
		l = *prev(it);
	upd(r, l, r - l);
	upd(r, i, -(r - i));
	upd(i, l, -(i - l));
	p[v].erase(it);
}
void ins(int i,int v)
{
	auto it = p[v].upper_bound(i);
	int l=0,r=0;
	if (it != p[v].end())
		r = *it;
	if (it != p[v].begin())
		l = *prev(it);
	upd(r, l, -(r - l));
	upd(r, i, r - i);
	upd(i, l, i - l);
	p[v].insert(it, i);
	a[i] = v;
}
int main()
{
	int m;
	RD(n,m);
	RP1(i,n) {RI(x); ins(i, x);}
	DO(m) {
		RI(t,x,y);
		if (t == 1) {
			if (a[x] == y)
				continue;
			del(x);
			ins(x,y);
		} else {
			PL(qry(x,y));
		}
	}
}
