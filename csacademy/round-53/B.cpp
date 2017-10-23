#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	if (n <= 2) {
		cout << n << '\n';
		return 0;
	}
	int la;
	cin >> la;
	--n;
	int ans = 1, s = 1, c = 1;
	int t = 0;
	while (n--) {
		int a;
		cin >> a;
		if (a == la) {
			++s;
			++c;
		} else if (a > la && t >= 0) {
			c = 1;
			++s;
			if (!t)
				t = 1;
		} else if (a < la && t <= 0) {
			c = 1;
			++s;
			if (!t)
				t = -1;
		} else {
			t = a - la;
			s = 1 + c;
			c = 1 + (a==la);
		}
		ans = max(ans, s);
		la = a;
	}
	cout << ans << '\n';

}
