#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(a) ((int)(a).size())
const int N = 2e5, M = 1e9 + 87;
vector<int> v[5],q[5];
int n,k,b,c;
ll f(ll x,ll y,ll t)
{
    return (x-t-1)/5 * (-b) + (y-x)%5*c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> b >> c;
    b = min(b, c * 5);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a += M;
        v[a%5].push_back(a);
        for (int j = 0; j < 5; ++j)
            q[(a+j)%5].push_back(a+j);
    }
    for (int i = 0; i < 5; ++i) {
        sort(begin(v[i]),end(v[i]));
        sort(begin(q[i]),end(q[i]));
        q[i].erase(unique(begin(q[i]),end(q[i])),end(q[i]));
    }
    ll ans = LLONG_MAX;
    for (int t = 0; t < 5; ++t) {
        int l[5] = {}, r[5] = {}, tot = 0;
        ll su = 0;
        for (int a : q[t]) {
            for (int i = 0; i < 5; ++i)
                while (r[i] < SZ(v[i]) && v[i][r[i]] <= a)
                    ++tot, su += f(v[i][r[i]], a, t), ++r[i];
            while (tot > k) {
                ll co = LLONG_MIN;
                int j = 0;
                for (int i = 0; i < 5; ++i)
                    if (l[i] < r[i] && f(v[i][l[i]], a, t) > co) {
                        co = f(v[i][l[i]], a, t);
                        j = i;
                    }
                ++l[j];
                --tot;
                su -= co;
            }
            if (tot == k)
                ans = min(ans, (a-t-1LL) / 5 * b * k + su);
        }
    }
    cout << ans << '\n';
}
