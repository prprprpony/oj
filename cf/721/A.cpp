#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'B')
			++cnt;
		else if (cnt) {
			ans.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt) 
		ans.push_back(cnt);
	cout << ans.size() << '\n';
	if (ans.size()) {
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i)
			cout << ' ' << ans[i];
		cout << '\n';
	}
}
