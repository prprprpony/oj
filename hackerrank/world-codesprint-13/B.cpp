#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define F first
#define S second
const int N = 1e5 + 987;
string name[N];
int grade[N],dsu[N],sz[N][4],lim[4];
map<string,int> id;
int find(int x) {return x == dsu[x] ? x : dsu[x] = find(dsu[x]);}
void meld(int x,int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    for (int i = 0; i < 4; ++i)
        if (sz[x][i] + sz[y][i] > lim[i])
            return;
    dsu[y] = x;
    for (int i = 0; i < 4; ++i)
        sz[x][i] += sz[y][i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a;
    cin >> n >> m >> a >> lim[0] >> lim[1] >> lim[2] >> lim[3];
    for (int i = 1; i <= n; ++i) {
        cin >> name[i] >> grade[i];
        id[name[i]] = i;
        dsu[i] = i;
        sz[i][0] = sz[i][grade[i]] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        string x,y;
        cin >> x >> y;
        meld(id[x],id[y]);
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i)
        mx = max(mx, sz[i][0]);
    if (mx < a) {
        cout << "no groups\n";
        return 0;
    }
    for (auto it = begin(id); it != end(id); ++it)
        if (sz[find(it->S)][0] == mx)
            cout << it->F << '\n';
}
