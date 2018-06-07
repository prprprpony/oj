#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
int s[N],dp[N];
pii st[N];
int pr[N],po[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sep;
    for (int i = 1; i <= n; ++i) {
        char a,l;
        cin >> a >> l;
        if (a == 'A')
            s[i] = 1;
        else 
            s[i] = -1;
        s[i] += s[i-1];
        if (l == 'L')
            sep.push_back(i);
    }
    sep.push_back(n+1);
    for (int i = sep[0]; i < sep[1]; ++i)
        dp[i] = s[i] >= 0;
    for (int i = 1; i + 1 < sep.size(); ++i) {
        int w = sep[i] - sep[i-1];
        for (int j = sep[i-1]; j < sep[i]; ++j)
            st[j - sep[i-1] + 1] = {s[j],dp[j]};
        sort(st+1,st+1+w);
        pr[0]=pr[w+1]=po[0]=po[w+1]=0;
        for (int j = 1; j <= w; ++j)
            pr[j] = max(st[j].S,pr[j-1]);
        for (int j = w; j >= 1; --j)
            po[j] = max(st[j].S,po[j+1]);
        for (int j = sep[i]; j < sep[i+1]; ++j) {
            int k = upper_bound(st+1,st+1+w,pii(s[j],1e9)) - st;
            if (k <= w)
                dp[j] = po[k];
            if (k-1 >= 1)
                dp[j] = max(dp[j],1+pr[k-1]);
        }
    }
    cout << dp[n] << endl;
}
