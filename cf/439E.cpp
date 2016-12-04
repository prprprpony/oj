#include <bits/stdc++.h>
using namespace std;
// daily life
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
const int maxn = 1e5 + 1,  M = 1e9 + 7;
int lp[maxn];
vi p;
int sz, ans;
int fc[6];
int f[maxn], fi[maxn];
inline int mns(int a) {return M - a;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
inline int add(int a, int b) {return (a += b) >= M ? a - M : a;}
void build()
{
	// factoring
	REP(i,2,maxn) {
		if (!lp[i]) {
			lp[i] = i;
			p.PB(i);
		}
		for (auto v : p) {
			if (i * v >= maxn)
				break;
			lp[i * v] = v;
			if (i % v == 0)
				break;
		}
	}
	// factorial
	f[0] = 1;
	REP(i,1,maxn)
		f[i] = mul(f[i-1], i);
	fi[0] = fi[1] = 1;
	REP(i,2,maxn)
		fi[i] = mns(mul(M / i, fi[M % i]));
	REP(i,2,maxn)
		fi[i] = mul(fi[i], fi[i-1]);
}
inline int C(int n, int k)
{
	return mul(f[n], mul(fi[k], fi[n-k]));
	//	n!/k!/(n-k)!
}
inline int H(int n, int k)
{
	return C(n + k - 1, k);
}
void dfs(int n, int k, int i, int s, int pro)
{
	if (n / pro < k)
		return;
	ans = add(ans, mul(s, H(k, n / pro - k)));
	for ( ; i < sz; ++i)
		dfs(n, k, i+1, mns(s), pro * fc[i]);
}
int solve(int n, int k)
{
	int x = n;
	sz = 0;
	while (x != 1) {
		int v = fc[sz++] = lp[x];
		while (x % v == 0)
			x /= v;
	}
	ans = 0;
	dfs(n, k, 0, 1, 1);
	return ans;
}
int main()
{
	build();
	int q;
	RD(q);
	while (q--) {
		int n, f;
		RD(n, f);
		printf("%d\n", solve(n, f));
	}
}
