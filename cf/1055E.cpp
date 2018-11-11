#include<bits/stdc++.h>
#define y0 waserdtfyguygthretwhrtrr
using namespace std;
#define SZ(a) ((int)(a).size())
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1566;
const int inf = N * N;
int n,s,m,k;
int a[N],b[N],p[N], dp[N][N], pm[N], po[N];
vector<pii> vp;
bool ok(int v)
{
    for (int i = 1; i <= n; ++i)
        p[i] = (a[i-1] <= v) + p[i-1];
    for (int i = 0; i < s; ++i)
        dp[1][i] = p[vp[i].F] - p[vp[i].S-1];
    for (int h = 2; h <= m; ++h) {
        fill_n(pm,N,-inf);
        fill_n(po,N,-inf);
        for (int i = 0; i < s; ++i) {
            int l,r;
            tie(r,l) = vp[i];
            po[r] = max(po[r], dp[h-1][i] - p[r]);
            pm[r] = max(pm[r], dp[h-1][i]);
        }
        for (int r = 1; r < N; ++r)
            pm[r] = max(pm[r],pm[r-1]);
        for (int r = N-2; r >= 0; --r)
            po[r] = max(po[r], po[r+1]);
        for (int i = 0; i < s; ++i) {
            int l,r;
            tie(r,l) = vp[i];
            dp[h][i] = p[r] - p[l-1] + max(p[l-1]  + po[l], pm[l-1]);
        }
    }
    return *max_element(dp[m],dp[m]+s) >= k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < s; ++i) {
        int l,r;
        cin >> l >> r;
        bool in = false;
        for (int j = 0; j < SZ(vp); ++j)
            if (l <= vp[j].S && vp[j].F <= r) {
                vp[j] = vp.back();
                vp.pop_back();
            } else if (vp[j].S <= l && r <= vp[j].F) {
                in = true;
                break;
            }
        if (!in)
            vp.emplace_back(r,l);
    }
    s = SZ(vp);
    m = min(m, s);
    sort(begin(vp),end(vp));
    copy_n(a,n,b);
    sort(b,b+n);
    const int C = unique(b,b+n) - b;
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(b,b+C,a[i]) - b;
    int lo = 0, hi = C-1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ok(mi))
            hi = mi - 1;
        else
            lo = mi + 1;
    }
    if (lo == C)
        cout << "-1\n";
    else
        cout << b[lo] << '\n';
}
