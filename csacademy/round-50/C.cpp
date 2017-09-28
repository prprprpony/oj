#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second 
template<class T,class U>
pair<T,U> operator - (const pair<T,U> & a, const pair<T,U> & b)
{
	return {b.F - a.F, b.S - a.S};
}
/**/
int dot(const pii & a, const pii & b)
{
	return a.F * b.F + a.S * b.S;
}
pii p[4], v[6], pr[2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 4; ++i)
			cin >> p[i].F >> p[i].S;
		int k = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j)
				v[k++] = p[j] - p[i];
		k = 0;
		for (int i = 0; i < 6; ++i)
			for (int j = i + 1; j < 6; ++j) if (v[i].F * v[j].S == v[i].S * v[j].F) {
				if (k < 2)
					pr[k++] = {i, j};
				else
					++k;
			}
		if (k != 2) {
			cout << "0\n";
			continue;
		}
		bool ok = 1;
		k = dot(v[pr[0].F],v[pr[0].F]);
		ok = ok && k == dot(v[pr[0].S],v[pr[0].S]);
		ok = ok && k == dot(v[pr[1].S],v[pr[1].S]);
		ok = ok && k == dot(v[pr[1].F],v[pr[1].F]);
		ok = ok && dot(v[pr[0].F], v[pr[1].F]) == 0;
		cout << (ok ? "1\n" : "0\n");
	}
}
