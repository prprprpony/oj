#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
int v[26],g[26][26],vis[26], opt[26], n;
void go(int x)
{
	vis[x] = 1;
	for (int y = 0; y < 26; ++y)
		if (v[y] && g[x][y]) {
			if (!vis[y])
				go(y);
			for (int i = 0; i < 26; ++i)
				g[x][i] |= g[y][i];
		}
}
void dfs(int i)
{
	if (i == n) {
		for (int j = 0; j < n; ++j)
			cout << char('A' + opt[j]) << " \n"[j==n-1];
	}
	for (int j=0;j<26;++j)
		if (v[j] && !vis[j]) {
			int ok = 1;
			for (int k = 0; k < i && ok; ++k)
				ok &= !g[j][opt[k]];
			if (!ok) continue;
			vis[j] = 1;
			opt[i] = j;
			dfs(i+1);
			vis[j] = 0;
		}
}
void solve()
{
	static int kase = 0;
	if (kase++)
		cout << '\n';
	cin.ignore(987,'\n');
	string s;
	getline(cin,s);
	memset(v,0,sizeof v);
	for (int i = 0; i < SZ(s); ++i)
		if (isupper(s[i]))
			v[s[i]-'A'] = 1;
	n = 0;
	for (int i = 0; i < 26; ++i)
		n += v[i];
	getline(cin,s);
	stringstream ss(s);
	string t;
	memset(g,0,sizeof g);
	memset(vis,0,sizeof vis);
	while (ss >> t) 
		g[t[0]-'A'][t[2]-'A'] = 1;
	for (int i = 0; i < 26; ++i)
		if (v[i] && !vis[i])
			go(i);
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			if (g[i][j] && g[j][i]) {
				cout << "NO\n";
				return;
			}
	memset(vis,0,sizeof vis);
	dfs(0);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	cin.ignore(987,'\n');
	while (T--) solve();
}