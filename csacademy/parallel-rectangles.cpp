#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
typedef long long ll;
/*>_<*/
const int N = 1e5 + 87, S = 50;
vector<int> v[N];
bool b[N];
map<ll,int> m;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	ll ans = 0;
	for (int x = 1; x < N; ++x)
		if (SZ(v[x]) > S) {
			for (int y : v[x]) b[y] = 1;
			for (int i = 1; i < N; ++i) if (i < x || (i > x && SZ(v[i]) <= S)) {
				int c = 0;
				for (int y : v[i])
					c += b[y];
				ans += c * 1LL * (c - 1) / 2;
			}
			for (int y : v[x]) b[y] = 0;
		} else {
			sort(ALL(v[x]));
			for (int i = 0; i < SZ(v[x]); ++i)
				for (int j = i + 1; j < SZ(v[x]); ++j)
					++m[v[x][i] * 1LL * N + v[x][j]];
		}
	for (const auto & p : m)
		ans += p.second * (p.second - 1LL) / 2;
	cout << ans << '\n';
}
