#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,s,e) for (int i = (s), __e = (e); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
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

/* reading input is now 20% cooler */
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* For it's time for you to fulfill your output */
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
const int N = 1122, M = 1e9+7;
char s[N];
int a[26], la[26], lt[N], dp[N], qp[N];
int n;
int main()
{
	RD(n,s);
	RP(i,n) s[i] -= 'a';
	RP(i,26) RD(a[i]);
/*
	fill_n(la, 26, -1);
	RP(i,n) {
		lt[i] = i ? lt[i-1] : 0;
		if (i - lt[i] + 1 > a[s[i]])
			lt[i] = i - a[s[i]] + 1;
		PL(lt[i]);
	}
*/
	int ml = 0;
	RP(i,n) {
		qp[i] = i+1;
		for (int v = a[s[i]], j = 1; j <= v && j <= i + 1; ++j) {
			dp[i] = (dp[i] + (i - j >= 0 ? dp[i-j] : 1)) % M;
			cmin(qp[i], 1 + (i - j >= 0 ? qp[i-j] : 0));
			if (i >= j)
				cmin(v, a[s[i-j]]);
			cmax(ml,j);
		}
	}
	PL(dp[n-1]);
	PL(ml);
	PL(qp[n-1]);
}
