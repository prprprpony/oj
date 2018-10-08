#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 897;
const int K = sqrt(N) * 2;
vector<int> g[N];
int n,m,tg[N],*cnt[N],mem[5*K*K],*ptr,t[N],on[N],s[N],pa[N],vv[N],vc[N],cv,ans;
void init(int u)
{
    if (vc[u] != cv) {
        vc[u] = cv;
        cnt[u] = ptr + K + 1;
        for (int i = -K-1; i <= K; ++i)
            cnt[u][i] = 0;
        ptr += K+K+2;
        tg[u] = -1;
    }
}
void add(int u,int v,int k)
{
    if (on[v] || vc[v] == cv || abs(k) > K)
        return;
    ++cnt[u][k];
}
int bld(int u)
{
    s[u] = on[u];
    vector<int> w;
    if (vv[u] == cv)
        w.push_back(u);
    for (int v : g[u]) {
        int x = bld(v);
        if (x)
            w.push_back(x);
        s[u] += s[v];
    }
    if (w.empty())
        return 0;
    if (w.size() > 1) {
        for (int v : w)
            pa[v] = u;
        w = {u};
    }
    init(w[0]);
    add(w[0],u,t[u] + s[u]);
    return w[0];
}
bool ck(int u) {return !on[u] && t[u] + s[u] < 0;}
int clamp(int a,int l,int r) {return a<l?l:a>r?r:a;}
int seg(int u) {return cnt[u][clamp(tg[u],-K-1,K)];}
int val(int u) {return ck(u) + seg(u);}
void upd(int u)
{
    int o=on[u]?1:-1;
    ans -= ck(u);
    on[u] ^= -1;
    ans += ck(u);
    for (;u;u=pa[u]) {
        ans -= val(u);
        s[u] += o;
        tg[u] -= o;
        ans += val(u);
    }
}
void solve(vector<int> & a)
{
    ptr = mem;
    ++cv;
    for (int u : a)
        vv[u] = cv;
    pa[bld(1)] = 0;
    for (int u=1;u<=n;++u)
        if (vc[u]==cv)
            for (int i = -K; i <= K; ++i)
                cnt[u][i] += cnt[u][i-1];
    for (int & u : a) {
        upd(u);
        u = ans;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    vector<int> q;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        q.push_back(abs(x));
        if (q.size() == K || i+1 == m) {
            solve(q);
            for (int j = 0; j < q.size(); ++j)
                cout << q[j] << " \n"[i+1==m&&j+1==q.size()];
            q.clear();
        }
    }
}
