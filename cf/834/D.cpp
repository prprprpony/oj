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
const int N = 35000 + 87, inf = 1e9;
int la[N],pr[N],dp[2][N];
struct node
{
	int mx,tg;
} t[N * 4];
void pull(int o)
{
	t[o].mx = max(t[o<<1].mx, t[o<<1|1].mx);
}
void bld(int o,int l,int r,int v[])
{
	t[o].tg = 0;
	if (r - l == 1) {
		t[o].mx = v[l];
		return ;
	}
	int m = l + ((r - l)>>1);
	bld(o<<1,l,m,v);
	bld(o<<1|1,m,r,v);
	pull(o);
}
void add(int o,int v)
{
	t[o].mx += v;
	t[o].tg += v;
}
void push(int o)
{
	if (t[o].tg) {
		add(o<<1,t[o].tg);
		add(o<<1|1,t[o].tg);
		t[o].tg = 0;
	}
}
void add(int o,int l,int r,int i,int j,int v)
{
	if (r <= i || j <= l)
		return;
	if (i <= l && r <= j) {
		add(o,v);
		return;
	}
	int m = (l + r) / 2;
	push(o);
	add(o<<1,l,m,i,j,v);
	add(o<<1|1,m,r,i,j,v);
	pull(o);
}
int qry(int o,int l,int r,int i,int j)
{
	if (r <= i || j <= l)
		return -inf;
	if (i <= l && r <= j)
		return t[o].mx;
	int m = (l + r) / 2;
	push(o);
	return max(qry(o<<1,l,m,i,j), qry(o<<1|1,m,r,i,j));
}
int main()
{
	RII(n,k);
	RP1(i,n) {
		RI(a);
		pr[i] = la[a];
		la[a] = i;
	}
	RP1(i,n) dp[1][i] = dp[1][i-1] + !pr[i];
	REP1(i,2,k) {
		int b = i & 1;
		bld(1,1,n+1,dp[b^1]);
		fill_n(dp[b]+1,i-1,-inf);
		REP1(j,i,n) {
			add(1,1,n+1,max(pr[j],1),j,1);
			dp[b][j] = qry(1,1,n+1,i-1,j);
		}
	}
	PL(dp[k&1][n]);
}
