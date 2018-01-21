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
struct node
{
    static node * nil;
    node *p, *c[2], *mn;
    int k,v;
    node(int a,int b) : p(nil), c{nil,nil}, mn(this), k(a), v(b) {}
    node * pull()
    {
        if (this == nil) return this;
        mn = this;
        RP(i,2)
            if (c[i]->mn->v < mn->v)
                mn = c[i]->mn;
        return this;
    }
    int d()
    {
        return p->c[1] == this;
    }
    void lk(int i,node * x)
    {
        c[i] = x;
        x->p = this;
    }
    node * cc(int i)
    {
        node * x = c[i];
        lk(i,nil);
        nil->lk(0,x);
        this->pull();
        return x;
    }
    node * rot()
    {
        int i = d();
        node * x = p;
        p->lk(i,c[i^1]);
        p->pull();
        p->p->lk(p->d(),this);
        lk(i^1,x);
        return this;
    }
    node * spl()
    {
        for (;p != nil;rot())
            if (p->p != nil)
                (p->d() == d() ? p : this)->rot();
        return this->pull();
    }
    node * la()
    {
        return c[1] != nil ? c[1]->la() : this->spl();
    }
    node * fi()
    {
        return c[0] != nil ? c[0]->fi() : this->spl();
    }
};
node * node::nil = new node(-1,1e9 + 987);
int ans;
node * meld(node * a, node *b)
{
    if (a == node::nil) return b;
    if (b == node::nil) return a;
    a = a->la();
    b = b->fi();
    if (a->k == b->k) {
        a->v += b->v - 2 * ans;
        node * t = b->cc(1);
        delete b;
        b = t;
    }
    a->lk(1,b);
    return a->pull();
}
node * rm(node * t)
{
    if (t == node::nil)
        return t;
    t = t->mn->spl();
    if (t->v <= 2 * ans) {
        node * x = meld(rm(t->cc(0)), rm(t->cc(1)));
        delete t;
        t = x;
    }
    return t;
}
int main()
{
    node * b, *t, * e;
    b = t = e = node::nil;
    {
        vector<pii> a;
        char c;
        while (RD(c)) {
            c -= 'a';
            if (!SZ(a) || BK(a).F != c)
                a.PB({c,1});
            else
                ++BK(a).S;
        }
        b = new node(a[0].F,a[0].S);
        int i = 1;
        for (; i < SZ(a) - 1; ++i)
            t = meld(t, new node(a[i].F,a[i].S));
        if (i < SZ(a))
            e = new node(a[i].F,a[i].S);
    }
    while (b != node::nil && e != node::nil) {
        if (t != node::nil) {
            t = t->mn->spl();
            int k = min((t->v - 2 * ans + 1) / 2, min(b->v, e->v));
            ans += k;
            t = rm(t);
            if ((b->v -= k) == 0) {
                delete b;
                b = node::nil;
                if (t != node::nil) {
                    b = t->fi();
                    t = b->cc(1);
                    b->v -= 2 * ans;
                }
            }
            if ((e->v -= k) == 0) {
                delete e;
                e = node::nil;
                if (t != node::nil) {
                    e = t->la();
                    t = e->cc(0);
                    e->v -= 2 * ans;
                }
            }
            if (b != node::nil && t != node::nil && (t=t->fi())->k == b->k) {
                b->v += t->v - 2 * ans;
                node * x = t->cc(1);
                delete t;
                t = x;
            }
            if (e != node::nil && t != node::nil && (t=t->la())->k == e->k) {
                e->v += t->v - 2 * ans;
                node * x = t->cc(0);
                delete t;
                t = x;
            }
        } else {
            ans += min(b->v,e->v) * (b->k != e->k);
            e = node::nil;
        }
    }
    PL(ans);
}
