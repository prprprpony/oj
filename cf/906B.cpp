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
void gao(vi & a,int n,int m)
{
    const int a43[3][4] = {{1,3,5,2},{4,6,12,9},{11,8,10,7}};
    const int a42[2][4] = {{5,4,7,2},{3,6,1,8}};
    const int a41[4] = {2,4,1,3};
    if (m == 4) {
        if (n == 1) {
            a = vi(a41,a41+4);
            return;
        }
        int i = 0;
        if (n & 1) {
            for (; i < 3; ++i)
                RP(j,4)
                    a.PB(a43[i][j]);
        }
        for (; i < n; i += 2) {
            RP(j,4)
                a.PB(i*m+a42[(i&1)^(n&1)][j]);
            RP(j,4)
                a.PB(i*m+a42[(i&1)^(n&1)^1][j]);
        }
    } else {
        RP(i,n) {
            for (int j = (i&1)+1; j <= m; j += 2)
                a.PB(i*m+j);
            for (int j = (i&1^1)+1; j <= m; j += 2)
                a.PB(i*m+j);
        }
    }
}
int n, m;
bool hao(int a,int b)
{
    int x = abs(a - b);
    return !(x == m || (x == 1 && (a-1)/m == (b-1)/m));
}
int main()
{
    RD(n,m);
    vi a;
    if (n * m <= 10) {
        RP(i,n*m) a.PB(i+1);
        do {
            bool ok = 1;
            for (int i = 0; i < n && ok; ++i)
                for (int j = 0; j < m && ok; ++j)
                    ok &= (!i || hao(a[i*m+j], a[(i - 1) * m + j])) && (!j || hao(a[i*m+j], a[i*m+j - 1]));
            if (ok) {
                PL("YES");
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < m; ++j)
                        PL<0,0>(a[i*m+j], " \n"[j==m-1]);
                return 0;
            }
        } while (next_permutation(ALL(a)));
        PL("NO");
        return 0;
    } 
    PL("YES");
    if (n < m) {
        gao(a,n,m);
        RP(i,n)
            RP(j,m)
                PL<0,0>(a[i*m+j]," \n"[j==m-1]);
    } else {
        gao(a,m,n);
        RP(j,n)
            RP(i,m) {
                int x = a[i*n+j] - 1;
                x = x % n * m + x / n + 1;
                PL<0,0>(x," \n"[i==m-1]);
            }
    }
}
