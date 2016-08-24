#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int cal(ll a) {return __lg(a) + ((a & (a - 1)) ? 1 : 0);}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	cout <<  cal(a) + cal(b) << '\n';
}
