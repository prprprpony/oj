#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		cout << (s.count(t) ? "YES" : "NO" )<< '\n';
		s.insert(t);
	}
}
