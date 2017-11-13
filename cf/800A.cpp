#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 987;
pii a[N];
int main()
{
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
		cin >> a[i].F >> a[i].S;
	sort(a,a+n,
		[] (const pii & x,const pii &y) -> bool {
			return x.S * 1LL * y.F < y.S * 1LL * x.F;
		}
	);
	double tl=a[0].S*1.0/a[0].F, tr, tp = 0, s = a[0].F;
	for (int i = 1; i < n; ++i) {
		tr = a[i].S*1.0/a[i].F;
		double dt = tr - tl;
		double w = dt * s / p;
		if (tp + w > tr)
			break;
		tp += w;
		s += a[i].F;
		tl = tr;
	}
	double r = p / s;
	if (r < 1)
		cout << setprecision(16) << (tp += (tl-tp) / (1 - r)) << '\n';
	else
		cout << "-1\n";

}
