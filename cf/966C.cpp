#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87, K = 60;
vector<ll> b[K];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        b[__lg(x)].push_back(x);
    }
    vector<ll> a0,a;
    for (int i = K-1; i >= 0; --i) {
        if (b[i].empty())
            continue;
        swap(a0,a);
        a.clear();
        a.push_back(b[i].back());
        b[i].pop_back(); 
        for (ll x : a0) {
            a.push_back(x);
            if ((x>>i&1) && b[i].size()) {
                a.push_back(b[i].back());
                b[i].pop_back(); 
            }
        }
        if (b[i].size()) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i==n-1];
}
