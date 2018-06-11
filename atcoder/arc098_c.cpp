#include<bits/stdc++.h>
using namespace std;
const int N = 2087, inf = 1e9 + 7;
int n,k,q;
int a[N],g[N],ct[N],si[N];
int solve(int bi)
{
    int mn = a[si[bi]];
    int m = 0;
    memset(ct,0,sizeof(ct));
    for (int i = 0; i < n; ++i) {
        if (a[i] < mn) {
            ++m;
            continue;
        }
        g[i] = m;
        ++ct[m];
    }
    int rm = q, mx = inf;
    for (int i = bi; i < n && rm; ++i) {
        int j = si[i];
        if (ct[g[j]] >= k) {
            --ct[g[j]];
            --rm;
            mx = a[j];
        }
    }
    return rm ? inf : mx - mn;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        si[i] = i;
    }
    sort(si,si+n,[&](int i,int j)->bool{return a[i] < a[j];});
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        int v = solve(i);
        if (v == inf)
            break;
        ans = min(ans, v);
    }
    cout << ans << endl;
}
