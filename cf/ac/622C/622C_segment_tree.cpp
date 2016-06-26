#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#define MAXN ((int)1e6 + 42)
#define LC(o) (2 * (o) + 1)
#define RC(o) (2 * (o) + 2)
using namespace std;
int a[MAXN];
vector<int> node[4 * MAXN];

void build(int o, int l, int r)
{
    if (l != r) {
        int m = (l + r) / 2;
        build(LC(o), l, m);
        build(RC(o), m + 1, r);
        set_union(node[LC(o)].begin(), node[LC(o)].end(),
                  node[RC(o)].begin(), node[RC(o)].end(),
                  back_inserter(node[o]));
    } else {
        node[o].push_back(a[l-1]);
    }
}

int find_not_equal(int o, int l, int r, int v) // precondition: an element that's not equal to v exists in [l, r] of the first call
{
    if (binary_search(node[o].begin(), node[o].end(), v)) {
        if (node[o].size() > 1) {
            int m = (l + r) / 2;
            int ret;
            if ((ret = find_not_equal(LC(o), l, m, v)) == -1)
                ret = find_not_equal(RC(o), m + 1, r, v);
            return ret;
        } else {
            return -1;
        }
    } else {
        return l;
    }
}

int query(int o, int l, int r, int i, int j, int v)
{
    if (l > j || r < i)
        return -1;
    if (i <= l && r <= j) {
        if (!binary_search(node[o].begin(), node[o].end(), v))
            return l;
        if (node[o].size() > 1)
            return find_not_equal(o, l, r, v);
        return -1;
    }
    int m = (l + r) / 2;
    int ret;
    if ((ret = query(LC(o), l, m, i, j, v)) == -1)
        ret = query(RC(o), m + 1, r, i, j, v);
    return ret;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    build(0, 1, n);
    while (m--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        printf("%d\n", query(0, 1, n, l, r, x));
    }
    return 0;
}
