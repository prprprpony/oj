#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19};
const int pw = 26;
int A, B;
ll ans = 1e8 + 1;
ll qpow(ll a, int x)
{
	int r = 1;
	for ( ; x; x >>= 1, a *= a)
		if (x & 1)
			r *= a;
	return r;
}
void dfs(int i, int j, int b, ll pro)
{
	if (pro >= ans)
		return;
	if (b == 1)
		return;
	if (i == A - 1) {
		if ((b-1) * log(p[i]) + log(pro) < log(ans))
			ans = min(ans, pro * qpow(p[i], b-1));
		return;
	}
	for (; j >= 1; --j)
		if (b % (j+1) == 0 && j * log(p[i]) + log(pro) < log(ans))
			dfs(i+1, j, b / (j+1), pro * qpow(p[i], j));
}
int main()
{
	cin >> A >> B;
	if (A == 0)
		ans = 1;
	dfs(0, pw, B, 1);
	cout << ans << '\n';
}
