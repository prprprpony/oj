#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int & x : a)
        scanf("%d", &x);
    vector<int> c(n);
    vector<pair<int, int>> st(n + 1);
    st[0] = {1e9 + 7, 0};
    int r = 1;
    for (int i = 0; i < n; ++i) {
        int lt = 0;
        while (st[r - 1].first < a[i])
            lt += st[--r].second;
        int w = 1;
        if (st[r - 1].first == a[i]) {
            lt += st[--r].second;
            w += st[r].second;
        }
        lt += st[r - 1].second ? 1 : 0;
        c[i] += lt;
        st[r++] = {a[i], w};
    }
    r = 1;
    for (int i = n - 1; i >= 0; --i) {
        int lt = 0;
        while (st[r - 1].first < a[i])
            lt += st[--r].second;
        int w = 1;
        if (st[r - 1].first == a[i]) {
            lt += st[--r].second;
            w += st[r].second;
        }
        lt += st[r - 1].second ? 1 : 0;
        c[i] += lt;
        st[r++] = {a[i], w};
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        //cerr<< c[i] << endl;
        ans += c[i];
    }
    cout << ans << endl;
}
