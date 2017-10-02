#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
/* */
const int M = 306;
pair<int,pii> v[M];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin >> n >> m;
	RP(i,m) {
		int x, y, w;
		cin >> x >> y >> w;
		v[i] = {w, {x,y}};
	}
	int ans = 0;
	RP(i,n)
		RP(j,n) {
			int s = 0;
			RP(k,m) {
				int t = max(abs(i - v[k].S.F), abs(j - v[k].S.S));
				if (t < v[k].F)
					s += v[k].F - t;
			}
			ans = max(ans, s);
		}
	cout << ans << '\n';
}
