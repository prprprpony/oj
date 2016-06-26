#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
inline int num(char c) {return c - '0';}
int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	ll ans = !(num(s[0]) & 3) ? 1 : 0;
	for (int i = 1; i < s.size(); i++) {
		if (!(num(s[i]) & 3))
			ans++;
		if (!((10 * num(s[i - 1]) + num(s[i])) & 3))
			ans += i;
	}
	cout << ans << '\n';
	return 0;
}