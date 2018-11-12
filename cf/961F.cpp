#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+87, M=1010101333,P=52127;
typedef long long ll;
int n;
char s[N];
ll h[N],p[N];
int ans[N];
int hs(int i,int j)
{
    --i;
    return ((h[j] - h[i] * p[j-i])%M+M)%M;
}
bool ok(int i,int w)
{
    int j = n+1-i;
    if (i-w < 1 || j + w > n)
        return false;
    return hs(i-w,i+w) == hs(j-w,j+w);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> (s+1);
    p[0]=1;
    for (int i = 1; i <= n; ++i) {
        h[i] = (h[i-1] * P + s[i])%M;
        p[i] = p[i-1] * P % M;
    }
    for (int i = 1; i <= n/2; ++i) {
        int l=0,r=n;
        if (s[i] != s[n+1-i])
            continue;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ok(i,m))
                l = m + 1;
            else
                r = m - 1;
        }
        ans[i-r] = max(ans[i-r],r*2+1);
    }
    for (int i = 1; i <= (n+1)/2; ++i) {
        ans[i] = max(ans[i], ans[i-1]-2);
        cout << (ans[i] ? ans[i] : -1) << " \n"[i==(n+1)/2];
    }
}
