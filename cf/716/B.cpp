#include <bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
int cnt[26],n,m,k;
void add(char c,int v)
{
	if (c == '?')
		k += v;
	else {
		c -= 'A';
		bool a = cnt[c];
		cnt[c] += v;
		bool b = cnt[c];
		if (a != b)
			m += v;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	n = SZ(s);
	bool ok = 0;
	for (int i = 0; i < n; ++i) {
		add(s[i],1);
		if (i >= 26)
			add(s[i-26],-1);
		if (m + k == 26) {
			ok = 1;
			vector<char> vc;
			for (int j = 0; j < 26; ++j)
				if (!cnt[j])
					vc.push_back(j+'A');
			for (int j = i-25; j <= i; ++j)
				if (s[j] == '?') {
					s[j] = vc.back();
					vc.pop_back();
				}
			break;
		}
	}
	if (!ok)
		cout << "-1\n";
	else {
		for (int i = 0; i < n; ++i)
			if (s[i] == '?')
				s[i] = 'A';
		cout << s << '\n';
	}
}
