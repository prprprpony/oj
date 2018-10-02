#include<bits/stdc++.h>
using namespace std;
const int N = 1006;
char x[N];
int nxt[N][26],dp[1<<20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k >> (x+1);
        int n = strlen(x+1);
        fill_n(nxt[n],26,n+1);
        for (int i = n-1; i >= 0; --i) {
            copy_n(nxt[i+1],26,nxt[i]);
            nxt[i][x[i+1]-'a'] = i+1;
        }
        bool ok = true;
        for (int s = 1; s < (1<<k) && ok; ++s) {
            int & d = dp[s];
            d = 0;
            for (int i = 0; i < k; ++i)
                if (s & (1 << i)) 
                    d = max(d, nxt[dp[s^(1<<i)]][i]);
            if (d > n)
                ok = false;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}
