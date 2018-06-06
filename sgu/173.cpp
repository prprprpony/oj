/*

(L[1][0,k-2],L[1][k-1]^L[0][0] = pop_count(L[1][0,k-2] & A) % 2)


(a,b) (c,d) is valid -> (a^b,c^d) is valid
Gaussian elimination ?

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getv(ll x,ll s,ll k)
{
    return (x >> s) & ((1LL<<k)-1);
}
ll setv(ll x,ll s,ll k,ll y)
{
    return ((x>>(s+k))<<(s+k)) | (y << s) | (x & ((1LL<<s)-1));
}
ll trans(ll x,ll A,ll k)
{
    int y = __builtin_popcountll(A&x) & 1;
    if (x & (1LL<<(k-1))) {
        x ^= (1LL<<(k-1));
        y ^= 1;
    }
    return x<<1|y;
}
    int n,m,k,l;
void print(ll r,string s = "")
{
    for (int i = 0; i < n; ++i)
        cout << char('0'+((r>>i)&1));
    cout << endl;
}
int main()
{
    int s[10],d[10];
    ll gau[205];
    cin >> n >> m >> k >> l;
    assert(l >= k - 1);
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> d[i];
        --s[i];
    }
    for (int i = 0; i < l; ++i) {
        string L0,L1;
        cin >> L0 >> L1;
        ll x = (L1[k-1]-'0') ^ (L0[0] - '0');
        for (int j = 1; j < k; ++j)
            x |= ll(L1[j-1]-'0') << j;
        gau[i] = x;
    }
    for (int i = 0; i < k-1; ++i) {
        nth_element(gau+i,gau+i,gau+l,greater<ll>());
        assert(gau[i] > 0);
        int h = __lg(gau[i]);
        assert(h + i == k - 1);
        for (int j = 0; j < l; ++j)
            if (j != i && (gau[j] & (1LL << h)))
                gau[j] ^= gau[i];
    }
    ll A = 0;
    for (int i = 0; i < k-1; ++i)
        A = (A<<1) | (gau[i]&1);
    ll r = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        r |= (c-'0'+0LL)<<i;
    }
    for (int i = m-1; i >= 0; --i) {
        ll v = getv(r,s[i],k);
        while (d[i]--)
            v = trans(v,A,k);
        r = setv(r,s[i],k,v);
    }
    print(r);
}
