#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(a) ((int)a.size())
typedef long long ll;
struct Int
{
	static const ll B = 1e18;
	static const int W = 18;
	vector<ll> d;
	Int(int x)
	{
		do {
			d.PB(x % B);
		} while (x /= B);
	}
	Int operator += (const Int & x)
	{
		d.resize(max(SZ(d),SZ(x.d)), 0);
		int c = 0;
		for (int i = 0; i < SZ(d); ++i) {
			d[i] += (i < SZ(x.d) ? x.d[i] : 0) + c;
			c = d[i] >= B;
			if (c)
				d[i] -= B;
		}
		if (c)
			d.PB(1);
		return *this;
	}
} a[2] = {2, 1};
ostream& operator << (ostream& out, const Int & x)
{
	out << x.d.back();
	for (int i = SZ(x.d)-2; i >= 0; --i)
		out << setw(Int::W) << setfill('0') << x.d[i];
	return out;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 3; i <= n; ++i)
		a[i&1] += a[i&1^1];
	cout << a[n&1] << '\n';
}
