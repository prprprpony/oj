#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define PB push_back
#define SZ(a) ((int)(a).size())
template<class T>
bool cmax(T & a, const T & b) {return a < b ? a = b, 1 : 0;}
/**/
const int N = 106, C = 2087;
int dp[N][C];
pii pre[N][C];
array<int,4> a[N];
void go(vector<int>&v, int i,int j)
{
	if (!dp[i][j])
		return;
	int x, y;
	tie(x,y) = pre[i][j];
	go(v,x,y);
	if (dp[x][y] < dp[i][j])
		v.PB(i);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][1] >> a[i][0] >> a[i][2];
		a[i][3] = i;
	}
	sort(a+1,a+1+n);
	for (int i = 1; i <= n; ++i) {
		memcpy(dp[i], dp[i-1], sizeof(dp[i]));
		for (int j = 0; j < C; ++j)
			pre[i][j] = {i-1,j};
		for (int j = a[i][0] - 1; j >= a[i][1]; --j)
			if (cmax(dp[i][j], dp[i-1][j - a[i][1]] + a[i][2])) {
				pre[i][j] = {i-1, j - a[i][1]};
			}
		for (int j = 1; j < C; ++j)
			if (cmax(dp[i][j], dp[i][j-1]))
				pre[i][j] = pre[i][j-1];
	}
	cout << dp[n][C-1] << '\n';
	vector<int> v;
	go(v, n, C-1);
	cout << SZ(v) << '\n';
	for (int i = 0;i<SZ(v);++i)
		cout << a[v[i]][3] << " \n"[i==SZ(v)-1];
}
