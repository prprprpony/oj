#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	char a, b, c;
	cin >> a >> b >> c;
	cout << (a - '0') + (b == '+' ? 1 : -1) * (c - '0') << '\n';
}
