#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int n = 20;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	for (int i = 0; i < 1e5; ++i) {
		for (char c = 'A'; c != 'A' + n; ++c) {
			bool okk = true;
			s.push_back(c);
			for (int j = 1; j * 2 <= s.size() && okk; ++j) {
				bool ok = false;
				for (int k = 0; k < j && !ok; ++k)
					if (s[i-k] != s[i-j-k])
						ok = true;
				if (!ok)
					okk = false;
			}
			if (okk)
				break;
			else
				s.pop_back();
		}
		if (s.size() == i)
			break;
	}
	cout << s << '\n';
}
