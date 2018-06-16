#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
pair<int,int> a[N];
long long ans[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+1+n);
    int mi = N;
    for (int i = n; i >= 1; --i) {
        mi = min(a[i].second,mi);
        ans[mi] += (a[i].first - a[i-1].first) * (n-i+1LL);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
}
