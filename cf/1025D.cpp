#include<bits/stdc++.h>
using namespace std;
const int N = 707;
bitset<N> lr[N][2],g[N];
int a[N];
void add(int u,int o,int v)
{
    if (lr[u][o][v])
        return;
    lr[u][o][v] = 1;
    for (int x = lr[u][o^1]._Find_first(); x != lr[u][o^1].size(); x = lr[u][o^1]._Find_next(x)) {
        // x v
        int l = min(x,v), r = max(x,v);
        if (l > 0 && g[u][l-1])
            add(l-1,1,r);
        if (r+1<N && g[u][r+1])
            add(r+1,0,l);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < i; ++j)
            g[i][j] = g[j][i] = __gcd(a[i],a[j]) > 1;
    }
    for (int i = 0; i < n; ++i) {
        add(i,0,i);
        add(i,1,i);
    }
    for (int i = 0; i < n; ++i)
        if (lr[i][0][0] && lr[i][1][n-1]) {
            cout << "Yes\n";
            return 0;
        }
    cout << "No\n";
}
