#include<cstdio>
#include<cstdlib>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define PB push_back
#define ALL(a) (a).begin(), (a).end()
#ifdef PP
	#define DBG(m,...) fprintf(stderr,m, __VA_ARGS__)
#else
	#define DBG(m,...) 
#endif
template<typename T>
T myabs(T x) {return x < 0 ? -x : x;}
template<typename T>
T gcd(T a,T b)
{
	T t;
	while (b) {
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}
ll add(ll a,ll b,ll n)
{
	return (a += b) < n ? a : a - n;
}
ll mul(ll a,ll b,ll n)
{
//	if (!b || a <= LLONG_MAX/b) return a * b % n;
	ll r = 0;
	for (;b;b>>=1,a=add(a,a,n))
		if (b&1)
			r = add(r,a,n);
	return r;
}
ll qpow(ll a,ll x,ll n)
{
	ll r = 1;
	for (;x;x>>=1,a=mul(a,a,n))
		if (x&1)
			r = mul(r,a,n);
	return r;
}
ll ran(ll n)
{
	static const ll b = RAND_MAX + 1LL;
	return rand() * 1.0 / b * n;
}
bool mr(ll n,ll a)
{
	if (!(a %= n))
		return 1;
	ll w = n - 1;
	int s = 0;
	for (;w%2 == 0;w/=2,++s);
	ll x = qpow(a,w,n);
	if (x == 1 || x == n - 1)
		return 1;
	for (int i = 0; i < s - 1; ++i) {
		x = mul(x,x,n);
		if (x == n - 1)
			return 1;
		if (x == 1)
			return 0;
	}
	return 0;
}
bool isp(ll n)
{
	if (n <= 2)
		return n == 2;
	if (n % 2 == 0)
		return 0;
	static const ll a[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
		if (!mr(n,a[i]))
			return 0;
	return 1;
}
ll pr(ll n,ll x,ll c)
{
	ll y = x;
	ll d = 1;
	while (d == 1) {
		x = add(mul(x,x,n),c,n);
		y = add(mul(y,y,n),c,n);
		y = add(mul(y,y,n),c,n);
		d = gcd(myabs(x-y),n);
	}
	return d;
}
void fac(ll n,vector<ll> & v)
{
	for(;n&1^1;n>>=1,v.PB(2));
	if (n == 1)
		return;
	if (isp(n)) {
		v.PB(n);
		return;
	}
	ll d = n;
	for (int c = 1; d == n; ++c)
		d = pr(n,2,c);
	fac(d,v);
	fac(n/d,v);
}
void solve()
{
	ll n;
	scanf("%lld",&n);
	vector<ll> ans;
	fac(n,ans);
for (int i = 0; i < ans.size(); ++i)
DBG("p[%d] = %lld\n",i,ans[i]);
	if (ans.size() == 1)
		puts("Prime");
	else 
		printf("%lld\n",*min_element(ALL(ans)));
}
void dpr(ll n)
{
	for (ll x = 0; x < n; ++x) 
		for (ll c = 0; c < n; ++c)
			DBG("pr:\nn = %lld, x = %lld, c = %lld, d = %lld\n",n,x,c,pr(n,x,c));
}
int main()
{
	srand(87878);
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
}
