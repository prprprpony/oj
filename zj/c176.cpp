#include<bits/stdc++.h>
using namespace std;
const int D = 6;
const int S = 1<<D;
const int N = 1e5+S;
typedef long long ll;
const ll inf = 2.1e13;
struct blk
{
	ll a[S],v[S],p[S+1],tg;
	int q;
	void bld()
	{
		q=-1;
		copy_n(a,S,v);
		sort(v,v+S);
		for (int j=S-1;j>=0;--j)
			p[j] = v[j] + p[j+1];
	}
	ll val(int i) 
	{
		return max(a[i] + tg,0LL);
	}
	ll qry(int i,int j)
	{
		ll ret = 0;
		for (;i<=j;++i)
			ret+=val(i);
		return ret;
	}
	ll qry()
	{
		if (q < 0 && v[q = 0] + tg < 0) {
			for (int i = S>>1; i; i>>=1)
				if (v[q|i] + tg < 0)
					q|=i;
			++q;
		}
		return p[q] + (S-q) * tg;
	}
	void add(int i,int j,ll w)
	{
		for (;i<=j;++i)
			a[i]+=w;
		bld();
	}
	void add(ll w)
	{
		tg+=w;
		q=-1;
	}
} b[N>>D];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i=0,m=0;m<n;++i,m+=S) {
		int j;
		for (j=0;j<S&&m+j<n;++j)
			cin>>b[i].a[j];
		for (;j<S;++j)
			b[i].a[j]=-inf;
		b[i].bld();
	}
	n = ((n + S - 1) >> D) << D;
	while (k--) {
		char c;
		int i,j;
		cin >> c >> i >> j;
		--i,--j;
		int l = i >> D,r = j >> D;
		i &= S-1,j &= S-1;
		if (c == 'C') {
			ll ans = 0;
			if (l == r) {
				ans = b[l].qry(i,j);
			} else {
				if (i)
					ans += b[l++].qry(i,S-1);
				if (j != S-1)
					ans += b[r--].qry(0,j);
				for (;l<=r;++l)
					ans += b[l].qry();
			}
			cout << ans << '\n';
		} else {
			ll x;
			cin >> x;
			if (c == '-')
				x = -x;
			if (l == r) {
				b[l].add(i,j,x);
			} else {
				if (i) 
					b[l++].add(i,S-1,x);
				if (j!=S-1)
					b[r--].add(0,j,x);
				for (;l<=r;++l)
					b[l].add(x);
			}
		}
	}
}

