#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 2.5;
#define F first
#define S second
pair<int,int> a[N];
bool v[N];
int n,cc;
void add(int k)
{
	++cc;
	v[k] = true;
	int p = -87,q = n+87;
	for (int x = 2; x >= 1; --x) {
		if (k-x >= 0 && v[k-x])
			p = k-x;
		if (k+x < n && v[k+x])
			q = k+x;
	}
	if (k-p <= 2 || q-k <= 2) {
		--cc;
		if (k-p <= 2 && q-k <= 2 && q-p > 2)
			--cc;
	}
}
void del(int k)
{
	v[k] = false;
	int p = -87,q = n+87;
	for (int x = 2; x >= 1; --x) {
		if (k-x >= 0 && v[k-x])
			p = k-x;
		if (k+x < n && v[k+x])
			q = k+x;
	}
	if (k-p <= 2 && q-k <= 2 && q-p > 2)
		++cc;
	else if (!(k-p <= 2) && !(q-k <= 2))
		--cc;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&a[i].F);
			a[i].S = i;
		}
		sort(a,a+n);
		int l,r;
		for (int i = 0; i < n; ++i)
			if (a[i].S == 0)
				l = i;
			else if (a[i].S == n - 1)
				r = i;
		if (l > r)
			swap(l,r);
		++r;
		fill_n(v,n,false);
		cc=0;
		for (int i = 0; i < r; ++i)
			add(a[i].S);
		long long ans = a[n-1].F - 1LL * a[0].F;
		for (int i = 0, j = r; i <= l; ++i) {
			for ( ; cc != 1 && j < n; ++j)
				add(a[j].S);
			if (cc != 1)
				break;
			ans = min(ans, a[j-1].F - 1LL * a[i].F);
			del(a[i].S);
		}
		printf("%lld\n",ans);
	}
}
