#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define MAXN 150000 + 426
using namespace std;
typedef pair<int, int> pii;
int t[MAXN];
bool on[MAXN];

int main()
{
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", t + i);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    while (q--) {
        int type, id;
        scanf("%d%d", &type, &id);
        if (type == 1) {
            if (pq.size() < k) {
                on[id] = true;
                pq.push({t[id], id});
            } else if (pq.top().first < t[id]) {
                on[pq.top().second] = false;
                pq.pop();
                on[id] = true;
                pq.push({t[id], id});
            }
        } else {
            puts(on[id] ? "YES" : "NO");
        }
    }
    return 0;
}
