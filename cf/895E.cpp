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
const int N = 1e5 + 87;
typedef double val;
struct node
{
    val m,k,s;
} t[N*4];
#define LC o<<1,l,m
#define RC o<<1|1,m,r
#define O t[o]
#define L t[o<<1]
#define R t[o<<1|1]
#define DA int o=1,int l=0,int r=n
#define DM int m = (l + r) / 2 
int n,q;
val a[N];
void pull(int o)
{
    O.s = L.s + R.s;
}
void dat(int o,int l,int r,val m,val k)
{
    O.s = O.s * m + (r - l) * k;
    O.m *= m;
    O.k = O.k * m + k;
}
void push(int o,int l,int m,int r)
{
    if (O.m != 1 || O.k != 0) {
        dat(LC,O.m,O.k);
        dat(RC,O.m,O.k);
        O.m = 1;
        O.k = 0;
    }
}
void init(DA)
{
    DM;
    O.m = 1;
    O.k = 0;
    if (r - l == 1) {
        O.s = a[l];
        return;
    }
    init(LC);
    init(RC);
    pull(o);
}
void upd(int i,int j,val v,DA)
{
    DM;
    if (j <= l || r <= i)
        return ;
    if (i <= l && r <= j) {
        dat(o,l,r,(j-i-1.)/(j-i),v);
        return;
    }
    push(o,l,m,r);
    upd(i,j,v,LC);
    upd(i,j,v,RC);
    pull(o);
}
val qry(int i,int j,DA)
{
    DM;
    if (j <= l || r <= i)
        return 0;
    if (i <= l && r <= j)
        return O.s;
    push(o,l,m,r);
    return qry(i,j,LC) + qry(i,j,RC);
}
int main()
{
    RD(n,q);
    RP(i,n) RD(a[i]);
    init();
    while (q--) {
        RI(ty,l,r);
        --l;
        if (ty == 1) {
            RI(i,j);
            --i;
            val s1 = qry(l,r), s2 = qry(i,j), x = 1. / (j - i) / (r - l);
            upd(l,r,s2 * x);
            upd(i,j,s1 * x);
        } else {
            PL(qry(l,r));
        }
    }
}
