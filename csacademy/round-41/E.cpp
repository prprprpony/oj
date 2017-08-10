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

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<typename T, typename ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		switch (*s) {
		case '(':
		case '[':
		case '{':
			++c;
			break;
		case ')':
		case ']':
		case '}':
			--c;
			break;
		}
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
#define RI(a) int a; RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

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
const int N = 1e5 + 87;
mt19937 ran(time(0));
struct node
{
	int v,t,s,p;
	node * lc, *rc;
	node() {}
	node(int k) : v(k), t(0), s(1), p(ran()), lc(nullptr), rc(nullptr) {}
} mem[N];
void add(node*t,int x)
{
	if (t) {
		t->v += x;
		t->t += x;
	}
}
void push(node*t)
{
	if (t->t) {
		add(t->lc,t->t);
		add(t->rc,t->t);
		t->t = 0;
	}
}
int sz(node * t) {return t ? t->s : 0;}
void pull(node*t)
{
	t->s = 1 + sz(t->lc) + sz(t->rc);
}
void split_v(node * t,node *& a, node *& b,int v)
{
	if (!t) {
		a = b = nullptr;
		return;
	}
	push(t);
	if (t->v < v) {
		a = t;
		split_v(t->rc,a->rc,b,v);
		pull(a);
	} else {
		b = t;
		split_v(t->lc,a,b->lc,v);
		pull(b);
	}
}
void split_k(node * t,node *& a, node *& b,int k)
{
	if (!t) {
		a = b = nullptr;
		return;
	}
	push(t);
	if (sz(t->lc) + 1 <= k) {
		a = t;
		split_k(t->rc,a->rc,b, k - (sz(t->lc) + 1));
		pull(a);
	} else {
		b = t;
		split_k(t->lc,a,b->lc,k);
		pull(b);
	}
}
node * meld(node * a,node * b)
{
	if (!a || !b) return a ? a : b;
	if (a->p > b->p) {
		push(a);
		a->rc = meld(a->rc,b);
		pull(a);
		return a;
	} else {
		push(b);
		b->lc = meld(a,b->lc);
		pull(b);
		return b;
	}
}
int mn(node * t)
{
	push(t);
	if (t->lc)
		return mn(t->lc);
	return t->v;
}
int main()
{
	RII(n,m);
	node * rt = nullptr;
	RP(i,n) {
		RI(h);
		node * x = new(mem+i) node(h), * l, * r;
		split_v(rt,l,r,h);
		rt = meld(meld(l,x),r);
	}
	RP(i,m) {
		RI(c);
		if (c > n) {
			PL(i);
			return 0;
		}
		node *l,*r,*x,*y,*z,*w;
		split_k(rt,l,r,n-c);
		int v = mn(r);
		if (v < 1) {
			PL(i);
			return 0;
		}
		add(r,-1);
		split_v(l,x,y,v);
		split_v(r,z,w,v);
		rt = meld(meld(x,z),meld(y,w));
	}
	PL(m);
}
