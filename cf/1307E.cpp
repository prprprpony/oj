#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5050;
const int MOD = 1e9 + 7;
vector<int> p[N], c[N];
int f[N], h[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        p[s].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> f[i] >> h[i];
        if (p[f[i]].size() < h[i]) {
            --i;
            --m;
            continue;
        }
        c[f[i]].push_back(h[i]);
    }
    ll ans = 0, sz = 0;
    for (int i = -1; i < m; ++i) {
        int x;
        ll wa, le;
        if (i >= 0) {
            c[f[i]].erase(find(begin(c[f[i]]), end(c[f[i]]), h[i]));
            x = p[f[i]][h[i] - 1]; // largest in left
            wa = le = 1;
        } else {
            x = -1;
            wa = 1;
            le = 0;
        }
        for (int j = 1; j <= n; ++j) {
            ll lo = 0, ro = 0, lr = 0;
            for (int w : c[j]) {
                int y = p[j][w - 1];
                bool lok = y < x;
                y = p[j][p[j].size() - w];
                bool rok = y > x;
                if (lok && rok)
                    ++lr;
                else if (lok)
                    ++lo;
                else if (rok)
                    ++ro;
            }
            if (i >= 0 && j == f[i]) {
                if (ro + lr) {
                    wa = wa * (ro + lr) % MOD;
                    ++le;
                }
                continue;
            }
            if (lo + ro + lr == 0)
                continue;
            if (lo && ro == 0 && lr == 0) {
                ++le;
                wa = wa * lo % MOD;
            } else if (ro && lo == 0 && lr == 0) {
                ++le;
                wa = wa * ro % MOD;
            } else if (lr == 1 && lo == 0 && ro == 0) {
                ++le;
                wa = wa * 2 % MOD;
            } else {
                le += 2;
                ll tmp = ((lo + lr) * (ro + lr) - lr) % MOD;
                wa = wa * tmp % MOD; 
            }
        }
        if (i >= 0)
            c[f[i]].push_back(h[i]);
        if (le > sz) {
            ans = wa;
            sz = le;
        } else if (le == sz) {
            (ans += wa) %= MOD;
        }
    }
    cout << sz << ' ' << ans << endl;
}
