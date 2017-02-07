#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> set_t;
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
typedef pair<int,pii> pt;
const int N = 1.12e5, K = 1e4+1;
pt p[N];
set_t v[K];
map<int,int> cnt[K];
int main()
{
	int n,k;
	ll ans=0;
	RD(n,k);
	RP(i,n) RD(p[i].S.F, p[i].F, p[i].S.S);
	sort(p, p + n);
	PER(i,n,0) {
		//  xi-ri <= xj <= xi+ri
		//	fi-k <= fj <= fi+k 
		int fi = p[i].S.S, xi = p[i].S.F, ri = p[i].F;
		REP(j,max(1,fi-k),min(K,fi+k+1)) {
			pii l(xi - ri, -1e9);
			pii r(xi + ri, 1e9);
			ans += v[j].order_of_key(r) - v[j].order_of_key(l);
		}
		v[fi].insert({xi, cnt[fi][xi]++});
	}
	PL(ans);
}
