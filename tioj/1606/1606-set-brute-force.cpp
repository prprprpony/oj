#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 LL;
const int Q = 5e4 + 87;
ll sumq(ll a,ll d,ll b,ll n)
{
	ll ret = 0;
	if (a >= b) {
		ret += a/b * n;
		a %= b;
	}
	if (d >= b) {
		ret += d/b * (n*(n-1)/2);
		d %= b;
	}
	if (!d)
		return ret;
	ll t = (a+(n-1)*d)/b;
	if (t)
		ret += n*t - sumq(b-a+d-1,b,d,t);
	return ret;
}
ll sumr(ll a,ll d,ll b,ll n)
{
	ll ret = 0;
	if (n >= b) {
		ret += n/b * (a*b + b*(b-1)/2*d - b * sumq(a,d,b,b));
		n %= b;
	}
	if (n)
		ret += a*n + n*(n-1)/2*d - b * sumq(a,d,b,n);
	return ret;
}
struct evt
{
	int l,r,a,d,b;
	bool operator < (const evt & x) const
	{
		return l < x.l;
	}
	ll qry(int x,int y) const
	{
		x = max(x,l);
		y = min(r,y);
		if (x > y)
			return 0;
		return sumr((a+d*1LL*(x-l)%b)%b,d,b,y-x+1);
	}
};
set<evt> st;
typedef set<evt>::iterator ptr;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	while (q--) {
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if (t == 1) {
			int a,b;
			scanf("%d%d",&a,&b);
			a %= b;
			evt x{l,r,a,a,b};
			ptr it = st.lower_bound(x);
			if (it != st.begin()) {
				ptr p = prev(it);
				if (p->r >= l) {
					int pl=p->l,pr=p->r;
					evt y(*p);
					y.r = l-1;
					st.erase(p);
					st.insert(y);
					if (pr > r) {
						st.insert({r+1,pr,(int)((y.a + (r+1LL-pl)*y.d%y.b)%y.b),y.d,y.b});
						st.insert(x);
						continue;
					}
				}
			}
			while (it != st.end() && it->r <= r)
				st.erase(it++);
			if (it != st.end() && it->l <= r) {
				evt y(*it);
				y.a = (it->a + it->d * (r+1LL-it->l) % it->b) % it->b;
				y.l = r + 1;
				st.erase(it);
				st.insert(y);
			}
			st.insert(x);
		} else {
			ll ans = 0;
			evt x{l,r,0,0,0};
			ptr it = st.lower_bound(x);
			if (it != st.begin())
				ans += prev(it)->qry(l,r);
			while (it != st.end() && it->l <= r)
				ans += (it++)->qry(l,r);
			printf("%lld\n",ans);
		}
	}
}
