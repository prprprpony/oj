#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a),end(a)
#define SZ(a) ((int)(a).size())
void sol()
{
	string a,b;
	cin >> a >> b;
	reverse(ALL(a));
	reverse(ALL(b));
	if (SZ(a) < SZ(b))
		a.swap(b);
	for (int i = 0; i < SZ(b); ++i)
		a[i] = (a[i] - '0' + b[i] - '0') % 10 + '0';
	while (a.back() == '0' && SZ(a) > 1)
		a.pop_back();
	reverse(ALL(a));
	cout << a << '\n';
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		sol();
}
