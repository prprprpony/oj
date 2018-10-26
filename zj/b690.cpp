/*
(sr - sl) / (r - l) = P / Q
Qsr - Qsl = Pr - Pl
Qsr - Pr = Qsl - PL
*/
#include<bits/stdc++.h>
using namespace std;
int n;
long long p,q,s=0,ans=0,v[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> q;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        s += a;
        v[i] = (q * s - p * i);
    }
    sort(v,v+n+1);
    for (int i = 1, c = 1; i < n + 1; ++i) {
        if (v[i] == v[i-1])
            ans += c++;
        else
            c = 1;
    }
    cout << ans << endl;
}
