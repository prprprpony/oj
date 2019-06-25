#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P = 998244353;
const ll PHI = P - 1;
const ll G = 3;
ll qpow(ll a,ll b,ll n)
{
    ll r=1%n;
    a%=n;
    for (;b;b>>=1,a=a*a%n)
        if (b&1)
            r=r*a%n;
    return r;
}
void exgcd(ll a,ll&x,ll b,ll&y,ll&g)
{
    if (b) {
        exgcd(b,y,a%b,x,g);
        y -= a/b*x;
    } else {
        x=1;
        y=0;
        g=a;
    }
}
ll inv(ll a,ll n)
{
    ll x,y,g;
    a = (a%n+n)%n;
    exgcd(n,x,a,y,g);
    assert(g == 1);
    return (y%n+n)%n;
}
void find_generator()
{
    ll t = PHI;
    vector<ll> p;
    for (ll i = 2; i * i <= t; ++i)
        if (t % i == 0) {
            p.push_back(i);
            while (t % i == 0)
                t /= i;
        }
    if (t > 1)
        p.push_back(t);
    for (ll i = 2; i < P; ++i) {
        bool ok = true;
        for (ll j : p)
            if (qpow(i,PHI/j,P) == 1) {
                ok = false;
                break;
            }
        if (ok) {
            cerr << i << endl;
            exit(0);
        }
    }
}
const ll K = 100;
template<ll n>
struct mat
{
    ll a[K][K];
    mat()
    {
        memset(a,0,sizeof a);
    }
    mat operator * (const mat & b) const
    {
        mat c;
        for (int k = 0; k < K; ++k)
            for (int i = 0; i < K; ++i)
                for (int j = 0; j < K; ++j)
                    (c.a[i][j] += a[i][k] * b.a[k][j]) %= n;
        return c;
    }
    mat operator ^ (ll b) const
    {
        mat r,s(*this);
        for (int i = 0; i < K; ++i)
            r.a[i][i] = 1;
        for(;b;b>>=1,s=s*s)
            if (b&1)
                r=r*s;
        return r;
    }
};
ll dlog(ll a,ll b,ll n)
{
    ll k = sqrt(n);
    while (k*k < n)
        k++;
    unordered_map<ll,ll> mj;
    ll ia = inv(a,n);
    for (ll j = 0, v = b; j < k; ++j, v = v * ia % n)
        mj[v] = j;
    ll ak = qpow(a,k,n);
    for (ll i = 0, v = 1; i < k; ++i, v = v * ak % n) {
        auto it = mj.find(v);
        if (it != end(mj))
            return i * k + it->second;
    }
    assert(2 + 2 == 5);
}
ll k,n,m;
mat<PHI> A;
int main()
{
    cin >> k;
    for (ll i = 0; i + 1 < k; ++i)
        A.a[i][i+1] = 1;
    for (ll i = k-1; i >= 0; --i)
        cin >> A.a[k-1][i];
    cin >> n >> m;
    A=A^(n-k);
    ll a=A.a[k-1][k-1];
    ll c=dlog(G,m,P)%PHI;
    ll x,y,g;
    exgcd(a,x,PHI,y,g);
    if (c % g) {
        cout << "-1\n";
        return 0;
    }
    x = (x%PHI+PHI)%PHI;
    x = c/g * x % PHI;
    cout << qpow(G,x,P) << endl;
}
