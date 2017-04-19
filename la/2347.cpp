#include <bits/stdc++.h>
using namespace std;
struct mat
{
    double a[2][2];
    mat operator * (const mat & x)
    {
        mat y;
        for (int r = 0; r < 2; ++r)
            for (int c = 0; c < 2; ++c) {
                y.a[r][c] = 0.0;
                for (int k = 0; k < 2; ++k)
                    y.a[r][c] += a[r][k] * x.a[k][c];
            }
        return y;
    }
};
mat qpow(mat a,int x)
{
    mat ret;
    ret.a[0][0] = 1;
    ret.a[0][1] = 0;
    ret.a[1][0] = 0;
    ret.a[1][1] = 1;
    for (; x; x>>=1,a=a*a)
        if (x&1)
            ret = ret * a;
    return ret;
}
long long rd(double x)
{
    return x < 0 ? x - 0.5 : x + 0.5;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int f[2],n;
        double a,b;
        cin >> f[0] >> f[1] >> a >> b >> n;
        if (n <= 1)
            cout << f[n] << '\n';
        else {
            mat m;
            m.a[0][0] = a;
            m.a[0][1] = b;
            m.a[1][0] = 1;
            m.a[1][1] = 0;
            m = qpow(m,n-1);
            cout << rd(m.a[0][0] * f[1] + m.a[0][1] * f[0]) << '\n';
        }
    }
}
