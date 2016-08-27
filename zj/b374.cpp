#include <iostream>
#include <algorithm>
using namespace std;
const int M = 3e4 + 314;
int cnt[M];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int mc = 0;
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		mc = max(mc, ++cnt[j]);
	}
	for (int i = 1; i < M; ++i)
		if (cnt[i] == mc)
			cout << i << ' ' << mc << '\n';
}
