#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+87;
int a[N][4],pre[N][4],nxt[N][4],st[2][4][N],w[N],z[N],t[N];
void link(int i,int j,int x)
{
    nxt[i][x] = j;
    pre[j][x] = i;
}
void del(int u,int x)
{
    link(pre[u][x], nxt[u][x], x);
}
bool ok(int l,int r,int d)
{
    int n = r - l, ts = l, o = N-1;
    if (n <= 1)
        return true;
    for (int x = 0; x < 4; ++x) {
        int * s = st[d][x];
        link(o,s[l],x);
        link(s[r-1],o,x);
        for (int i = l; i + 1 < r; ++i)
            link(s[i],s[i+1],x);
    }
    vector<int> sep{l};
    while (n > 1) {
        int p[4][2];
        for (int i = 0; i < 4; ++i)
            p[i][0] = p[i][1] = o;
        for (int sz = 1; sz * 2 <= n; ++sz) {
            for (int b=0;b<=2;b+=2){
                int l=b;
                int r=b^1;
                p[l][0]=pre[p[l][0]][l];
                p[l][1]=pre[p[l][1]][l^1];

                if (a[p[l][0]][l] >= a[pre[p[l][1]][l^1]][l^1]) {
                    int u=o;
                    do {
                        t[ts++] = (u = pre[u][l]);
                    } while (u != p[l][0]);
                    goto out;
                }

                p[r][0]=nxt[p[r][0]][r];
                p[r][1]=nxt[p[r][1]][r^1];
                if (a[p[r][0]][r] <= a[nxt[p[r][1]][r^1]][r^1]) {
                    int u=o;
                    do {
                        t[ts++] = (u = nxt[u][r]);
                    } while (u != p[r][0]);
                    goto out;
                }
            }
        }
out:
        if (ts == sep.back())
            return false;
        n -= ts - sep.back();
        for (int i = sep.back(); i < ts; ++i)
            for (int x = 0; x < 4; ++x) {
                w[t[i]] = sep.back();
                del(t[i],x);
            }
        sep.push_back(ts);
    }
    w[nxt[o][0]] = r-1;
    for (int x = 0; x < 4; ++x) {
        fill(z+l,z+r,0);
        for (int i = l; i < r; ++i) {
            int u = st[d][x][i];
            st[d^1][x][w[u] + z[w[u]]++] = u;
        }
    }
    for (int i = 0; i+1 < sep.size(); ++i)
        if (!ok(sep[i],sep[i+1],d^1))
            return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j)
            cin >> a[i][j];
        swap(a[i][1],a[i][2]);
    }
    for (int x = 0; x < 4; ++x) {
        int * v = st[0][x];
        iota(v,v+n,0);
        sort(v,v+n,[&](int i,int j){return a[i][x]<a[j][x];});
    }
    cout << (ok(0,n,0) ? "YES\n" : "NO\n");
}
