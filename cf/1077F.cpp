#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5056,inf = 1e18;
int n,k,x,a[N],dp[N],tmp[N],l,r;
pair<int,int> dk[N];
int32_t main()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)   
        dp[i] = 0;
    for (int i = k; i <= n; ++i)
        dp[i] = -inf;
    for (int j = 1; j <= x; ++j) {
        for (int i = 1; i <= n; ++i)
            tmp[i] = dp[i-1]+a[i];
        l = r = 0;
        for (int i = 0; i <= n; ++i) {
            if (i) {
                while (r > l && dk[r-1].second <= tmp[i])
                    --r;
                dk[r++] = {i,tmp[i]};
            }
            while (l < r && dk[l].first < i - k + 1)
                ++l;
            if (j < i/k || j > i) {
                dp[i] = -inf;
                continue;
            }
            assert(l < r);
            dp[i] = dk[l].second;
        }
    }
    cout << (dp[n] < 0 ? -1 : dp[n]) << endl;
}
