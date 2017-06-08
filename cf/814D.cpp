#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1087;
ll x[N],y[N],r[N];
vector<int> g[N];
bool s[N];
ll sqr(ll t) {return t * t;}
ll dfs(int u)
{
	ll ans = sqr(r[u]);
	for (int v : g[u])
		ans -= dfs(v);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i] >> r[i];
	for (int i = 0; i < n; ++i) {
		int p = -1;
		for (int j = 0; j < n; ++j)
			if (r[j] > r[i] && sqr(x[i]-x[j]) + sqr(y[i]-y[j]) < sqr(r[j]) && (p == -1 || r[j] < r[p]))
				p = j;
		if (p != -1) {
			g[p].push_back(i);
			s[i] = 1;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		if (!s[i]) {
			ans += sqr(r[i]);
			for (int j : g[i])
				ans += dfs(j);
		}
	cout << setprecision(15) << ans * acos(-1) << '\n';
}
