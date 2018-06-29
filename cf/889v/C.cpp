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
const int N = 1e6 + 87, M = 1e9 + 7;
int add(int a,int b) {return (a += b) < M ? a : a - M;}
int mul(int a,int b) {return a * 1LL * b % M;}
int f[N],fi[N];
struct seg
{
    int tg, su;
} t[N*4];
#define LC o<<1,l,m
#define RC o<<1|1,m,r
int n,k;
void init(int o = 1,int l = 0, int r = n)
{
    t[o].tg = 1;
    t[o].su = 0;
    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    init(LC);
    init(RC);
}
void dat(int o,int v)
{
    t[o].tg = mul(t[o].tg, v);
    t[o].su = mul(t[o].su, v);
}
void push(int o)
{
    if (t[o].tg != 1) {
        dat(o<<1,t[o].tg);
        dat(o<<1|1,t[o].tg);
        t[o].tg = 1;
    }
}
void pull(int o)
{
    t[o].su = add(t[o<<1].su, t[o<<1|1].su);
}
void upd(int i,int j,int v,int o = 1,int l = 0,int r = n)
{
    if (r <= i || j <= l)
        return;
    if (i <= l && r <= j) {
        dat(o,v);
        return;
    }
    push(o);
    int m = (l + r) / 2;
    upd(i,j,v,LC);
    upd(i,j,v,RC);
    pull(o);
}
void asn(int i,int v,int o = 1,int l = 0,int r = n)
{
    if (r - l == 1) {
        t[o].su = v;
        t[o].tg = 1;
        return;
    }
    int m = (l + r) / 2;
    push(o);
    if (i < m)
        asn(i,v,LC);
    else
        asn(i,v,RC);
    pull(o);
}
int qry(int i,int j,int o = 1,int l = 0,int r = n)
{
    if (r <= i || j <= l)
        return 0;
    if (i <= l && r <= j) {
        return t[o].su;
    }
    push(o);
    int m = (l + r) / 2;
    return add(qry(i,j,LC),  qry(i,j,RC));
}
int main()
{
    RD(n,k);

    f[0] = 1;
    RP1(i,n) f[i] = mul(i,f[i-1]);
    fi[0] = fi[1] = 1;
    REP1(i,2,n) fi[i] = mul(M-M/i,fi[M%i]);
    REP1(i,2,n) fi[i] = mul(fi[i],fi[i-1]);

    init();
    asn(0,1);
    int ans = 0;
    RP1(i,n) {
        int s = qry(i-k,i);
        ans = add(ans, mul(s, mul(f[n-1], fi[i-1])));
        asn(i,s);
        upd(i-k,i,i-1);
    }
    PL(add(f[n], M - ans));
}
