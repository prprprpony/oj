#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 87;
const int W = 11;
const int MAXC = 1e6 + 1;
int N, Q, C, P, A[MAXN];
vector<int> vp;
vector<int> f[W];
struct seg
{
    int tag;
    int mn;
    int ans;
    int c0;
    seg() {}
    seg(int v) : tag(0), mn(0), ans(v % P), c0(v == 0) {}
    void apply(int tdd)
    {
        tag += tdd;
        mn += tdd;
        ans = -1;
    }
} t[MAXN * 2];
void pull(int o, int z)
{
    if (t[o + 1].ans < 0 || t[z].ans < 0)
        t[o].ans = -1;
    else
        t[o].ans = (t[o + 1].ans + t[z].ans) % P;
    t[o].mn = min(t[o + 1].mn, t[z].mn);
    t[o].c0 = t[o + 1].c0 + t[z].c0;
}
void push(int o, int z)
{
    if (t[o].tag) {
        t[o + 1].apply(t[o].tag);
        t[z].apply(t[o].tag);
        t[o].tag = 0;
    }
}
void bld(int o = 0, int l = 0, int r = N)
{
    if (r - l == 1) {
        t[o] = seg(A[l]);
        return;
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    bld(o + 1, l, m);
    bld(z, m, r);
    pull(o, z);
}
void chg(int i, int v, int o = 0, int l = 0, int r = N)
{
    if (r - l == 1) {
        t[o] = seg(A[l] = v);
        return;
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    push(o, z);
    if (i < m)
        chg(i, v, o + 1, l, m);
    else
        chg(i, v, z, m, r);
    pull(o, z);
}
void upd(int i, int j, int o = 0, int l = 0, int r = N)
{
    if (j <= l || r <= i)
        return;
    if (i <= l && r <= j) {
        t[o].apply(1);
        return;
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    push(o, z);
    upd(i, j, o + 1, l, m);
    upd(i, j, z, m, r);
    pull(o, z);
}
int qry(int i, int j, int o = 0, int l = 0, int r = N)
{
    if (j <= l || r <= i)
        return 0;
    if (i <= l && r <= j) {
        if (t[o].ans != -1)
            return t[o].ans;
        if (t[o].mn >= vp.size() - 1)
            return t[o].ans = (f[vp.size() - 1][0] * 1ll * t[o].c0 + f[vp.size() - 1][1] * 1ll * (r - l - t[o].c0)) % P;
        int tdd = t[o].mn;
        if (r - l == 1)
            return t[o].ans = f[tdd][A[l] % vp[tdd] + (A[l] >= vp[tdd] ? vp[tdd] : 0)];
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    push(o, z);
    int ret = qry(i, j, o + 1, l, m);
    ret = (ret + qry(i, j, z, m, r)) % P;
    pull(o, z);
    return ret;
}
int phi(int x)
{
    int y = x;
    for (int i = 2; i * i <= y; ++i)
        if (y % i == 0) {
            while (y % i == 0)
                y /= i;
            x = x - x / i;
        }
    if (y > 1)
        x = x - x / y;
    return x;
}
int max_vp_size()
{
    int mx = 0;
    for (int i = 1; i <= 1000; ++i)  {
        vp = {i};
        while (vp.back() != 1)
            vp.push_back(phi(vp.back()));
        mx = max((int)vp.size(), mx);
    }
    return mx;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q >> C >> P;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    if (P == 1) {
        while (Q--) {
            int a, b, c;
            cin >> a >> b >> c;
            if (a == 2)
                cout << "0\n";
        }
        return 0;
    }
    vp = {P};
    while (vp.back() != 1)
        vp.push_back(phi(vp.back()));
    f[0].resize(P * 2);
    iota(begin(f[0]), end(f[0]), 0);
    for (int & i : f[0])
        i %= P;
    for (int i = 1; i < vp.size(); ++i) {
        f[i].resize(vp[i] * 2);
        ll x = 1;
        bool ot = 0;
        for (int j = 0; j < f[i].size(); ++j) {
            f[i][j] = f[i - 1][x + ot * vp[i - 1]];
            x = x * C;
            if (x >= vp[i - 1]) {
                ot = 1;
                x %= vp[i - 1];
            }
        }
    }
    /*
    for (int i = 0; i < vp.size(); ++i)
        for (int j = 0; j < f[i].size(); ++j)
            fprintf(stderr, "f(%d,%d) = %d\n", i, j, f[i][j]);
            */
    bld();
    while (Q--) {
        int ot, l, r;
        cin >> ot >> l >> r;
        --l;
        if (ot == 1)
            upd(l, r);
        else if (ot == 2)
            cout << qry(l, r) << '\n';
        else
            chg(l, r);
        /*
        cout << flush;
        for (int i = 0; i < N; ++i)
            fprintf(stderr, "A[%d] = %d\n", i, qry(i, i+1));
        fputs("=========\n\n", stderr);
        */
    }
}
