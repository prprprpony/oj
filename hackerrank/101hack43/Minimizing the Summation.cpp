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

/* Good Luck && Have Fun ! */

const int maxn = 1.12e5;
int a[maxn];
int main()
{
	int n, k;
	RD(n, k);
	RP(i,n)
		RD(a[i]);
	sort(a, a + n);
	ll s = 0, s2 = 0, v = 0;
	RP(i,k) {
		ll q = 1LL * a[i] * a[i];
		v += s2 - 2 * a[i] * s + i * q;
		s += a[i];
		s2 += q;
	}
	ll ans = v;
	REP(i,k,n) {
		ll q = 1LL * a[i-k] * a[i-k];
		s -= a[i-k];
		s2 -= q;
		v -= s2 - 2 * a[i-k] * s + (k-1) * q;
		q = 1LL * a[i] * a[i];
		v += s2 - 2 * a[i] * s + (k-1) * q;
		cmin(ans, v);
		s += a[i];
		s2 += q;
	}
	printf("%lld\n", ans<<1);
}
