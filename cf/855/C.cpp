#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
/**/
const int N = 1e5 + 9, M = 1e9 + 7;
int add(int a,int b) {return (a+=b) < M ? a : a - M;}
int mul(int a,int b) {return a * 1LL * b % M;}
int qpow(int a,int b) 
{
	int r = 1;
	for (;b;b>>=1,a=mul(a,a))
		if(b&1)
			r = mul(r,a);
	return r;
}
vector<int> g[N];
int n, m, k, x;
struct dp
{
	int d[11][3];
	dp()
	{
		memset(d,0,sizeof(d));
	}
	dp operator + (const dp & c) const
	{
		dp r;
		for (int i = 0; i <= x; ++i)
			for (int j = 0; i + j <= x; ++j) {
				r.d[i+j][0] = add(r.d[i+j][0], mul(d[i][0], add(add(c.d[j][0], c.d[j][1]), c.d[j][2])));
				if (i >= 1)
					r.d[i+j][1] = add(r.d[i+j][1], mul(d[i][1], c.d[j][0]));
				r.d[i+j][2] = add(r.d[i+j][2], mul(d[i][2], add(c.d[j][0], c.d[j][2])));
			}
		return r;
	}
};
/*
void prt(const dp & d)
{
	for (int i = 0; i <= x; ++i)
		for (int j = 0; j < 3; ++j)
			cerr << i << ',' << j << ',' << d.d[i][j] << endl;
}
*/
dp dfs(int p,int u)
{
	dp d;
	d.d[0][0] = k - 1;
	d.d[1][1] = 1;
	d.d[0][2] = m - k;
	for (int v : g[u]) if (v != p) {
		d = d + dfs(u,v); 
/*
cerr << u << "->" << v << endl;
prt(d);
*/
	}
	return d;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	cin >> k >> x;
	dp d = dfs(0, 1);
	int ans = 0;
	for (int i = 0; i <= x; ++i)
		ans = add(ans, add(d.d[i][0], add(d.d[i][1], d.d[i][2])));
	cout << ans << '\n';
}
