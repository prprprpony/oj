#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
array<int,3> a[N];
int t[2][N],ans[N],f[N];
int *p = t[0];
void add(int x,int v)
{
    for (int i = x; i < N; i += i & -i)
        f[i] += v;
}
int qry(int i)
{
    int r = 0;
    for (; i; i ^= i & -i)
        r += f[i];
    return r;
}
void cdq(int l,int r,int d = 0) // xi <= xj, yi < yj, zi < zj
{
    if (r - l == 1) {
        t[d][l] = p[l];
        return;
    }
    int m = l + r >> 1;
    cdq(l,m,d^1);
    cdq(m,r,d^1);
    int * lt = t[d^1] + l, * rt = t[d^1] + m, * ot = t[d] + l;
    int ln = m - l, rn = r - m, on = r - l;
    while (ln || rn) {
        if (ln && (!rn || a[lt[ln-1]][1] >= a[rt[rn-1]][1])) {
            --ln;
            ans[lt[ln]] += r - m - rn - qry(a[lt[ln]][2]);
            ot[--on] = lt[ln];
        } else {
            --rn;
            add(a[rt[rn]][2],1);
            ot[--on] = rt[rn];
        }
    }
    for (int i = 0; i < r - m; ++i)
        add(a[rt[i]][2],-1);
}
void cal(int l,int r) // xi = xj, yi < yj, zi < zj
{
    for (int i,j=r-1; j >= l; j = i) {
        for (i = j; i >= l && a[p[i]][1] == a[p[j]][1]; --i)
            ans[p[i]] -= r - j - 1 - qry(a[p[i]][2]);
        for (int k = i+1; k <= j; ++k)
            add(a[p[k]][2],1);
    }
    for (int i = l; i < r; ++i)
            add(a[p[i]][2],-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    iota(p,p+n,0);
    sort(p,p+n,[&](int i,int j)->bool{return a[i] < a[j];});
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[p[i]][0] == a[p[j]][0]; ++j);
        cal(i,j);
    }
    cdq(0,n);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << '\n';
}
