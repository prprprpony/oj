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
const int N = 1e5 + 8;
mt19937 ran(1925);
int n,k;
int a[N],ia[N];
struct node
{
	int s,p,v;
	node * lc, * rc;
	node () {}
	node (int x) : s(1), p(ran()), v(x), lc(NULL), rc(NULL) {}
} mem[N * (__lg(N)+2)];
node * ptr;
node * tr[N];
inline void init()
{
	ptr = mem;
}
inline node * newnode(int v) {return new (ptr++) node(v);}
inline int sz(node * t) {return t ? t->s : 0;}
inline void pull(node * t) {t->s = sz(t->lc) + 1 + sz(t->rc);}
void insert(node *& t, int v)
{
	if (!t) {
		t = newnode(v);
		return;
	}
	if (t->v < v) {
		insert(t->rc,v);
		if (t->rc->p > t->p) {
			node * q = t->rc;
			t->rc = q->lc;
			pull(t);
			q->lc = t;
			t = q;
		}
	} else {
		insert(t->lc,v);
		if (t->lc->p > t->p) {
			node * q = t->lc;
			t->lc = q->rc;
			pull(t);
			q->rc = t;
			t = q;
		}
	}
	pull(t);
}
inline void tradd(node *& t,int v)
{
	insert(t,v);
}
inline int trank(node * t,int k,int s = 1)
{
	return t ? (t->v < k ? trank(t->rc,k,sz(t->lc) + 1 + s) : trank(t->lc,k,s)) : s;
}
inline int trqry(node * t,int i,int j)
{
	return trank(t,j) - trank(t,i);
}
void add(int i,int v)
{
	for ( ; i <= n; i += i & -i)
		tradd(tr[i],v);
}
int qry(int i,int vl,int vr)
{
	int ret = 0;
	for (; i; i ^= i & -i)
		ret += sz(tr[i]) - trqry(tr[i],vl,vr);
	return ret;
}
int main()
{
	freopen("friendcross.in","r",stdin);
	freopen("friendcross.out","w",stdout);
	init();
	RD(n,k);
	RP1(i,n) RD(a[i]);
	RP1(i,n/2) swap(a[i], a[n+1-i]);
	RP1(i,n) ia[a[i]] = i;
	ll ans = 0;
	DO(n) {
		DRI(x);
		x = ia[x];
		ans += qry(x-1,max(1,a[x]-k),min(n,a[x]+k)+1);
		add(x,a[x]);
	}
	PL(ans);
}
