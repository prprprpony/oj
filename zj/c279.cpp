#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 5;
int dp[N];
vector<int> p;
int sev[N];
int main()
{
    for (int i = 2; i < N; ++i) {
        if (!sev[i])
            p.push_back(sev[i] = i);
        for (int j : p) {
            if (i * 1LL * j >= N)
                break;
            sev[i * j] = j;
            if (j == sev[i])
                break;
        }
    }
    for (int i = 0, s = 0; i < p.size(); ++i) {
        s = min(s + p[i], N - 1);
        for (int j = s; j >= p[i]; --j)
            if (j - p[i] == 0 || dp[j-p[i]])
                dp[j] = max(dp[j], 1 + dp[j - p[i]]);
    }
    int n;
    cin >> n;
    cout << (dp[n] ? dp[n] : -1) << endl;
}
