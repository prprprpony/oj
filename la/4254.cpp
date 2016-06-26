#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct PG
{
    int r;
    int d;
    int w;
    bool operator < (const PG& a) const // for sort
    {
        return r < a.r;
    }
    bool operator > (const PG& a) const // for priority queue
    {
        return d > a.d || (d == a.d && w > a.w);
    }
};

PG p[10000 + 228];
int n;
int last;

bool ok(int s)
{
    priority_queue<PG, vector<PG>, greater<PG> > pq;

    for (int t = p[0].r, i = 0; t <= last + 1 && !(pq.empty() && i == n); pq.size() || i == n ? ++t : t = p[i].r) {
        if (pq.size() && pq.top().d < t)
            return false;
        int work = s;
        while (pq.size() && work > 0) {
            PG x = pq.top();
            pq.pop();
            if ((work -= x.w) < 0) {
                x.w = -work;
                pq.push(x);
            }
        }
        while (i < n && p[i].r == t)
            pq.push(p[i++]);
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int low = 1, high = 0;
        last = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &p[i].r, &p[i].d, &p[i].w);
            high += p[i].w;
            last = max(last, p[i].d);
        }
        sort(p, p + n);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ok(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        printf("%d\n", low);
    }
    return 0;
}
/*
Total Time complexity = O(T * (n + lg(sigma w) * max(d) * lg(n)))
                          20   1e4 lg(1e7)         2e4    lg(1e4)
                                    23                      13
*/
