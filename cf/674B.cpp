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
template<char end = '\n'>
void PL(void) {PT(end);}
template<char end = '\n', typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL<end>(b...);}

/* Good Luck && Have Fun ! */
bool v[1087];
int main()
{
	DRII(n,k);
	DRIIII(a,b,c,d);
	if (n == 4 || k < n + 1) {
		PL(-1);
		return 0;
	}
	v[a] = v[b] = v[c] = v[d] = true;
	PL<' '>(a,c);
	RP1(i,n) if (!v[i])
		PL<' '>(i);
	PL(d,b);
	PL<' '>(c,a);
	RP1(i,n) if (!v[i])
		PL<' '>(i);
	PL(b,d);
}
