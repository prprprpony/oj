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
const int N = (2e5+87) * 2, M = 1e9 + 7;
const int I2 = (M+1) / 2, I3 = (M+1) / 3;
int mul(ll a,ll b) {return a * b % M;}
int add(int a,int b) {return (a += b) < M ? a : a - M;}
int sub(int a,int b) {return (a -= b) < 0 ? a + M : a;}
const int I6 = mul(I2,I3);
int a[N],st[N],tp,lt[N],rt[N];
int s1(int n)
{
    return mul(mul(n,n+1),I2);
}
int s2(int n)
{
    return mul(mul(n, mul(n+1, add(n,n+1))), I6);
}
int k1(int l,int r)
{
    return mul(mul(mul(l+1,r+1),l+r+2),I2);
}
int k2(int l,int r,int t)
{
    int f = max(min(r - t, l), 0), ans = 0;
    ans = add(mul(add(I2,r), sub(s1(t + f), s1(t))), mul(sub(0,I2), sub(s2(t + f), s2(t))));
    ans = add(ans, mul(l - f, s1(r)));
    return ans;
}
int main()
{
    RI(n);
    int mx = 0;
    RP(i,n) RD(a[i]), cmax(mx, a[i]);
    copy_n(a,n,a+n);
    st[tp++]=-1;
    RP(i,n*2) {
        while (tp > 1 && a[i] > a[st[tp-1]])
            --tp;
        lt[i] = i - st[tp-1] - 1;
        st[tp++] = i;
    }
    st[0]=2*n;
    tp=1;
    PR(i,n*2) {
        while (tp > 1 && a[i] >= a[st[tp-1]])
            --tp;
        rt[i] = st[tp-1] - i - 1;
        st[tp++] = i;
    }
    int ans=0, cnt=0;
    RP(i,n*2) {
        if (a[i] == mx)
            continue;
        int w = 0, t;
        if (i < n) {
            t = n - 1 - i;
            w = k1(lt[i], min(rt[i], t));
            if (rt[i] - t >= 2)
                w = add(w, k2(lt[i]+1,rt[i]-t-1,t));
        } else {
            t = i - n;
            if (t < lt[i] && t + rt[i] + 1 >= 2)
                w = k2(rt[i]+1,lt[i]-t,t-1);
        }
        cnt = add(cnt, w);
        ans = add(ans, mul(w, a[i]));
    }
    ans = add(ans, mul(sub(s1(s1(n)), cnt), mx));
    PL(ans);
}
