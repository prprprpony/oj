#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 87;
int n,a[N],p[N];
ll dp[N];
vector<int> v[2];
bool gao(int x1,int x2)
{
    for (int i = n - 1; i >= 0; --i) {
        int k = (x1 - 1) / a[p[i]] + 1;
        if (k <= n - i && dp[i + k] >= x2) {
            for (int j = i; j < n; ++j)
                v[j >= i + k].push_back(p[j]);
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1,x2;
    cin >> n >> x1 >> x2;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    iota(p,p+n,0);
    sort(p,p+n,[](int i,int j)->bool{return a[i] < a[j];});
    for (int i = n - 1; i >= 0; --i)
        dp[i] = max(dp[i+1], a[p[i]] * 1LL * (n - i));
    bool ok = gao(x1,x2);
    if (!ok) {
        ok = gao(x2,x1);
        v[0].swap(v[1]);
    }
    if (!ok) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n" << v[0].size() << ' ' << v[1].size() << '\n';
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] + 1 << " \n"[j + 1 == v[i].size()];
}
