#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
template<class T>
bool cmax(T & a,const T & b) {return a < b ? a = b, 1 : 0;}
template<class T>
bool cmin(T & a,const T & b) {return a > b ? a = b, 1 : 0;}
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define PER(i,a,b) for (int i((a)-1); i >= (b); --i)
#define SZ(a) ((int)(a).size())
/*>_<*/
const int N = 25;
int g[N][N],ct[8],tt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            cin >> g[i][j];
    vector<tuple<int,int,int>> ans;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 1; j <= m; ++j) {
            int x = g[i][j], y = g[i-1][j];
            if (x && y) {
                ans.emplace_back(j,x,y);
            } else if (y) {
                ++tt;
                ct[y] = tt;
                ct[g[i][j-1]] = tt;
                for (x = 1; ct[x] == tt; ++x);
                ans.emplace_back(j,x,y);
                ans.emplace_back(j,x,x);
                ans.emplace_back(j,x,x);
            }
        }
    }
    cout << ans.size() << '\n';
    for (const auto & t : ans)
        cout << "1 " << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
}
