#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> cntx;
unordered_map<int,int> cnty;
map<pair<int,int>, int> cntp;
int main()
{
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans += cntx[x] + cnty[y] - cntp[{x, y}];
		++cntx[x], ++cnty[y], ++cntp[{x, y}];
	}
	printf("%lld\n", ans);
}
