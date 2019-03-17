#include<bits/stdc++.h>
using namespace std;
void solve(int a,int b,int m,int v[])
{
    int n = __builtin_popcount(m);
    if (n == 1) {
        v[0] = a;
        v[1] = b;
        return;
    }
    int x = __lg(a ^ b);
    bool f = a>>x&1;
    a ^= f << x;
    b ^= (!f) << x;
    m ^= 1 << x;
    int c = a ^ (m & -m);
    solve(a,c,m,v);
    solve(c,b,m,v+(1<<(n-1)));
    for (int i = 0; i < (1<<(n-1)); ++i)
        v[i] ^= f<<x;
    for (int i = (1<<(n-1)); i < (1<<n); ++i)
        v[i] ^= (!f)<<x;
}
int main()
{
    int n,a,b,v[1<<17];
    cin >> n >> a >> b;
    if (__builtin_popcount(a^b)&1) {
        solve(a,b,(1<<n)-1,v);
        cout << "YES\n";
        for (int i = 0; i < (1<<n); ++i)
            cout << v[i] << " \n"[i+1==(1<<n)];
    } else {
        cout << "NO\n";
    }
}
