#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) for (int i = (a), __e = (b); i <= __e; ++i)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,s,e) for (int i = (s), __e = (e); i >= __e; --i)
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

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */
/*

b + k <= 1002000

C(a+k,b+k)
= C(a+k-1,b+k-1) + C(a+k-1,b+k)
= C(a+k-1,b+k-1) + (a+k-1)! / ((a-b-1)! * (b+k)!)
= C(a+k-1,b+k-1) + (a-b)/(b+k) *  (a+k-1)! / ((a-b)! * (b+k-1)!)
= C(a+k-1,b+k-1) + (a-b)/(b+k) C(a+k-1,b+k-1)
*/
int p,ct;
void exgcd(int a,ll&x,int b,ll&y,ll&g)
{
	if (b) {
		exgcd(b,y,a%b,x,g);
		y -= a/b*x;
	} else {
		x = 1;
		y = 0;
		g = a;
	}
}
inline int inv(int a)
{
	ll x,y,g;
	exgcd(a,x,p,y,g);
	assert(g == 1);
	return (x%p+p)%p;
}
inline int add(int a,int b) {return (a+=b) < p ? a : a-p;}
inline int mul(int a,int b) {return a * 1LL * b % p;}
inline int _div(int a,int b) {return mul(a,inv(b));}
void rp(int & x,int v)
{
	while(x%p==0) {x/=p;ct+=v;}
}
int C(int n,int k)
{
	int ret = 1;
	RP1(i,k) {
		int a = n - i + 1;
		int b = i;
		rp(a,1);
		rp(b,-1);
		ret = _div(mul(ret,a%p),b%p);
	}
	return ret;
}
int main()
{
	int a,b,n;
	RD(a,b,n,p);
	if (a == b) {
		PL(1);
		return 0;
	}
	int v = C(a,b);
	int ans = ct?0:v;
	RP1(k,n) {
		int x = a+k;
		int y = b+k;
		rp(x,1);
		rp(y,-1);
		v = mul(v,_div(x%p,y%p));
		if (ct == 0)
			cmax(ans,v);
	}
	PL(ans);
}
