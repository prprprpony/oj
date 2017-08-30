#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 87;
int po[N],f[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x = min(n - i, m);
		po[i] = x;
		m -= x;
		f[i] = i&-i;
	}
	for (int i = 1; i <= n; ++i) {
		int r = po[i] + 1, v = 0;
		for (int k = 1<<__lg(n); k; k >>= 1)
			if ((v|k) <= n && f[v|k] < r) {
				v |= k;
				r -= f[v];
			}
		cout << ++v << " \n"[i == n];
		for ( ; v <= n; v += v&-v)
			--f[v];
	}
}
