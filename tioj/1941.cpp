#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> dp;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s,t;
        cin >> s >> t;
        dp.insert(s);
        auto it = dp.upper_bound(t);
        if (it != end(dp))
            dp.erase(it);
    }
    cout << dp.size() << endl;
}
