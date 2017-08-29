#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
#ifdef PP
	#define DBG(m,...) fprintf(stderr,m, __VA_ARGS__)
#else
	#define DBG(m,...) 
#endif
ll add(ll a,ll b,ll n)
{
	return (a += b) < n ? a : a - n;
}
ll mul(ll a,ll b,ll n)
{
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
bool isp(ll n) // n is odd
{
	static const ll a[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	for (auto x : a)
		if (!mr(n,x))
			return 0;
	return 1;
}
const int N = 1e6 + 5;
int sev[N];
int vp[78499];
void pre()
{
	int s = 0;
	for (int i = 2; i < N; ++i) {
		if (!sev[i]) {
			sev[i] = i;
			vp[s++] = i;
		}
		for (int k = 0; k < s; ++k) {
			int j = vp[k];
			if (i * 1LL * j >= N)
				break;
			sev[i * j] = j;
			if (j == sev[i])
				break;
		}
	}
DBG("SZ(vp) = %d\n", s);
}
int main()
{
	pre();
	ll n;
	while (scanf("%lld",&n) == 1 && n) {
		for (;n&1^1;n>>=1);
		ll d = 1;
		for (auto x : vp) {
			if (n < N) {
				while (n > 1) {
					int c = 0;
					int p = sev[n];
					for (;sev[n] == p; n /= p, ++c);
					d *= (c + 1);
				}
			}
			if (x * 1LL * x * x > n)
				break;
			int c = 0;
			for (;n % x == 0;n /= x,++c);
			d *= (c + 1);
		}
		if (n != 1) {
			ll x = sqrt(n) + 0.5;
			while (x * x < n) ++x;
			while (x * x > n) --x;
			if (x * x == n)
				d *= 3;
			else if (isp(n)) 
				d *= 2;
			else
				d *= 4;
		}
		printf("%lld\n",d - 1);
	}
}
