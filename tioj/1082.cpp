#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+87;
int b[N],w[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while ((cin>>n)&&n) {
        int ans = 0;
        int cnt[3] = {0,0,0};
        for(int i=0;i<n;++i) {
            cin>>b[i]>>w[i];
            ans += min(b[i], w[i]);
            ++cnt[b[i] != w[i] ? b[i] < w[i] : 2];
        }
        if(n==1) {
            cout<<(b[0]&&w[0] ? "-1\n" : "0\n");
            continue;
        }
        if (!((cnt[0] && cnt[1]) || (cnt[0] && cnt[2]) || (cnt[1] && cnt[2]) || cnt[2] >= 2)) {
            if (cnt[0]) {
                int v = b[0]-w[0];
                for (int i=0;i<n;++i)
                    v=min(v,b[i]-w[i]);
                ans += v;
            } else {
                int v = w[0]-b[0];
                for (int i=0;i<n;++i)
                    v=min(v,w[i]-b[i]);
                ans += v;
            }
        }
        cout << ans << '\n';
    }
}
