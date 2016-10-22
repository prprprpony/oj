#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.4e4;
int a[maxn];
inline int sqr(int x) {return x * x;}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		ans += sqr(a[i] - a[i-1]);
	cout << ans << '\n';
}
