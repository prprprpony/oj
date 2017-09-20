#include <bits/stdc++.h>
using namespace std;
#define D 19
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define PB push_back
template<class T,class U>
ostream& operator << (ostream&out,const pair<T,U> & v)
{
	return out << '(' << v.F << ',' << v.S << ')';
}
template<class T>
ostream& operator << (ostream&out,const vector<T> & v)
{
	out << '[';
	for (int i = 0; i < SZ(v); ++i)
		out << v[i] << ",]"[i==SZ(v)-1];
	return out;
}
const int N = 1e5 + 987;
vector<pii> a[2];
void div(const pii & x, vector<pii> & v, int b, int g = 1)
{
	int k = (x.F+1) / 2;
	if (k&1^g)
		--k;
	if (k)
		v.PB({k, x.S | b});
	if (x.F-k)
		v.PB({x.F - k, x.S});
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	a[0] = {{n,0}};
	for (int i = 0; i < D; ++i) {
		a[i&1^1].clear();
		int j = 0;
		if (x>>i&1) 
			div(a[i&1][j++],a[i&1^1], 1<<i);
		for (; j + 1 < SZ(a[i&1]); j += 2) {
			div(a[i&1][j],a[i&1^1], 1<<i);
			div(a[i&1][j+1],a[i&1^1], 1<<i);
		}
		if (j < SZ(a[i&1]))
			div(a[i&1][j],a[i&1^1], 1<<i, 0);
		sort(ALL(a[i&1^1]), greater<pii>());
	}
//	cerr << a[n&1] << endl;
	if (SZ(a[n&1]) != n) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << a[n&1][i].S << " \n"[i == n - 1];
}
