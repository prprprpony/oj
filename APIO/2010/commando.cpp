#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i = (s); i != (e); ++i)
typedef long long ll;
const int maxn = 1.12e6;
ll p[maxn], dp[maxn];
struct line
{
	ll m, k;
	line() {}
	line(ll _m, ll _k) : m(_m), k(_k) {}
	ll operator () (ll x) {return m * x + k;}
} dk[maxn];
int l, r;
inline double crx(const line & a, const line & b) {return (b.k - a.k) * 1.0 / (a.m - b.m);}
int main()
{
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	rep(i,1,n+1) scanf("%d",p+i), p[i]+=p[i-1];
	dp[0] = 0;
	l = 0, r = 1;
	dk[0] = line(0, 0);
	rep(i,1,n+1) {
		while (r - l > 1 && dk[l](p[i]) <= dk[l+1](p[i]))
			++l;
		dp[i] = dk[l](p[i]) + a * p[i] * p[i] + b * p[i] + c;
		line now(-2 * a * p[i], a * p[i] * p[i] - b * p[i] + dp[i]);
		while (r - l > 1 && crx(dk[r-1], dk[r-2]) >= crx(dk[r-2], now))
			--r;
		dk[r++] = now;
/*
		a * (p[i] - p[j]) ^ 2 + b * (p[i] - p[j]) + c + dp[j]
		= p[i] * (-2a * p[j]) + (a * p[j]^2  - b * p[j] + dp[j]) + (a * p[i]^2 + b * p[i] + c)
*/
	}
	printf("%lld\n", dp[n]);
}
