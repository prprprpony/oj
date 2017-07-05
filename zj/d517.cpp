#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	map<string,int> m;
	while (cin >> n) {
		m.clear();
		for (int i = 0; i < n; ++i) {
			cin >> s;
			auto p = m.insert({s,m.size()+1});
			cout << (p.S ? "New" : "Old") << "! " << p.F->S << '\n';
		}
	}
}
