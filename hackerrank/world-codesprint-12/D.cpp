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
const int N = 1e5 + 87, M = 1e9, W = 40;
int mul(int a,int b) {return a * 1LL * b % M;}
int add(int a,int b) {return (a += b) < M ? a : a - M;}
int f[W], n, a[N], t[N * 4][W];
void da(int o,int v)
{
    int i;
    for (i = W - 1; i > v; --i)
        t[o][i] = t[o][i - v];
    for (;i;--i)
        t[o][i] = 0;
    t[o][0] += v;
}
void push(int o)
{
    if (t[o][0]) {
        da(o<<1,t[o][0]);
        da(o<<1|1,t[o][0]);
        t[o][0] = 0;
    }
}
void pull(int o)
{
    REP(i,1,W)
        t[o][i] = t[o<<1][i] + t[o<<1|1][i];
}
void bld(int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        if (a[l] < W)
            ++t[o][a[l]];
        return;
    }
    int m = l + ((r - l)>>1);
    bld(o<<1,l,m);
    bld(o<<1|1,m,r);
    pull(o);
}
int asn(int i,int v,int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        int j;
        for (j=1;j<W && !t[o][j];++j);
        if (j < W)
            --t[o][j];
        if (v < W)
            ++t[o][v];
        return j;
    }
    if (v < W)
        ++t[o][v];
    push(o);
    int m = l + ((r - l)>>1);
    int j = i < m ? asn(i,v,o<<1,l,m) 
                  : asn(i,v,o<<1|1,m,r);
    if (j < W)
        --t[o][j];
    return j;
}
void da(int i,int j,int v,int o=1,int l=0,int r=n)
{
    if (j <= l || r <= i)
        return;
    if (i <= l && r <= j) {
        da(o,v);
        return;
    }
    push(o);
    int m = l + r >> 1;
    da(i,j,v,o<<1,l,m);
    da(i,j,v,o<<1|1,m,r);
    pull(o);
}
int qry(int i,int j,int o=1,int l=0,int r=n)
{
    if (j <= l || r <= i)
        return 0;
    if (i <= l && r <= j) {
        int s = 0;
        REP(k,1,W)
           s = add(s, mul(t[o][k], f[k]));
        return s;
    }
    push(o);
    int m = l + r >> 1;
    return add(qry(i,j,o<<1,l,m), qry(i,j,o<<1|1,m,r));
}
int main()
{
    f[0] = 1;
    REP(i,1,W)
        f[i] = mul(f[i-1], i);
    int m;
    RD(n,m);
    RP(i,n) RD(a[i]);
    bld();
    while (m--) {
        RI(x,l,r);
        --l;
        if (x == 1) 
            da(l,r,1);
        else if (x == 2)
            PL(qry(l,r));
        else
            asn(l,r);
    }
}
