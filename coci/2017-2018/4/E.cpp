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
template<class T,class U>
pair<T,U> operator + (const pair<T,U> & a, const pair<T,U> & b) {return {a.F+b.F,a.S+b.S};}
template<class T,class U>
pair<T,U> operator - (const pair<T,U> & a, const pair<T,U> & b) {return {a.F-b.F,a.S-b.S};}
template<class T,class U>
pair<T,U> operator += (pair<T,U> & a, const pair<T,U> & b) {return a = a + b;}
template<class T,class U>
pair<T,U> operator -= (pair<T,U> & a, const pair<T,U> & b) {return a = a - b;}
const int N = 1e5 + 87;
struct fen
{
    vi v;
    pll f[N],tot;
    void co(int x)
    {
        v.PB(x);
    }
    void init()
    {
        sort(ALL(v));
        v.erase(unique(ALL(v)),end(v));
    }
    int gi(int x)
    {
        return upper_bound(ALL(v),x) - begin(v);
    }
    void add(const pll & x)
    {
        for (int i = gi(x.S); i <= SZ(v); i += i & -i)
            f[i] += x;
        tot += x;
    }
    void sub(const pll & x)
    {
        for (int i = gi(x.S); i <= SZ(v); i += i & -i)
            f[i] -= x;
        tot -= x;
    }
    int rank(int x)
    {
        int s = 1;
        for (int i = gi(x - 1); i; i ^= i & -i)
            s += f[i].F;
        return s;
    }
    ll difsum(int x)
    {
        pll s(0,0);
        for (int i = gi(x - 1); i; i ^= i & -i)
            s += f[i];
        pll t = tot - s;
        return x * s.F - s.S + t.S - x * t.F;
    }
} f,s;
int a[N];
int main()
{
    RI(n);
    RP1(i,n) {
        RD(a[i]);
        f.co(a[i] - i);
        s.co(a[i] + i);
    }
    f.init();
    s.init();
    PR1(i,n) s.add({1,a[i]+i});
    ll ans = 9e18;
    RP1(i,n) {
        s.sub({1,a[i]+i});
        f.add({1,a[i]-i});
        int lo = 1, hi = 1e9 + 1e6;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (f.rank(mi - i) + s.rank(mi + i) - 1 <= n/2 + 1)
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        int h = max(max(i,n-i+1), hi);
        cmin(ans, f.difsum(h - i) + s.difsum(h + i));
    }
    PL(ans);
}
