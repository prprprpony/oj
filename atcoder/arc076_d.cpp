#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
struct seg
{
    int ps;
    int mx;
} t[N * 4];
int n;
vector<int> vl[N];
void add(int i, int v, int o = 1, int l = 0, int r = n + 2)
{
    if (r - l == 1) {
        t[o].ps += v;
        t[o].mx = max(0, t[o].ps);
        return;
    }
    int m = l + (r - l) / 2;
    if (i < m)
        add(i, v, o * 2, l, m);
    else
        add(i, v, o * 2 + 1, m, r);
    t[o].ps = t[o * 2].ps + t[o * 2 + 1].ps;
    t[o].mx = max(t[o * 2].mx, t[o * 2 + 1].mx + t[o * 2].ps);
}
int main()
{
    int m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        vl[r].push_back(l);
    }
    for (int i = 1; i <= n; ++i)
        add(i, -1);
    int ans = 0, rs = 0;
    for (int r = n + 1; r >= 1; --r) {
        if (r <= n) {
            add(r, 1);
            --rs;
        }
        for (int l : vl[r])
            add(l, 1);
        ans = max(ans, t[1].mx + rs);
    }
    printf("%d\n", ans);
}

