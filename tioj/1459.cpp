#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
void exgcd(int a, int & x, int b, int & y, int & g)
{
	if (b) {
		exgcd(b, y, a % b, x, g);
		y -= a / b * x;
	} else {
		x = 1;
		y = 0;
		g = a;
	}
}
int inv(int a, int m)
{
	int x, y, g;
	exgcd(m,x,a,y,g);
	assert(g == 1);
	return (y % m + m) % m;
}
inline int mod(int a, int m) {return (a % m + m) % m;}
inline int mul(int a, int b, int m) {return a * 1LL * b % m;}
inline int _div(int a, int b, int m) {return mul(a, inv(b, m), m);}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n && n) {
		int a1, m1;
		cin >> a1 >> m1;
		bool ok = true;
		rep(i,1,n) {
			int a2, m2, g;
			cin >> a2 >> m2;
			if (!ok || !(ok = (a2 - a1) % (g = __gcd(m1, m2)) == 0))
				continue;
			m2 /= g;
			int y = _div(mod((a2 - a1) / g, m2), mod(m1 / g, m2), m2); 
			a1 += m1 * y;
			m1 *= m2;
			a1 = mod(a1, m1);
		}
		if (ok)
			printf("%d:%02d\n", (a1 / 60 % 12) ? (a1 / 60 % 12) : 12 , a1 % 60);
		else
			puts("Starvation");
	}
}
