#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5 + 87, inf = 2e9 + 87;
int n, A, B, a[N], mx[N], d[N], s[N];
int main()
{
    scanf("%d%d%d", &n, &A, &B);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (i > 1) {
            s[i] = (a[i] == a[i - 1] ? A : B) + s[i - 1];
        }
    }
    d[1] = 0;
    vector<pair<int, int>> vp;
    fill_n(mx, N, -inf);
    for (int i = 2; i <= n; ++i) {
        d[i] = d[1] - s[1] + s[i - 1] + 0;
        for (auto p : vp)
            if (p.second != a[i])
                d[i] = max(d[i], p.first + s[i - 1] + B);
        d[i] = max(d[i], mx[a[i]] + s[i - 1] + A);
        mx[a[i - 1]] = max(mx[a[i - 1]], d[i] - s[i]);
        vp.emplace_back(d[i] - s[i], a[i - 1]);
        sort(vp.rbegin(), vp.rend());
        for (int i = 0; i < vp.size(); ++i)
            for (int j = vp.size() - 1; j > i; --j)
                if (vp[j].second == vp[i].second)
                    vp.erase(begin(vp) + j);
        if (vp.size() > 2)
            vp.resize(2);
    }
    int ans = max(s[n], d[n]);
    for (int i = 1; i < n; ++i)
        ans = max(ans, d[i] + s[n] - s[i]);
    printf("%d\n", ans);
}
