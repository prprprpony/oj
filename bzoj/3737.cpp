#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)(a).size())
#define ALL(a) (a).begin(),(a).end()
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
bool isp(ll n)
{
    static const ll a[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (n % 2 == 0)
        return n==2;
    for (int i = 0; i < sizeof a / sizeof a[0]; ++i)
        if (!mr(n,a[i]))
            return 0;
    return 1;
}
vector<ll> d, p, ans;
void gao(int i,int j,ll n, ll x)
{
    if (n == 1) {
        ans.PB(x);
        if (x % 2)
            ans.PB(2*x);
        return;
    }
    while (j>=0&&n%p[j])
        --j;
    for (;i>=0&&d[i]+1>=p[j];--i)
        if (n % d[i] == 0) {
            ll t = n / d[i], y = x * (d[i]+1);
            while (t % (d[i] + 1) == 0)
                t /= d[i] + 1, y *= d[i] + 1;
            gao(i-1,j,t,y);
        }
}
void solve()
{
    ll n;
    scanf("%lld",&n);
    assert(n>0);
    /*
    if (n==1) {
        puts("1\n2");
        return;
    }*/
    d.clear();
    p.clear();
    ans.clear();
    for (ll i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            if (isp(i+1))
                d.push_back(i);
            if (n/i > i && isp(n/i+1))
                d.push_back(n/i);
        }
    sort(ALL(d));
    ll t = n;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            p.PB(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.PB(n);
    gao(SZ(d)-1,SZ(p)-1,t,1);
    sort(ALL(ans));
    ans.erase(unique(ALL(ans)),ans.end());
    int k = SZ(ans);
    printf("%d\n",k);
    bool f=1;
    for (int i = 0; i < k; ++i) {
        if (f)
            f=0;
        else
            putchar(' ');
        printf("%lld",ans[i]);
    }
    puts("");
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--) solve();
}
