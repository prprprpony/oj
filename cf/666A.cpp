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
const int N = 1.12e4;
char s[N];
set<string> ans;
bool dp[N][2];
int main()
{
	RD(s);
	int n = strlen(s);
	if (n >= 7)
		dp[n-2][0] = true;
	if (n >= 8)
		dp[n-3][1] = true;
	PER(i,n-3,5) {
		dp[i][0] = dp[i+2][1] || (dp[i+2][0] && (s[i] != s[i+2] || s[i+1] != s[i+3]));
		dp[i][1] = dp[i+3][0] || (dp[i+3][1] && (s[i] != s[i+3] || s[i+1] != s[i+4] || s[i+2] != s[i+5]));
	}
	REP(i,5,n-1) {
		char c;
		RP(j,2)
		if (dp[i][j]) {
			c = s[i+j+2];
			s[i+j+2] = '\0';
			ans.insert(s + i);
			s[i+j+2] = c;
		}
	}
	PL(SZ(ans));
	for (auto x : ans)
		PL(x.c_str());
}
