#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> v(n);
    for (auto & p : v)
        scanf("%d%d", &p.first, &p.second);
    v.emplace_back(m, 0);
    sort(v.begin(), v.end());
    vector<ll> a, b;
    int i = v[0].first, j = 0;
    while (i <= m) {
        while (j < v.size() && v[j].first == i)
            a.push_back(v[j++].second);
        sort(a.begin(), a.end());
        if (i == m)
            break;
        int w = a.size();
        b.clear();
        for (; w >= 2; w -= 2)
            b.push_back(a[w - 1] + a[w - 2]);
        i = b.size() ? i + 1 : v[j].first;
        if (w)
            b.push_back(a[0]);
        swap(a, b);
    }
    printf("%lld\n", a.back());
}
