#include <bits/stdc++.h>
using namespace std;
const int S = 86400;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,x,s=0;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		s += a;
	}
	cout << (s == x - n + 1 ? "YES\n" : "NO\n");
}
