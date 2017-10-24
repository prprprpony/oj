#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
/*>_<*/
const int N = 5566;
int cnt[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = SZ(s);
	for (int i = 0; i < n; ++i)
		cnt[i+1] = s[i] - 'a' + cnt[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i - 1; j <= n; ++j) {
			int v = cnt[j] - cnt[i-1]
				 + i - 1 - cnt[i-1]
				 + n - j - (cnt[n] - cnt[j]);
			ans = max(ans, v);
		}
	cout << ans << '\n';
}
