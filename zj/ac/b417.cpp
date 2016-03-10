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
    int i, l, r;
} q[MAXQ];

pii ans[MAXQ];

struct cmpl
{
    bool operator () (const Query& a, const Query& b)
    {
        return a.l < b.l;
    }
};

struct cmpr
{
    bool operator () (const Query& a, const Query& b)
    {
        return a.r < b.r;
    }
};

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
    for (int i = 0; i < m; i++) {
        q[i].i = i;
        scanf("%d%d", &q[i].l, &q[i].r);
    }

    sort(q, q + m, cmpl());
    int size = sqrt(m);
    for (int i = 0; i < m; i += size)
        sort(q + i, q + min(i + size, m), cmpr());

    int l = q[0].l, r = q[0].l - 1;
    for (int i = 0; i < m; i += size) {
        expandr(r, q[i].r);
        shrinkr(r, q[i].r);
        shrinkl(l, q[i].l);
        for (int j = i; j < i + size && j < m; j++) {
            expandr(r, q[j].r);
            expandl(l, q[j].l);
            shrinkl(l, q[j].l);
            ans[q[j].i] = {mx, num[mx]};
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
