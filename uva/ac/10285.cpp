#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int m[100][100],d[100][100],r,c;
bool check(int h,int i,int j)
{
    return i>=0&&i<r&&j>=0&&j<c&&m[i][j]<h;
}
int dp(int i,int j)
{
    if(d[i][j]!=0)return d[i][j];
    if(check(m[i][j],i-1,j))d[i][j]=max(d[i][j],dp(i-1,j));
    if(check(m[i][j],i+1,j))d[i][j]=max(d[i][j],dp(i+1,j));
    if(check(m[i][j],i,j-1))d[i][j]=max(d[i][j],dp(i,j-1));
    if(check(m[i][j],i,j+1))d[i][j]=max(d[i][j],dp(i,j+1));

    return ++d[i][j];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int N;
    cin>>N;
    while(N--)
    {
        string name;
        int ans=0;
        cin>>name>>r>>c;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>m[i][j];
        memset(d,0,sizeof(d));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(d[i][j]==0)ans=max(ans,dp(i,j));
        cout<<name<<": "<<ans<<endl;
    }

    return 0;
}
