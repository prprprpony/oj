#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)((a).size()))
/* I AM A WEAK TRASH DEAL WITH IT */
const int B = 11;
const int N = 61;
const ll inf = 1e18;
ll dp[B][N][1<<(B-1)];
void pre()
{
	for (int b = 2; b < B; ++b) {
		ull h = 1;
		dp[b][0][0] = 1;
		for (int w = 1; h <= inf; ++w, h *= b) {
			for (int s = 0; s < (1<<b); ++s) {
				for (int d = 0; d < b; ++d) {
					dp[b][w][s] += dp[b][w-1][1<<d^s];
				}
//if (b <= 3) cerr << b << ' ' << w << ' ' << s << ' ' << dp[b][w][s] << endl;
			}
		}
	}
}
ll calc(int b,ll v)
{
	if (!v)
		return 0;
	string u;
	for (;v;v/=b)
		u += char(v%b);
	reverse(ALL(u));
/*
for (int i = 0; i < SZ(u); ++i)
	cerr << char(u[i]+'0');
cerr << endl;
*/
	ll ans = 0;
	for (int i = 2; i < SZ(u); i += 2)
		ans += dp[b][i][0] - dp[b][i-1][1];
	int s = 0;
	for (int i = 0; i < SZ(u); ++i) {
		for (int j = !i; j < u[i]; ++j)
			ans += dp[b][SZ(u) - i - 1][1<<j^s];
		s ^= 1 << u[i];
	}
	return ans + !s;
}
int main()
{
	pre();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int b;
		ll l, r;
		cin >> b >> l >> r;
/*
cerr << b << ',' << r << ' ' << calc(b,r) << endl;
cerr << b << ',' << l-1 << ' ' << calc(b,l-1) << endl;
*/
		cout << calc(b,r) - calc(b,l-1) << '\n';
	}
}
