#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+6;
struct mat
{
    ll a[5][5];
    mat(ll v=0)
    {
        memset(a,0,sizeof a);
        if (v %= M)
            for (int i = 0; i < 5; ++i)
                a[i][i] = v;
    }
    mat operator * (const mat & b) const
    {
        mat c;
        for (int k = 0; k < 5; ++k)
            for (int i = 0; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    (c.a[i][j] += a[i][k] * b.a[k][j]) %= M;
        return c;
    }
    mat operator % (const mat & b) const
    {
        return *this;
    }
};
template<class T>
T qpow(T a,ll b,T m)
{
    T r = T(1);
    for (;b;b>>=1,a=a*a%m)
        if (b & 1)
            r = r * a % m;
    return r;
}
int main()
{
    ll n,f[3],c,ans=1;
    cin >> n >> f[0] >> f[1] >> f[2] >> c;
    n -= 3;
    mat a;
    a.a[0][1] = a.a[1][2] = 1;
    for (int i = 0; i < 3; ++i) a.a[2][i] = 1;
    a = qpow(a,n,a);
    for (int i = 0; i < 3; ++i)
        ans = ans * qpow(f[i], a.a[2][i], M+1) % (M+1);
    a = mat(0);
    a.a[0][1] = a.a[1][2] = a.a[3][3] = a.a[3][4] = a.a[4][4] = 1;
    for (int i = 0; i < 4; ++i)
        a.a[2][i] = 1;
    a = qpow(a,n,a);
    ans = ans * qpow(c, (a.a[2][3] + a.a[2][4]) * 2 % M, M+1) % (M+1);
    cout << ans << endl; 
}
