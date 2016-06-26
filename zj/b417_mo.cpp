/*
    Mo's algorithm
    O((N + Q) * sqrt(N))
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#define MAXN 100001
#define MAXQ 1000000
using namespace std;
typedef pair<int, int> pii;

int a[MAXN];
int cnt[MAXN];
int num[MAXN];
int mx;

struct Query
{
    int i, block, l, r;
    bool operator < (const Query& b) const {
        return block < b.block || (block == b.block && r < b.r);
    }

} q[MAXQ];

pii ans[MAXQ];

void insert(int v) {
    num[cnt[v]]--;
    cnt[v]++;
    num[cnt[v]]++;
    mx = max(mx, cnt[v]);
}

void erase(int v) {
    if (cnt[v] == mx && num[cnt[v]] == 1)
        mx--;
    num[cnt[v]]--;
    cnt[v]--;
    num[cnt[v]]++;
}

void expandl(int& l, int e) {
    while (l > e)
        insert(a[--l]);
}

void expandr(int& r, int e) {
    while (r < e)
        insert(a[++r]);
}

void shrinkl(int& l, int e) {
    while (l < e)
        erase(a[l++]);
}

void shrinkr(int& r, int e) {
    while (r > e)
        erase(a[r--]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int size = sqrt(n) + 1;
    for (int i = 0; i < m; i++) {
        q[i].i = i;
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].block = q[i].l / size;
    }

    sort(q, q + m);

    int l = q[0].l, r = q[0].l - 1;
    for (int i = 0; i < m; i++) {
        expandr(r, q[i].r);
        expandl(l, q[i].l);
        shrinkr(r, q[i].r);
        shrinkl(l, q[i].l);
        ans[q[i].i] = {mx, num[mx]};
    }

    for (int i = 0; i < m; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
