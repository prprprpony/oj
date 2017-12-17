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
template<class T,class U>
bool cmax(T & a, const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}

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
void _BG(const char * s) {cerr<<s<<endl;};
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		for (char x : "([{") c += *s == x;
		for (char x : ")]}") c -= *s == x;
	}
	cerr<<" = "<<a;
	if (sizeof...(b)) {
		cerr<<", ";
        ++s;
    }
    _BG(s,b...);
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
const int N = 2e5 + 87;
int n,ar[N],st[N],sz[N];
vi g[N];
mt19937 ran(time(0));
struct node
{
    int k,v,tg,mx;
    mt19937::result_type p;
    node * lc, * rc;
    node(int _k,int _v) : k(_k), v(_v), tg(0), mx(_v), p(ran()), lc(0), rc(0) {}
};
int MX(node * t) {return t ? t->mx : 0;}
void add(node * t,int v)
{
    if (t) {
        t->tg += v;
        t->v += v;
        t->mx += v;
    }
}
void push(node * t)
{
    if (t->tg) {
        add(t->lc, t->tg);
        add(t->rc, t->tg);
        t->tg = 0;
    }
}
void pull(node * t)
{
    t->mx = max(t->v, max(MX(t->lc), MX(t->rc)));
}
void split(node * t,int k,node *& a, node *& b) // a: <= k
{
    if (!t) {
        a = b = 0;
        return;
    }
    push(t);
    if (t->k <= k) {
        a = t;
        split(t->rc, k, a->rc, b);
        pull(a);
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        pull(b);
    }
}
node * meld(node * a,node * b)
{
    if (!a || !b)
        return a ? a : b;
    if (a->p > b->p) {
        push(a);
        a->rc = meld(a->rc, b);
        pull(a);
        return a;
    } else {
        push(b);
        b->lc = meld(a, b->lc);
        pull(b);
        return b;
    }
}
void prt(node * t)
{
    if (!t) return;
    prt(t->lc);
    BG(st[t->k],t->v,t->mx);
    prt(t->rc);
}
int qry(node * t,int i)
{
    if (!t)
        return 0;
    push(t);
    if (t->k < i)
        return qry(t->rc, i);
    return max(max(t->v, MX(t->rc)), qry(t->lc, i));
}
node * la(node * t)
{
    return t->rc ? la(t->rc) : t;
}
void flt(node * t, node * y, vector<pair<int,pii>> & v)
{
    if (!y)
        return;
    push(y);
    flt(t,y->rc,v);
    v.PB({y->k, {qry(t,y->k), max(y->v, SZ(v) ? BK(v).S.S : 0)}});
    flt(t,y->lc,v);
    delete y;
}
void upd(node *& t, node * y)
{
    vector<pair<int,pii>> v;
    flt(t,y,v);
    for (int i = 0; i < SZ(v); ++i) {
        node * l, * m, * r;
        l = 0;
        split(t, v[i].F, m, r);
        if (i + 1 < SZ(v))
            split(m,v[i+1].F,l,m);
        add(m, v[i].S.S);
        if (!m || la(m)->k != v[i].F)
            m = meld(m, new node(v[i].F, v[i].S.F + v[i].S.S));
        t = meld(meld(l,m),r);
    }
}
node * dfs(int p,int u)
{
    node * t = 0;
    sz[u] = 0;
    int w = 1;
    for (int v : g[u]) if (v != p) {
        auto pt = dfs(u,v);
        w += qry(pt,ar[u]);
        if (sz[v] > sz[u])
            swap(t,pt);
//BG(p+1,u+1,sz[u],"before upd");
        upd(t,pt);
        sz[u] += sz[v];
//BG(p+1,u+1,sz[u],"after upd");
    }
    ++sz[u];
    node *l,*m,*r;
    split(t,ar[u],l,r);
    split(l,ar[u]-1,l,m);
    if (m) delete m;
    t = meld(meld(l,new node(ar[u], w)), r);
    return t;
}
int main()
{
    RD(n);
    RP(i,n) RD(ar[i]);
    copy_n(ar,n,st);
    sort(st,st+n);
    RP(i,n) ar[i] = lower_bound(st,st+n,ar[i]) - st;
    RP(i,n-1) {
        RI(x,y);
        --x,--y;
        g[x].PB(y);
        g[y].PB(x);
    }
    auto t = dfs(-1,0);
    PL(n - t->mx);
}
