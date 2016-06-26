#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1.06e6;
pii p[2];
pii dist[maxn];
int sqr(int x) {return x * x;}
int dis(const pii & a, const pii & b) {return sqr(a.first - b.first) + sqr(a.second - b.second);}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 2; ++i)
        cin >> p[i].first >> p[i].second;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pii c;
        cin >> c.first >> c.second;
        dist[i] = {dis(c, p[0]), dis(c, p[1])};
    }
    sort(dist, dist + n);
    int max1 = 0, ans = numeric_limits<int>::max();
    for (int i = n - 1; i >= 0; --i) {
        ans = min(ans, dist[i].first + max1);
        max1 = max(max1, dist[i].second);
    }
    ans = min(ans, max1);
    cout << ans << '\n';
}
