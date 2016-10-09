#include <iostream>
using namespace std;
const int maxn = 1e5;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int last = -1, ans = 0;
	for (int i = 0; i + b.size() - 1 < a.size(); ++i) {
		bool ok = true;
		for (int j = 0; j < b.size() && ok; ++j)
			ok = a[i+j] == b[j];
		if (ok && (last == -1 || last + b.size() - 1 < i)) {
			last = i;
			++ans;
		}
	}
	cout << ans << '\n';

}
