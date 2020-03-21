// cf 1019E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
/* STL container */
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define PB push_back
#define EB emplace_back
/* Good Luck && Have Fun ! */
/*** geometry.cpp ***/
// copied and modified from bcw_codebook
// list of algorithms: point operations, convex hull (Andrew's monotone chain), minkowski sum
#define x first
#define y second
#define cpdd const pdd
// typedef long long val_t;
typedef double db_t;
typedef __int128 val_t;
// typedef double val_t;
// typedef long double val_t;
// typedef __float128 val_t;
struct pdd : pair<val_t, val_t> {
    using pair<val_t, val_t>::pair;

    pdd operator + (cpdd &p) const {
        return {x+p.x, y+p.y};
    }

    pdd operator - () const {
        return {-x, -y};
    }

    pdd operator - (cpdd &p) const {
        return (*this) + (-p);
    }

    pdd operator * (val_t f) const {
        return {f*x, f*y};
    }

    val_t operator * (cpdd &p) const {
        return x*p.x + y*p.y;
    }
};
db_t abs(cpdd &p) { return hypot((db_t)p.x, (db_t)p.y); }
db_t arg(cpdd &p) { return atan2((db_t)p.y, (db_t)p.x); }
val_t cross(cpdd &p, cpdd &q) {const val_t L = 1; return p.x*L*q.y - p.y*L*q.x; }
val_t cross(cpdd &p, cpdd &q, cpdd &o) { return cross(p-o, q-o); }
pdd operator * (val_t f, cpdd &p) { return p*f; } // !! Not f*p !!
vector<pdd> convex_hull(vector<pdd> pt){
    sort(ALL(pt));
    pt.erase(unique(ALL(pt)), end(pt));
    int n = pt.size(), top = 0;
    if (n <= 2)
        return pt;
    vector<pdd> stk(2 * n);
    for (int i = 0; i < n; i++){
        while (top >= 2 && cross(stk[top - 1], pt[i], stk[top - 2]) <= 0)
            top--;
        stk[top++] = pt[i];
    }
    for (int i = n - 2, t = top + 1; i >= 0; i--) {
        while (top >= t && cross(stk[top - 1], pt[i], stk[top - 2]) <= 0)
            top--;
        stk[top++] = pt[i];
    }
    stk.resize(top - 1);
    return stk;
}
vector<pdd> minkowski_bruteforce(vector<pdd> a, vector<pdd> b)
{
    vector<pdd> c;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            c.PB(a[i] + b[j]);
    return convex_hull(c);
}
// copied and modified from https://www.w3xue.com/exp/article/20192/20858.html
vector<pdd> minkowski(vector<pdd> a, vector<pdd> b) 
{
    a = convex_hull(a);
    b = convex_hull(b);
    a.PB(a[0]);
    b.PB(b[0]);
    int na = a.size(), nb = b.size();
    vector<pdd> q(na + nb + 1);
    int top = -1;
    q[++top] = a[0] + b[0];
    int i = 0, j = 0;
    while(i + 1 < na && j + 1 < nb) {
        auto n1 = (a[i] + b[j + 1]) - q[top], n2 = (a[i + 1] + b[j]) - q[top];
        if(cross(n1, n2) < 0)
            q[++top] = a[i + 1] + b[j], i++;
        else
            q[++top] = a[i] + b[j + 1], j++;
    }
    for(; i < na; i++) q[++top] = a[i] + b[nb - 1];
    for(; j < nb; j++) q[++top] = b[j] + a[na - 1];
    // assert(top + 1 == q.size());
    // TODO: the assertion below failed
    // assert(q == convex_hull(q));
    return convex_hull(q);
}
/*** geometry.cpp ***/
/*** edge_decomposition.cpp ***/
const int N = 2e5 + 87; // 2n beacuse of transformation to binary tree
vector<tuple<int, int, int>> E;
vector<int> g[N];
void add_edge(int u, int v, int a, int b)
{
    g[u].PB(SZ(E));
    E.emplace_back(v, a, b);
    g[v].PB(SZ(E));
    E.emplace_back(u, a, b);
}
void build_binary_tree(int & n, int u = 1, int p = 0)
{
    int pe = -1;
    for (int & i : g[u])
        if (get<0>(E[i]) == p) {
            pe = i;
            swap(i, g[u].back());
            g[u].pop_back();
            break;
        }
    for (int i : g[u])
        build_binary_tree(n, get<0>(E[i]), u);
    while (g[u].size() > 2) {
        ++n;
        int i = g[u].back();
        g[u].pop_back();
        get<0>(E[i ^ 1]) = n;
        g[n].PB(i);
        i = g[u].back();
        g[u].pop_back();
        get<0>(E[i ^ 1]) = n;
        g[n].PB(i);
        add_edge(u, n, 0, 0);
    }
    if (pe != -1)
        g[u].PB(pe);
}

int sz[N];
void getsz(int u, int p)
{
    sz[u] = 1;
    for (int i : g[u])
        if (get<0>(E[i]) != p) {
            getsz(get<0>(E[i]), u);
            sz[u] += sz[get<0>(E[i])];
        }
}
pii find_ct(int u, int p, int n)
{
    pii ct = {INT_MAX, -1};
    for (int i : g[u]) {
        int v = get<0>(E[i]);
        if (v == p)
            continue;
        ct = min(ct, find_ct(v, u, n));
        ct = min(ct, pii(max(sz[v], n - sz[v]), i));
    }
    return ct;
}
void dfs(int u, int p, vector<pdd> & h, ll as = 0, ll bs = 0)
{
    int ch = 0;
    for (int i : g[u]) 
        if (get<0>(E[i]) != p) {
            dfs(get<0>(E[i]), u, h, as + get<1>(E[i]), bs + get<2>(E[i]));
            ++ch;
        }
    if (ch == 0)
        h.EB(as, bs);
}
vector<pdd> solve(int u0)
{
    vector<pdd> ans, lh, rh;
    getsz(u0, 0);
    if (sz[u0] == 1) {
        ans.EB(0, 0);
        return ans;
    }
    int ce = find_ct(u0, 0, sz[u0]).S;
    if (sz[u0] == 2) {
        ans.EB(get<1>(E[ce]), get<2>(E[ce]));
        return ans;
    }
    int a = get<0>(E[ce]);
    int b = get<0>(E[ce ^ 1]);
    g[a].erase(find(ALL(g[a]), ce ^ 1));
    g[b].erase(find(ALL(g[b]), ce));
    dfs(a, 0, lh);
    for (auto & p : lh) {
        p.F += get<1>(E[ce]);
        p.S += get<2>(E[ce]);
    }
    dfs(b, 0, rh);
    ans = minkowski(lh, rh);
    for (const auto & p : solve(a))
        ans.PB(p);
    for (const auto & p : solve(b))
        ans.PB(p);
    return convex_hull(ans);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        add_edge(u, v, a, b);
    }
    build_binary_tree(n);
    auto a = solve(1);
/*** edge_decomposition.cpp ***/
    a.PB(a[0]);
    int t = a.size();
    for (int i = 0; i < m; ++i) {
        pdd p(i, 1);
        // only the upper hull is needed actually
        while (t >= 2 && a[t - 1] * p < a[t - 2] * p)
            --t;
        cout << (ll)(a[t - 1] * p) << " \n"[i == m - 1];
    }
}
