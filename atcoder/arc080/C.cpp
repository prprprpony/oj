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
const int N = 2e5 + 87;
int a[N],b[N/2],m,rev[N];
struct sgt
{
	int t[N*2];
	void bld(int o,int l,int r)
	{
		if (r - l == 1) {
			t[o] = b[l];
			return;
		}
		int m = l + ((r - l)>>1);
		bld(o<<1,l,m);
		bld(o<<1|1,m,r);
		t[o] = min(t[o<<1],t[o<<1|1]);
	}
	int qry(int o,int l,int r,int i,int j)
	{
		if (r <= i || j <= l)
			return 1e9;
		if (i <= l && r <= j)
			return t[o];
		int m = (l + r)/2;
		return min(qry(o<<1,l,m,i,j),qry(o<<1|1,m,r,i,j));
	}
} t[2];
pii gp(int l,int r)
{
	int w = (r - l) / 2;
	int k =	t[l&1].qry(1,0,m,l/2,l/2+w);
	return {k,t[(l&1)^1].qry(1,0,m,(rev[k]+1)/2,(l+1)/2+w)};
}
typedef pair<pii,pii> hp;
priority_queue<hp,vector<hp>,greater<hp>> pq;
void ps(int l,int r)
{
	if (l < r)
		pq.push({gp(l,r),{l,r}});
}
int main()
{
	RI(n);
	RP(i,n) {RD(a[i]); rev[a[i]] = i;}
	m = n/2;
	RP(i,m) b[i] = a[2*i];
	t[0].bld(1,0,m);
	RP(i,m) b[i] = a[2*i+1];
	t[1].bld(1,0,m);
	ps(0,n);
	while (SZ(pq)) {
		pii v,x;
		tie(v,x) = pq.top();
		pq.pop();
		int l = rev[v.F];
		int r = rev[v.S];
		ps(x.F,l);
		ps(l+1,r);
		ps(r+1,x.S);
		PL<0,0>(v.F,' ',v.S," \n"[SZ(pq) == 0]);
	}
}
