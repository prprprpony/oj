#include <bits/stdc++.h>
using namespace std;
const int maxn = 106;
const int M = 1000 * maxn / 2;
int a[maxn];
bitset<M> dp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T >> N;
	while (T--) {
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum & 1) {
			cout << "No\n";
			continue;
		}
		sum >>= 1;
		dp.reset();
		dp[0] = 1;
		for (int i = 0; i < N && !dp[sum]; ++i)
			dp |= dp << a[i];
		cout << (dp[sum] ? "Yes\n" : "No\n");
	}
}
