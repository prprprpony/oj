#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 426;
typedef priority_queue<int> heap;

heap h[maxn];
int p[maxn];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int merge(int a, int b) {
    if (h[a].size() < h[b].size())
        swap(a, b);
    p[b] = a;
    while (h[b].size()) {
        h[a].push(h[b].top());
        h[b].pop();
    }
    return a;
}

int main(void)
{
    int n, m;
    int x, y;
    int ans;
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            h[i] = heap();
            int s;
            scanf("%d", &s);
            h[i].push(s);
            p[i] = i;
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &x, &y);
            x = find(x);
            y = find(y);
            if (x == y)
                ans = -1;
            else {
                int s = h[x].top();
                h[x].pop();
                h[x].push(s >> 1);
                s = h[y].top();
                h[y].pop();
                h[y].push(s >> 1);
                
                x = merge(x, y);
                ans = h[x].top();
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
