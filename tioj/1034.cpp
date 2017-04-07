#include<bits/stdc++.h>
using namespace std;
const int N=401,inf=0x3fffffff;
const int dr[]={0,1,-1,0};
const int dc[]={-1,0,0,1};
int d[N][N];
int n;
inline int id(int r,int c) {return r*n+c;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	int m=n*n;
	for (int i = 0; i < m; ++i) {
		fill_n(d[i],m,inf);
		d[i][i]=0;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int e;
			cin>>e;
			for (int k=0;k<4;++k) {
				int r=i+dr[k];
				int c=j+dc[k];
				if (0<=r&&r<n&&0<=c&&c<n)
					d[id(r,c)][id(i,j)] = e;
			}
		}
	for(int k=0;k<m;++k)
		for(int i=0;i<m;++i)
			for(int j=0;j<m;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int q;
	cin>>q;
	while(q--) {
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		--a,--b,--x,--y;
		int ans=inf;
		for(int i=0;i<m;++i)
			ans=min(ans,d[i][id(a,b)]+d[i][id(x,y)]);
		cout<<ans<<'\n';
	}
}
