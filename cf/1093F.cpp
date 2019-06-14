#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+87,K=105,M=998244353;
int n,k,l;
struct {
    deque<int> dk;
    int sum;
    void clear()
    {
        dk.clear();
        sum = 0;
    }
    void upd(int x)
    {
        sum = (sum + x) % M;
        dk.push_front(x);
        if (dk.size() >= l) {
            sum = (sum + M - dk.back()) % M;
            dk.pop_back();
        }
    }
} dp[K];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> l;
    ll tot = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < k; ++j)
            if (j + 1 == x || x == -1)
                dp[j].upd((tot - dp[j].sum) % M);
            else
                dp[j].clear();
        tot = 0;
        for (int j = 0; j < k; ++j)
            tot += dp[j].sum;
    }
    cout << tot % M << endl;
}
