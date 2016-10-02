#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	if (n == 24) {
		if (s[0] > '2' || (s[0] == '2' && s[1] > '3'))
			s[0] = '0';
	} else {
		if (s[0] > '1') {
			if (s[1] > '0')
				s[0] = '0';
			else 
				s[0] = '1';
		} else if (s[0] == '0' && s[1] == '0') {
			s[1] = '1';
		} else if (s[0] == '1' && s[1] > '2') {
			s[1] = '0';
		}
	}
	if (s[3] >= '6')
		s[3] = '0';
	cout << s << '\n';
}
