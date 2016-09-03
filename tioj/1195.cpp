#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		string s;
		cin >> s;
		if (s[2] == s[3] && s[3] == s[4] && s[4] == s[5])
			ans += 2000;
		else if (s[2] == s[3] && s[3] == s[4])
			ans += 1000;
		else if (s[3] == s[4] && s[4] == s[5])
			ans += 1000;
		else
			ans += 1500;
	}
	cout << ans << '\n';
}
