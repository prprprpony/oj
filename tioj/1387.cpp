#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define F first
#define S second
const int MT = 1.12e4;
const int MN = 50 * 1.12;
piii a[MN];
int dp[MT];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,T;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].S.F >> a[i].S.S >> a[i].F;
	cin >> T;
	for (int i = 0; i < n; ++i)
		while (a[i].F--)
			for (int j = T; j >= a[i].S.F; --j)
				dp[j] = max(dp[j], dp[j-a[i].S.F] + a[i].S.S);
	cout << dp[T] << '\n';
}
