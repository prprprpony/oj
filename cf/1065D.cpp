#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
pii operator + (const pii & a,const pii & b) {return {a.F+b.F,a.S+b.S};}
const int N = 11;
const int M = 306;
const int inf = 1e9;
int n;
pii pos[M];
pii d[M][M];
pii dp[M][3];
int id(int i,int j,int k)
{
    if (i < 0 || i >= n || j < 0 || j >= n || k < 0 || k >= 3)
        return -1;
    return (i*n+j)*3+k;
}
void upd(int x,int y,pii k)
{
    if (x >= 0 && y >= 0)
        d[x][y] = min(d[x][y],k);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            pos[x] = {i,j};
        }
    const int m = n*n*3;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            d[i][j] = {inf,inf};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 3; ++k)
                for (int l = 0; l < 3; ++l)
                    if (l != k)
                        upd(id(i,j,k),id(i,j,l),{1,1});

            upd(id(i,j,0),id(i+1,j+2,0),{1,0});
            upd(id(i,j,0),id(i-1,j-2,0),{1,0});
            upd(id(i,j,0),id(i+1,j-2,0),{1,0});
            upd(id(i,j,0),id(i-1,j+2,0),{1,0});
            upd(id(i,j,0),id(i+2,j+1,0),{1,0});
            upd(id(i,j,0),id(i+2,j-1,0),{1,0});
            upd(id(i,j,0),id(i-2,j+1,0),{1,0});
            upd(id(i,j,0),id(i-2,j-1,0),{1,0});

            for (int d = 1; d < n; ++d) {
                upd(id(i,j,1),id(i+d,j+d,1),{1,0});
                upd(id(i,j,1),id(i+d,j-d,1),{1,0});
                upd(id(i,j,1),id(i-d,j-d,1),{1,0});
                upd(id(i,j,1),id(i-d,j+d,1),{1,0});
            }

            for (int d = 1; d < n; ++d) {
                upd(id(i,j,2),id(i,j+d,2),{1,0});
                upd(id(i,j,2),id(i,j-d,2),{1,0});
                upd(id(i,j,2),id(i-d,j,2),{1,0});
                upd(id(i,j,2),id(i+d,j,2),{1,0});
            }
        }

    for (int k = 0; k < m; ++k)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 2; i <= n * n; ++i) {
        int a = id(pos[i-1].F,pos[i-1].S,0);
        int b = id(pos[i].F,pos[i].S,0);
        for (int x = 0; x < 3; ++x) {
            dp[i][x] = {inf,inf};
            for (int y = 0; y < 3; ++y)
                dp[i][x] = min(dp[i][x], dp[i-1][y] + d[a+y][b+x]);
        }
    }
    pii ans = *min_element(dp[n*n],dp[n*n]+3);
    cout << ans.F << ' ' << ans.S << endl;
}
