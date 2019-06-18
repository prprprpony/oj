#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+87;
int a[N][4],pre[N][4],nxt[N][4];
void link(int i,int j,int x)
{
    nxt[i][x] = j;
    pre[j][x] = i;
}
void del(int u,int x)
{
    link(pre[u][x], nxt[u][x], x);
}
bool ok(vector<int> & s,int o)
{
    for (int x = 0; x < 4; ++x) {
        sort(begin(s),end(s),[&](int i,int j){return a[i][x]<a[j][x];});
        link(o,s[0],x);
        link(s.back(),o,x);
        for (int i = 0; i + 1 < s.size(); ++i)
            link(s[i],s[i+1],x);
    }
    int n = s.size();
    while (n > 1) {
        vector<int> t;
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
                        t.push_back(u = pre[u][l]);
                    } while (u != p[l][0]);
                    goto out;
                }

                p[r][0]=nxt[p[r][0]][r];
                p[r][1]=nxt[p[r][1]][r^1];
                if (a[p[r][0]][r] <= a[nxt[p[r][1]][r^1]][r^1]) {
                    int u=o;
                    do {
                        t.push_back(u = nxt[u][r]);
                    } while (u != p[r][0]);
                    goto out;
                }
            }
        }
out:
        if (t.empty()) 
            return false;
        n -= t.size();
        for (int u : t)
            for (int x = 0; x < 4; ++x)
                del(u,x);
        if (!ok(t,o+1))
            return false;
    }
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
    vector<int> v(n);
    iota(begin(v),end(v),0);
    cout << (ok(v,n) ? "YES\n" : "NO\n");
}
