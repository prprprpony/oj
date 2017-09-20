#include<bits/stdc++.h>
using namespace std;
const int N = 1987;
char s[N];
void solve(int l,int r,int s1,int ex)
{
	int m = (l + r) / 2;
	fill(s+m,s+r,'1');
	cout << "? "  << (s+1) << endl;
	fill(s+m,s+r,'0');
	int c;
	cin >> c;
	c -= ex;
	int x[2], y[2];
	y[1] = (s1-c+r-m)/2;
	y[0] = r-m-y[1];
	x[1] = s1-y[1];
	x[0] = m-l-x[1];
	if (x[0] && x[1])
		solve(l,m,x[1],ex+y[1]);
	else if (y[0] && y[1])
		solve(m,r,y[1],ex+x[1]);
	else {
		int p[2] = {l,m};
		if (y[0])
			swap(p[0],p[1]);
		cout << "! " << p[0] << ' ' << p[1] << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	fill_n(s+1,n,'0');
	cout << "? "  << (s+1) << endl;
	int k;
	cin >> k;
	solve(1,n+1,k,0);
}
