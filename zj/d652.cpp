#include<bits/stdc++.h>
using namespace std;
const int N = 56, inf = 1e9;
int a[N];
int d[N][N];
int dp(int i,int j)
{
	if (j - i + 1 == 2)
		return 0;
	int & now = d[i][j];
	if (now)
		return now;
	now = inf;
	for (int k = i + 1; k < j; ++k)
		now = min(now, dp(i,k) + dp(k,j) + a[i] * a[k] * a[j]);
	return now;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << dp(0,n-1) << '\n';
}
