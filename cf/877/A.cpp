#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
vector<string> v{"Danil", "Olya", "Slava", "Ann", "Nikita"};
int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for (auto x : v) {
		for (int i = 0; i + SZ(x) - 1 < SZ(s); ++i) {
			cnt += s.substr(i,SZ(x)) == x;
		}
	}
	cout << (cnt == 1 ? "YES" : "NO") << '\n';
}
