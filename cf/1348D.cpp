#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<int> a = {1};
    int as = 1;
    while (as < n) {
        int p = a.back();
        if (p <= n - as && n - as <= 2 * p) {
            a.push_back(n - as);
            as = n;
        } else {
            a.push_back(p * 2);
            as += a.back();
        }
    }
    if (as != n) {
        as -= a.back();
        a.pop_back();
        as -= a.back();
        a.pop_back();
        int w = n - as;
        a.push_back(w / 2);
        a.push_back((w + 1) / 2);
    }
    cout << a.size() - 1 << '\n';
    for (int i = 1; i < a.size(); ++i)
        cout << a[i] - a[i - 1] << " \n"[i + 1 == a.size()];
    assert(accumulate(a.begin(), a.end(), 0ll) == n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
