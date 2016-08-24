#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int cntl = 0;
	for (auto c : s)
		if (c == 'L')
			++cntl;
	int cntr = n - cntl;
	ll ans =  0;
	for (int i = 0, j = n - 1; i < j;) {
		while (s[i] != 'R' && i < j)
			++i, --cntl;
		while (s[j] != 'L' && i < j)
			--j, --cntr;
		if (i < j) {
			if (cntl < cntr) {
				ans += cntl;
				--cntr;
				++i;
			} else {
				ans += cntr;
				--cntl;
				--j;
			}
		}
	}
	cout << ans << '\n';
}
