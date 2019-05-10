#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[20],c[20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n);
    int x = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] && (i == 0 || a[i] != a[i-1])) {
            int t = a[i];
            for (int j = 19; j >= 0; --j)
                if (t >> j & 1)
                    t ^= b[j];
            if (t) {
                int k = __lg(t);
                b[k] = t;
                c[k] = a[i];
                bool ok = true;
                for (int j = __lg(a[i]); j >= 0 && ok; --j)
                    ok &= b[j] > 0;
                if (ok)
                    x = __lg(a[i])+1;
            }
        }
    cout << x << '\n';
    vector<int> ans{0}, t;
    for (int i = 0; i < x; ++i) {
        t.clear();
        int l = 0, r = c[i];
        for (int v : ans) {
            t.push_back(v ^ l);
            t.push_back(v ^ r);
            swap(l,r);
        }
        swap(ans, t);
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i+1==ans.size()];
}
