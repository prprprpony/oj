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
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const double a) {printf("%.16f", a);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}

/* The line will last forever! */
template<char s = ' ', char e = '\n'>
void PL() {if (e) PT(e);}
template<char s = ' ', char e = '\n', class T, class ... TT>
void PL(const T&a,const TT&...b){PT(a);if(sizeof...(b)&&s)PT(s);PL<s,e>(b...);}

/* Good Luck && Have Fun ! */
const int N = 2e5 + 87, M = 1e9 + 9, P = 0xdefaced;
int add(int a,int b) {return (a += b) < M ? a : a - M;}
int mul(int a,int b) {return a * 1LL * b % M;}
int pw[N];
void pre()
{
	pw[0] = 1;
	REP(i,1,N) pw[i] = mul(pw[i-1], P);
}
struct hs
{
	int v,s;
	hs(int a = 0,int b = 0) : v(a), s(b) {}
	hs operator + (const hs & b) const
	{
		return hs(add(mul(v,pw[b.s]),b.v), s + b.s);
	}
	hs operator += (const hs & b)
	{
		return *this = *this + b;
	}
};
struct node
{
	int v,k;
	hs h;
	node * p, * c[2];
	node() {}
	node(int i,int x) : v(i), k(x), h(x,1), p(0), c{0,0} {}
	int d() {return p ? p->c[1] == this : -1;}
} mem[N];
hs th(node * t) {return t ? t->h : hs();}
void pull(node * t)
{
	t->h = th(t->c[0]) + hs(t->k,1) + th(t->c[1]);
}
void lc(node * x,int i,node * y)
{
	if (x)
		x->c[i] = y;
	if (y)
		y->p = x;
}
node * cc(node * t,int i)
{
	node * x = t->c[i];
	if (x) x->p = 0;
	t->c[i] = 0;
	pull(t);
	return x;
}
void rot(node * t)
{
	node * p = t->p;
	int i = t->d();
	lc(p->p,p->d(),t);
	lc(p,i,t->c[i^1]);
	pull(p);
	lc(t,i^1,p);
}
node * spl(node * t)
{
	for (;t->p;rot(t))
		if (t->p->p)
			rot(t->d() == t->p->d() ? t->p : t);
	pull(t);
	return t;
}
node * lb(node * t,int v)
{
	if (!t)
		return t;
	if (t->v < v && t->c[1])
		return lb(t->c[1],v);
	else if (t->v >= v && t->c[0])
		return lb(t->c[0], v);
	else
		return spl(t);
}
void split(node * t,node *& a,node *& b,int v)
{
	if (!t) {
		a = b = 0;
		return;
	}
	t = lb(t,v);
	if (t->v < v) {
		b = cc(t,1);
		a = t;
	} else {
		a = cc(t,0);
		b = t;
	}
}
void ins(node *& t, node * x)
{
	node * l, * r;
	split(t,l,r,x->v);
	lc(x,0,l);
	lc(x,1,r);
	pull(x);
	t = x;
}
node * meld(node * a,node * b)
{
	if (!a || !b) return a ? a : b;
	a = lb(a,1e9);
	lc(a,1,b);
	pull(a);
	return a;
}
int b[N];
int main()
{
	pre();
	RI(n,m);
	hs a,t;
	RP(i,n) {RI(x); a += hs(x,1); t += hs(pw[i],0);}
	RP(i,m) {RI(x); b[x] = i;}
	node * rt = 0;
	RP1(i,n-1) ins(rt, new(mem+i) node(b[i],i));
	int ans = 0;
	REP1(i,n,m) {
		ins(rt, new(mem+i) node(b[i],i));
		if (a.v == rt->h.v)
			++ans;
		a += t;
		spl(rt = mem+(i-n+1));
		node * x = cc(rt,0);
		node * y = cc(rt,1);
		rt = meld(x,y);
	}
	PL(ans);
}
