#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x) {return x ? x%10+f(x/10) : 0;}
int main()
{
	ll n,s;
	cin >> n >> s;
	ll lo = 1, hi = n;
	while (lo <= hi) {
		ll mi = (lo + hi) / 2;
		if (mi - f(mi) < s)
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	cout << n - hi << endl;
}
