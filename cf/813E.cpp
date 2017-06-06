#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
deque<int> q[N];
int b[N],t[__lg(N) + 1][N];
void bld(int o,int l,int r)
{
	if (r - l == 1) {
		t[o][l] = b[l];
		return;
	}
	int m = (l + r) / 2;
	bld(o+1,l,m);
	bld(o+1,m,r);
	merge(t[o+1]+l,t[o+1]+m,t[o+1]+m,t[o+1]+r,t[o]+l);
}
int qry(int o,int l,int r,int i,int j)
{
	if (r <= i || j <= l)
		return 0;
	if (i <= l && r <= j)
		return lower_bound(t[o]+l,t[o]+r,i) - t[o] - l;
	int m = (l + r) / 2;
	return qry(o+1,l,m,i,j) +  qry(o+1,m,r,i,j);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k,m,ans=0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (q[a].size() == k) {
			b[i] = q[a].front();
			q[a].pop_front();
		} else {
			b[i] = -1;
		}
		q[a].push_back(i);
	}
	bld(0,0,n);
	cin >> m;
	while (m--) {
		int l,r;
		cin >> l >> r;
		l = (l + ans) % n;
		r = (r + ans) % n;
		if (l > r)
			swap(l,r);
		++r;
		cout << (ans = qry(0,0,n,l,r)) << '\n';
	}
}
