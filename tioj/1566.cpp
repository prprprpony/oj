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

// input
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */
int main()
{
	int n,m;
	ll k;
	RD(n,m,k);
	cmin(m,n);
	deque<pll> mn, mx;
	vector<pii> ans;
	RP(i,n+m-2) {
		if (i < n) {
			ll h;
			RD(h);
			while (SZ(mn) && BK(mn).S >= h)
				DB(mn);
			mn.EB(i,h);
			while (SZ(mx) && BK(mx).S <= h)
				DB(mx);
			mx.EB(i,h);
		}
		while (FT(mn).F + m <= i)
			DF(mn);
		while (FT(mx).F + m <= i)
			DF(mx);
		if (FT(mx).S - FT(mn).S == k)
			ans.EB(max(0,i-m+1),min(n-1,i));
	}
	printf("%d\n", SZ(ans));
	for (auto x : ans)
		printf("%d %d\n", x.F+1, x.S+1);
}
