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
template<char sep = ' ',char end = '\n',typename T, typename ...  TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e6 + 87;
ll a[N];
int q[N],mq[N];
int main()
{
	RI(T);
	while (T--) {
		RI(n);
		RP1(i,n) RD(a[i]), a[i] += a[i-1];
		++n;
		int r=0,ans=0;
		RP(i,n) {
			while (r && a[q[r-1]] > a[i]) {
				--r;
				cmax(ans, mq[r] - q[r]);
				if (r && a[mq[r-1]] <= a[mq[r]])
					mq[r-1] = mq[r];
			}
			q[r] = i;
			mq[r] = i;
			++r;
		}
		while (r) {
			--r;
			cmax(ans, mq[r] - q[r]);
			if (r && a[mq[r-1]] <= a[mq[r]])
				mq[r-1] = mq[r];
		}
		PL(ans);
	}
}
