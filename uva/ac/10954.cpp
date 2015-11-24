#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll i;
    ll ans;
    while (scanf("%d", &n) == 1 && n > 0) {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        ans = 0;
        while (n--) {
            scanf("%lld", &i);
            pq.push(i);
        }
        while (pq.size() != 1) {
            i = pq.top();
            pq.pop();
            i += pq.top();
            pq.pop();
            ans += i;
            pq.push(i);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
