#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
char g[100][100];
int r,c;

bool dfs(vector< vector<bool> >& vis,int i,int j)
{
	if(i<0 || i>=r || j<0 || j>=c)return 0;
	if(!vis[i][j])
	{
		vis[i][j]=1;
		for(int m=i-1;m<=i+1;m++)
			for(int n=j-1;n<=j+1;n++)
				if((m!=i || n!=j) && g[m][n]=='@')dfs(vis,m,n);
	}
	return 1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>r>>c,r)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>g[i][j];
		vector<bool> tmp(c,0);
		vector< vector<bool> > vis(r,tmp);
		int ans=0;

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(!vis[i][j] && g[i][j]=='@')ans+=dfs(vis,i,j);

		cout<<ans<<endl;
	}
	return 0;
}
