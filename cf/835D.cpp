#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a), _B(b); i < _B; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1), _B(b); i >= _B; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) REP(__i,0,n)
template<typename T>
void cmax(T & a, T b) {a = max(a, b);}
template<typename T>
void cmin(T & a, T b) {a = min(a, b);}

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define CLR(a) a.clear()
#define BK(a) (a.back())
#define FT(a) (a.front())
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<typename T, typename ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		switch (*s) {
		case '(':
		case '[':
		case '{':
			++c;
			break;
		case ')':
		case ']':
		case '}':
			--c;
			break;
		}
	}
	cerr<<" = "<<a;
	if (*s) {
		cerr<<", ";
		_BG(++s,b...);
	} else
		cerr<<endl;
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define RI(a) int a; RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const double a) {printf("%.16f", a);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
const int N = 5006;
const int K = 2;
const int P[K] = {37,61}, M[K] = {1000000000+9,1000000000+7};
int p[N][K];
struct hs
{
	int h[N][K];
	int mul(int a,int b,int k) {return a * 1LL * b % M[k];}
	int add(int a,int b,int k) {return (a += b) < M[k] ? a : a - M[k];}
	int sub(int a,int b,int k) {return (a -= b) >= 0 ? a : a + M[k];}
	void pre()
	{
		RP(k,K) {
			p[0][k] = 1;
			REP(i,1,N) p[i][k] = mul(p[i-1][k], P[k], k);
		}
	}
	void init(char * s,int n)
	{
		RP(k,K) {
			h[0][k] = 0;
			RP1(i,n) h[i][k] = add(mul(h[i-1][k],P[k], k), s[i-1] - 'a', k);
		}
	}
	array<int,K> val(int i,int j) // [i,j)
	{
		array<int,K> ret;
		RP(k,K) ret[k] = sub(h[j][k], mul(h[i][k], p[j-i][k], k), k);
		return ret;
	}
} x,y;
char s[N];
int dp[N][N],ans[N];
int main()
{
	RD(s);
	int n = strlen(s);
	x.pre();
	x.init(s,n);
	reverse(s,s+n);
	y.init(s,n);
	fill_n(dp[1],n,1);
	ans[1] = n;
	REP1(w,2,n) {
		int k = w>>1;
		int r = k + (w&1);
		RP(i,n-w+1) {
			dp[w][i] = x.val(i+r,i+r+k) == y.val(n-i-k,n-i);
			if (dp[k][i] && dp[k][i] == dp[k][i+r] && x.val(i,i+k) == x.val(i+r,i+r+k))
				dp[w][i] = 1 + dp[k][i];
			++ans[dp[w][i]];
		}
	}
	PR1(i,n-1) ans[i] += ans[i+1];
	RP1(i,n) PL<0,0>(ans[i]," \n"[i==n]);
}
