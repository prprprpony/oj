#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a),end(a)
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9 + 7, N = 4e4, Q = 4e5;
const int S = 75;
int a[N],b[N],g[N],ans[Q],cnt[N];
pair<pii,int> qry[Q];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    copy_n(a,n,b);
    sort(b,b+n);
    int m = unique(b,b+n) - b;
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(b,b+m,a[i]) - b;
    for (int i = 0; i * S < n; ++i)
        fill_n(g+i*S,min(S,n-i*S),i);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        qry[i] = {pii(l,r), i};
    }
    sort(qry,qry+q,[&](const pair<pii,int> & x, const pair<pii,int> & y)->bool{
        return g[x.F.F] != g[y.F.F] ? g[x.F.F] < g[y.F.F] :
               (g[x.F.F] & 1)       ? x.F.S < y.F.S       :
                                      x.F.S > y.F.S       ;
    });
    int l = 0, r = 0;
    long long s = 0;
    auto add = [&] (int x) {
        s += b[x] * (2 * cnt[x] + 1LL) % M;
        ++cnt[x];
    };
    auto sub = [&] (int x) {
        --cnt[x];
        s -= b[x] * (2 * cnt[x] + 1LL) % M;
    };
    for (int i = 0; i < q; ++i) {
        const pair<pii,int> & w = qry[i];
        while (r < w.F.S)
            add(a[r++]);
        while (l > w.F.F)
            add(a[--l]);
        while (r > w.F.S)
            sub(a[--r]);
        while (l < w.F.F)
            sub(a[l++]);
        s %= M;
        if (s < 0)
            s += M;
        ans[w.S] = s;
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
