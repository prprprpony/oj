#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
/* */
const int N = 64;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
const char * di = "nswe";
int n, v[N][N];
bool go(int i,int & x,int & y)
{
	int a = x + dx[i];
	int b = y + dy[i];
	if (!(0 <= a && a < n))
		return 0;
	if (!(0 <= b && b < n))
		return 0;
	if (v[a][b])
		return 0;
	v[a][b] = v[x][y] + 1;
	tie(x,y) = tie(a,b);
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int x, y;
	char w;
	int wi;
	cin >> n >> w >> x >> y;
	RP(i,4) if (w == di[i]) {wi = i; break;}
	v[x][y] = 1;
	RP(wabAlabadada,n*n-1) {
		if (go(wi,x,y))
			continue;
		if (go(wi^2,x,y))
			continue;
		if (go(wi^2^1,x,y))
			continue;
		if (go(wi^1,x,y))
			continue;
	}
	RP(i,n)
		RP(j,n)
			cout << v[i][j] << " \n"[j==n-1];
}
