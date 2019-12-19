#include<bits/stdc++.h>
using namespace std;
#ifndef PR3PONY
ifstream _fin("snowcow.in");
ofstream _fout("snowcow.out");
#define cin _fin
#define cout _fout
#endif
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
vector<int> g[N];
int n, q;
int lt[N], rt[N], tp;
void dfs(int u,int p)
{
    lt[u] = tp++;
    for (int v : g[u])
        if (v != p)
            dfs(v, u);
    rt[u] = tp;
}
set<pii> s[N]; // (r, l]
ll tag[N*2], sum[N*2];
void add(int i,int j,int v,int o=0,int l=0,int r=n)
{
    if (j <= l || r <= i)
        return;
    if (i <= l && r <= j) {
        tag[o] += v;
        sum[o] += v * (r - l);
        return;
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    add(i,j,v,o+1,l,m);
    add(i,j,v,z,m,r);
    sum[o] = tag[o] * (r - l) + sum[o + 1] + sum[z];
}
ll qry(int i,int j,int o=0,int l=0,int r=n, ll ot = 0)
{
    if (j <= l || r <= i)
        return 0;
    if (i <= l && r <= j)
        return sum[o] + ot * (r - l);
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    ot += tag[o];
    ll ret = qry(i,j,o+1,l,m,ot);
    ret += qry(i,j,z,m,r,ot);
    return ret;
}
void upd(set<pii> & st, int l, int r)
{
    int ml = l, mr = r;
    for (auto it = st.upper_bound({l, INT_MAX}); it != end(st) && it->S < r; st.erase(it++)) {
        add(it->S, it->F, -1);
        ml = min(ml, it->S);
        mr = max(mr, it->F);
    }
    add(ml, mr, 1);
    st.emplace(mr, ml);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    while (q--) {
        int tmw, x, c;
        cin >> tmw >> x;
        if (tmw == 1) {
            cin >> c;
            upd(s[c], lt[x], rt[x]);
        } else {
            cout << qry(lt[x], rt[x]) << '\n';
        }
    }
}
