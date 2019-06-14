#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int S = sqrt(1e9+88);
pii v[2*S];
ll a,b,p,q;
pii g(ll x)
{
    return {abs(x * p % q * 2 - q),x};
}
pii h(ll x)
{
    return {x * p % q,x};
}
int solve()
{
    cin >> a >> b >> p >> q;
    int _ = __gcd(p,q);
    p /= _, q /= _;
    p %= q;
    pii ans(INT_MAX,INT_MAX);
    if (q == 1)
        return a;
    if ((b - a + 1) >= S) {
        for (int i = 0; i < S; ++i)
            v[i] = h(a + i);
        sort(v,v+S);
        int m = 1;
        for (int i = 1; i < S; ++i)
            if (v[i].F != v[i-1].F)
                v[m++] = v[i];
        copy_n(v,m-1,v+m);
        int i;
        for (i = 0; a + i + S - 1 <= b; i += S) {
            int d = i * p % q;
            int e = (q - d) % q;
            int s = lower_bound(v,v+m,pii(e,INT_MIN)) - v;
            int j = lower_bound(v+s,v+s+m,pii(((q+1)/2+e)%q,INT_MIN),[&](pii x,pii y){return (x.F+d)%q < (y.F+d)%q;}) - v;
            if (j < s+m)
                ans = min(ans,g(v[j].S+i));
            if (j-1 >= s)
                ans = min(ans,g(v[j-1].S+i));
        }
        a += i - S;
    }
    for (;a<=b;)
        ans=min(ans,g(a++));
    return ans.S;
}
int main()
{
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
