#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[2005][2005],n,m,q;
ll qry(ll x,ll y)
{
    ll a=x%n,b=y%m;
    return (x*y-a*b)/2 + (((__builtin_popcountll(x/n) ^ __builtin_popcountll(y/m))&1)?a*b-s[a][b]:s[a][b]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        string g;
        cin >> g;
        for (int j = 1; j <= m; ++j) {
            int x=g[j-1]-'0';
            s[i][j]=s[i+n][j+m]=x;
            s[i+n][j]=s[i][j+m]=x^1;
        }
    }
    n*=2,m*=2;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    while (q--) {
        int x1,y1,x2,y2;
        cin >>x1>>y1>>x2>>y2;
        --x1,--y1;
        cout << qry(x2,y2)-qry(x1,y2)-qry(x2,y1)+qry(x1,y1) << '\n';
    }
}
