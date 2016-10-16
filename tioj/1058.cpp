#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int n = a.find_first_of('.');
	int m = b.find_first_of('.');
	if (n < 0)
		n = a.size();
	if (m < 0)
		m = b.size();
	if (n != m) {
		cout << (n > m ? a : b) << '\n';
	} else {
		for (int i = 0; i < a.size() && i < b.size(); ++i)
			if (a[i] != b[i]) {
				cout << (a[i] > b[i] ? a : b) << '\n';
				return 0;
			}
		cout << (a.size() > b.size() ? a : b) << '\n';
	}
}
