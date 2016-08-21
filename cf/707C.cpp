#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
/*
Euclid's formula
(a^2 - b^2)^2 + (2ab)^2 = (a^2 + b^2)^2
*/
	if (n < 3)
		cout << -1;
	else if (n & 1)
		cout << (n*n-1)/2 << ' ' << (n*n+1)/2;
	else
		cout << n*n/4-1 << ' ' << n*n/4+1;
	cout << '\n';
}
