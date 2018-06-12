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
const int N = 50, dr[] = {-1,1,0,0}, dc[]={0,0,-1,1};
char g[51][51];
int cnt[4], wa[4];
int vis[51][51], tt;
void dfs(int i,int j)
{
    vis[i][j] = tt;
    for (int k = 0; k < 4; ++k) {
        int x = i + dr[k], y = j + dc[k];
        if (0 <= x && x <N && 0 <= y && y < N && vis[x][y] != tt && g[x][y] == g[i][j])
            dfs(x,y);
    }
}
bool gofi(int c,int w)
{
    for (int i = 2; i < N; ++i)
        for (int j = 2; j < N; ++j) {
            if (g[i][j] == 'a' + c)
                continue;
            bool ok = 1;
            for (int x = i-2; x <= i; ++x)
                for (int y = j - 2; y <= j; ++y)
                    ok = ok && g[x][y] == g[i][j];
            if (ok) {
                g[i-1][j-1] = c + 'a';
                if (--w == 0)
                    return true;
            }
        }
    return false;
}
void redo()
{
    ++tt;
    fill_n(cnt,4,0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (vis[i][j] != tt) {
                dfs(i,j);
                ++cnt[g[i][j]-'a'];
            }
    for (int i = 0; i < 4; ++i) BG(i,cnt[i],wa[i]);
    for (int i = 0; i < 4; ++i) {
        if (cnt[i] < wa[i]) {
             gofi(i,wa[i]-cnt[i]);
        }
    }
}
void test()
{
    ++tt;
    fill_n(cnt,4,0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (vis[i][j] != tt) {
                dfs(i,j);
                ++cnt[g[i][j]-'a'];
            }
    bool ok = 1;
    for (int i = 0; i < 4; ++i) {
        BG(cnt[i],wa[i]);
        ok = ok && (cnt[i] == wa[i]);
    }
    assert(ok);
}
int main()
{
    fill(g[0],g[0]+N,'a');
    for (int i = 1; i <= N-2; ++i) {
        g[i][0] = 'b';
        g[i][N-1] = 'd';
    }
    fill(g[N-1],g[N-1]+N,'c');
    for (int i = 0; i < 4; ++i)
        RD(wa[i]);

    for (int i = 1, x = 0; i <= 24; ++i, x^=1)
        for (int j = 1; j <= 48; j += 2, x ^= 1)
            g[j][i] = g[j+1][i] = 'c' + x;
    for (int i = 25, x = 0; i <= 48; ++i, x^=1)
        for (int j = 1; j <= 48; j += 2, x ^= 1)
            g[j][i] = g[j+1][i] = 'a' + x;
    ++tt;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (vis[i][j] != tt) {
                dfs(i,j);
                ++cnt[g[i][j]-'a'];
            }
    ++tt;
    dfs(0,0);
    ++tt;
    dfs(1,0);
    ++tt;
    dfs(N-1,0);
    ++tt;
    dfs(1,N-1);

    for (int i = 1; i <= 24; ++i) {
        for (int j = 1; j <= 48; j += 2) {
            if (vis[j][i] > 1)
                continue;
            int c = g[j][i] - 'a';
            if (wa[c] < cnt[c]) {
                g[j][i] = g[j+1][i] = g[j][i-1] = 'b';
                --cnt[c];
            }
        }
    }

    for (int i = 48; i >= 25; --i) {
        for (int j = 1; j <= 48; j += 2) {
            if (vis[j][i] > 1)
                continue;
            int c = g[j][i] - 'a';
            if (wa[c] < cnt[c]) {
                g[j][i] = g[j+1][i] = g[j+1][i+1] = 'd';
                --cnt[c];
            }
        }
    }
//    for (int i = 0; i < 4; ++i) { BG(cnt[i],wa[i]); }
    redo();

    PL(N,N); for (int i = 0; i < N; ++i) PL(g[i]);

//    test();
}
