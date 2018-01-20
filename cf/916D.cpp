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
bool RD(int & a)
{
    int c;
    while (!isdigit(c = getchar()));
    a = 0;
    do {
        a = 10 * a + c - '0';
    } while (isdigit(c = getchar()));
    return 1;
}
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
const int N = 1e5 + 87, inf = 1e9 + 87;
#define tm gadgagdagagadgeovovov
struct node
{
    int s, lc, rc;
} tm[N * (35 * 2 + 17)];
int ver[N], pr[N], ptr = 1;
int add(int t,int i,int x,int l=1,int r=inf)
{
    tm[ptr] = tm[t];
    t = ptr++;
    tm[t].s += x;
    if (r - l > 1) {
        int m = l + ((r-l)>>1);
        if (i < m)
            tm[t].lc = add(tm[t].lc,i,x,l,m);
        else
            tm[t].rc = add(tm[t].rc,i,x,m,r);
    }
    return t;
}
int qry(int t,int i,int j,int l=1,int r=inf)
{
    if (!t or j <= l or r <= i)
        return 0;
    if (i <= l and r <= j)
        return tm[t].s;
    int m = l + r >> 1;
    return qry(tm[t].lc,i,j,l,m) + qry(tm[t].rc,i,j,m,r);
}
map<string,int> mp;
int id(const string & s)
{
    auto it = mp.lower_bound(s);
    if (it == end(mp) or it->F != s)
        it = mp.insert(it,{s,SZ(mp)});
    return it->S;
}
void asn(int i,int j,int v)
{
    int x = qry(pr[i],j,j+1,0,N);
    if (x)
        ver[i] = add(ver[i], x, -1);
    if (v)
        ver[i] = add(ver[i], v, 1);
    pr[i] = add(pr[i],j,v-x,0,N);
}
int main()
{
    RI(q);
    char cmd[20], s[20];
    REP(i,1,q+1) {
        fflush(stdout);
        ver[i] = ver[i-1];
        pr[i] = pr[i-1];
        int x,p;
        RD(cmd);
        switch (cmd[0]) {
        case 's':
            RD(s,x);
            p = id(s);
            asn(i,p,x);
            break;
        case 'r':
            RD(s);
            p = id(s);
            asn(i,p,0);
            break;
        case 'q':
            RD(s);
            p = id(s);
            if (p=qry(pr[i],p,p+1,0,N))
                PL(qry(ver[i],1,p));
            else
                PL(-1);
            break;
        case 'u':
            RD(x);
            ver[i] = ver[i-x-1];
            pr[i] = pr[i-x-1];
            break;
        }
    }
}
