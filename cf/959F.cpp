#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87, M = 1e9 + 7, C = 1<<20;
int a[N],ans[N];
vector<pii> qq[N];
bool b[C];
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i) {
        int l,x;
        cin >> l >> x;
        qq[l].emplace_back(i,x);
    }
    int w = 1;
    b[0] = true;
    v = {0};
    for (int i = 1; i <= n; ++i) {
        if (b[a[i]]) {
            w = w * 2 % M;
        } else {
            int m=v.size();
            for (int j = 0; j < m; ++j) {
                v.push_back(v[j] ^ a[i]);
                b[v.back()] = true;
            }
        }
        for (const auto & p : qq[i])
            ans[p.F] = b[p.S] * w;
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
