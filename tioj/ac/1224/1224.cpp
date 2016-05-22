#include <cstdio>
#include <algorithm>
#define LC(o) ((o) * 2 + 1)
#define RC(o) ((o) * 2 + 2)
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 42;
const int maxr = 1e6;

struct line {
    int x, d, u, s;
    bool operator < (const line& l) const {
        return x < l.x;
    }
};

struct node {
    int tag; // how many lines covers exactly the segment
    int x; // the sum of node's offspring's covered length
};

line a[2 * maxn];
node t[4 * maxr];

inline int query(int o, int l, int r) {
    return t[o].tag ? r - l + 1 : t[o].x;
}

void modify(int o, int l, int r, int i, int j, int v) {
    if (l > j || r < i)
        return;
    if (i <= l && r <= j) {
        t[o].tag += v;
        return;
    }
    int m = (l + r) / 2;
    modify(LC(o), l, m, i, j, v);
    modify(RC(o), m + 1, r, i, j, v);
    t[o].x = query(LC(o), l, m) + query(RC(o), m + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r, d, u;
        scanf("%d%d%d%d", &l, &r, &d, &u);
        a[2*i] = {l, d, u, 1};
        a[2*i+1] = {r, d, u, -1};
    }
    sort(a, a + 2 * n);
    ll x = a[0].x;
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        ans += (a[i].x - x) * query(0, 0, maxr-1);
        modify(0, 0, maxr-1, a[i].d, a[i].u-1, a[i].s);
        x = a[i].x;
    }
    printf("%lld\n", ans);
    return 0;
}
