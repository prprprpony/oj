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
int a[25];
bool fa[6];
bool chk(vi u,vi v)
{
    const int n = SZ(u);
    for (int i = 1; i < n; i += 2)
        if (a[u[i]] != a[u[i-1]])
            return 0;
    for (int i = 1; i < n; i += 2)
        if (a[v[i]] != a[v[i-1]])
            return 0;
    bool ok = 1;
    for (int i = 1; i < n; i += 2)
        ok &= a[u[i]] == a[v[(i+2)%n]];
    if (ok)
        return 1;
    ok = 1;
    for (int i = 1; i < n; i += 2)
        ok &= a[u[i]] == a[v[(i+n-2)%n]];
    return ok;
}
int main()
{
    RP1(i,24) RD(a[i]);
    RP(i,6) {
        fa[i] = 1;
        for (int j = i*4+2; j <= i * 4 + 4; ++j)
            fa[i] &= a[j] == a[j-1];
    }
    bool ok = 0;
    if (fa[0] && fa[2]) {
        if (a[13] == a[14] && a[15] == a[16]
            && a[5] == a[6] && a[7] == a[8]
            && a[17] == a[18] && a[19] == a[20]
            && a[21] == a[22] && a[23] == a[24]) {
            ok |= (a[13] == a[7] && a[5] == a[19] && a[17] == a[23] && a[21] == a[15])
                 || (a[13] == a[23] && a[5] == a[15] && a[17] == a[7] && a[21] == a[19]);
        }
    }
    if (fa[1] && fa[5]) {
        ok |= chk({3,4,17,19,10,9,16,14}, {1,2,18,20,12,11,15,13});
    }
    if (fa[3] && fa[4]) {
        ok |= chk({1,3,5,7,9,11,24,22}, {2,4,6,8,10,12,23,21});
    }
    PL(ok ? "YES" : "NO");
}
