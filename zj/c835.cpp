#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 22;
vector<ll> v[M];
int main()
{
    int n, m;
    ll s = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        s += b;
        v[a].push_back(b);
    }
    for (int i = 0; i < m; ++i) {
        sort(v[i].begin(), v[i].end());
        int w = v[i].size();
        for (; w >= 2; w -= 2)
            v[i + 1].push_back(v[i][w - 1] + v[i][w - 2]);
        v[i].resize(w);
    }
    if (v[m].empty()) {
        printf("%lld\n", s);
        return 0;
    }
    sort(v[m].begin(), v[m].end());
    printf("%lld\n", v[m].back());
}
