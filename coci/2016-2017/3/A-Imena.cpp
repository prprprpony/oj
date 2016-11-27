#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,b) REP(i,0,b)
#define SZ(a) ((int)a.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	int cnt = 0;
	while (cin >> s) {
		bool ok = isupper(s[0]);
		bool flag = false;
		if (!isalpha(s.back()) && !isdigit(s.back())) {
			s.pop_back();
			flag = true;
		}
		for (int i = 1; ok && i < SZ(s); ++i)
			ok = ok && islower(s[i]);
		if (ok)
			++cnt;
		if (flag) {
			cout << cnt << '\n';
			cnt = 0;
		}
	}
}
