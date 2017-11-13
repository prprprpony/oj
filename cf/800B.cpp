#include<bits/stdc++.h>
using namespace std;
typedef long double db;
typedef pair<db,db> pdd;
#define X first
#define Y second
pdd operator - (const pdd & a, const pdd & b)
{
	return {a.X - b.X, a.Y - b.Y};
}
db dot(const pdd & a, const pdd & b)
{
	return a.X * b.X + a.Y * b.Y;
}
db mag2(const pdd & a)
{
	return dot(a,a);
}
db mag(const pdd & a)
{
	return sqrt(mag2(a));
}
db dist(const pdd & a, const pdd & b)
{
	return mag(b - a);
}
pdd operator * (const db & t, const pdd & v)
{
	return {t * v.X, t * v.Y};
}
pdd proj(const pdd & a, const pdd & b)
{
	return dot(a, b) / mag2(b) * b;
}
struct line
{
	pdd a,v;
	line(const pdd & q, const pdd & w) : a(q), v(w - q) {}
	db dist(const pdd & b)
	{
		const auto & c = b - a;
		return mag(c - proj(c,v));
	}
};
/*>_<*/
const int N = 1087;
pdd v[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i].X >> v[i].Y;
	v[n] = v[0], v[n+1] = v[1];
	db d = 9e18;
	for (int i = 0; i < n; ++i)
		d = min(d, dist(v[i], v[i+1]) / 2);
	for (int i = 1; i <= n; ++i)
		d = min(d, line(v[i-1], v[i+1]).dist(v[i]) / 2);
	cout << setprecision(16) << d << '\n';
}
