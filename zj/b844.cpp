#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 87;
int a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q;
	while (cin >> n >> q) {
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a,a+n);
		while (q--) {
			int p;
			cin >> p;
			cout << ((upper_bound(a,a+n,p)-a)&1) << '\n';
		}
	}
}

