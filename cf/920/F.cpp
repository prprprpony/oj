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
const int N = 1e6 + 87;
int lp[N],D[N];
void pre()
{
    vector<int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            lp[i] = i;
            p.PB(i);
        }
        for (int j : p) {
            if (i * 1LL * j >= N)
                break;
            lp[i*j] = j;
            if (i % j == 0)
                break;
        }
    }
    D[1] = 1;
    REP(i,2,N) {
        int c = 1, x = i, y = 0;
        for (D[i] = 1;x > 1; x /= lp[x]) {
            if (lp[x] == y) {
                ++c;
            } else {
                y = lp[x];
                D[i] *= c;
                c = 2;
            }
        }
        D[i] *= c;
    }
}
struct node
{
    ll s;
    int mx;
} t[N*4];
int a[N],n;
#define LC o<<1,l,m
#define RC o<<1|1,m,r
#define T t[o]
#define L t[o<<1]
#define R t[o<<1|1]
void pull(int o)
{
    T.mx = max(L.mx,R.mx);
    T.s = L.s + R.s;
}
void bld(int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        T = {a[l],a[l]};
        return;
    }
    int m = l + r >> 1;
    bld(LC);
    bld(RC);
    pull(o);
}
void upd(int i,int j,int o=1,int l=0,int r=n)
{
    if (r <= i || j <= l || t[o].mx <= 2)
        return;
    if (r - l == 1) {
        int x = T.mx;
        T = {D[x],D[x]};
        return;
    }
    int m = l + r >> 1;
    upd(i,j,LC);
    upd(i,j,RC);
    pull(o);
}
ll qry(int i,int j,int o=1,int l=0,int r=n)
{
    if (r <= i || j <= l)
        return 0;
    if (i <= l && r <= j)
        return T.s;
    int m = l + r >> 1;
    return qry(i,j,LC) + qry(i,j,RC);
}
int main()
{
    pre();
    int m;
    RD(n,m);
    RP(i,n) RD(a[i]);
    bld();
    while (m--) {
        RI(q,l,r);
        --l;
        if (q == 1)
            upd(l,r);
        else
            PL(qry(l,r));
    }
}
