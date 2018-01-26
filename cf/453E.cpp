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
struct pony
{
    int s,m,r;
} p[N];
int n;
struct fen
{
    ll f[N];
    void add(int i,ll x)
    {
        for (; i <= n; i += i & -i)
            f[i] += x;
    }
    ll qry(int i)
    {
        ll ans = 0;
        for (; i; i ^= i & -i)
            ans += f[i];
        return ans;
    }
    ll qry(int l,int r)
    {
        return qry(r) - qry(l-1);
    }
} fr, fm;
ll ans[N];
vector<pair<pii,pii>> qry;
int main()
{
    set<int> un;
    set<pair<pii,int>> z;
    vector<pii> vl;
    RD(n);
    RP1(i,n) {
        RD(p[i].s,p[i].m,p[i].r);
        if (p[i].r) {
            fr.add(i,p[i].r);
            vl.PB({p[i].m / p[i].r, i});
        }
        un.insert(i);
    }
    RI(m);
    RP(i,m) {
        RI(t,l,r);
        for (auto it = un.lower_bound(l); it != end(un) and *it <= r; un.erase(it++))
            ans[i] += min(p[*it].s + t * 1LL * p[*it].r, p[*it].m * 1LL);
        for (auto it = z.lower_bound({{l,INT_MIN},INT_MIN}); it != end(z) and it->F.S <= r; z.erase(it++)) {
            if (it->F.S < l)
                z.insert(it, {{l-1,it->F.S}, it->S});
            if (it->F.F > r)
                z.insert(it, {{it->F.F,r+1}, it->S});
            qry.PB(make_pair(pii(t - it->S, i),pii(max(l,it->F.S), min(r,it->F.F))));
        }
        z.insert({{r,l},t});
    } 
    sort(ALL(vl));
    sort(ALL(qry));
    int j = 0;
    for (const auto & x : qry) {
        int t, i, l, r;
        tie(t,i) = x.F;
        tie(l,r) = x.S;
        for (;j < SZ(vl) and vl[j].F < t; ++j) {
            int k = vl[j].S;
            fr.add(k, -p[k].r);
            fm.add(k, p[k].m);
        }
        ans[i] += t * fr.qry(l,r) + fm.qry(l,r);
    }
    RP(i,m) PL(ans[i]);
}
