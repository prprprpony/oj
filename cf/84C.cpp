#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e4 + 87,inf=1e9;
pair<pii,int> a[N];
int h[N],ans;
int sqr(int x) {return x * x;}
void chk(int k,int x,int y,int i)
{
	if (h[a[k].S] < 0 && sqr(a[k].F.F+a[k].F.S-x) + sqr(y) <= sqr(a[k].F.S)) {
		h[a[k].S] = i;
		++ans;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].F.F >> a[i].F.S;
		a[i].F.F -= a[i].F.S;
		a[i].S = i;
	}
	sort(a,a+n);
	fill_n(h,n,-1);
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		int k = lower_bound(a,a+n,make_pair(pii(x,-inf),-inf)) - a;
		if (k < n)
			chk(k,x,y,i);
		if (k)
			chk(k-1,x,y,i);
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i)
		cout << h[i] << " \n"[i==n-1];
}
