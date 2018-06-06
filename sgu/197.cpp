#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
const int W = 1<<5;
int p;
struct mat
{
    ui a[W][W];
    mat(int o = 0) 
    {
        memset(a,0,sizeof(a));
        if (o) {
            for (int i = 0; i < W; ++i)
                a[i][i] = 1;
        }
    }
    ui* operator [] (int i) {return a[i];}
    const ui * operator [] (int i) const {return a[i];}
    mat operator * (const mat & b) const {
        mat c;
        for (int k = 0; k < W; ++k)
            for (int i = 0; i < W; ++i)
                for (int j = 0; j < W; ++j)
                    c[i][j] += a[i][k] * b[k][j];
        for (int i = 0; i < W; ++i)
            for (int j = 0; j < W; ++j)
                c[i][j] %= p;
        return c;
    }
} t;
mat qpow(mat a,int b)
{
    mat r(1);
    for (;b;b>>=1,a=a*a)
        if (b&1)
            r = r * a;
    return r;
}
bool ok(int x)
{
    int la = -87;
    for (int i = 0; x; x>>=1,++i)
        if (x&1) {
            if (la == i - 1)
                return 0;
            la = i;
        }
    return 1;
}
int main()
{
    string n;
    int m;
    cin >> n >> m >> p;
    for (int i = n.size() - 1; i >= 0; --i) {
        if (n[i] == '0') {
            n[i] = '9';
        } else {
            n[i]--;
            break;
        }
    }
    int S = (1<<m)-1;
    for (int i = 0; i <= S; ++i)
        for (int j = 0; j <= S; ++j)
            t[i][j] = ok(i & j) && ok((S^i)&(S^j));
    mat a[10];
    a[0] = mat(1);
    for (int i = 1; i < 10; ++i)
        a[i] = t * a[i-1];
    mat ans(1);
    for (int i = 0; i < n.size(); ++i)
        ans = qpow(ans,10) * a[n[i]-'0'];
    ui su = 0;
    for (int i = 0; i <= S; ++i)
        for (int j = 0; j <= S; ++j)
            su = (su + ans[i][j]) % p;
    cout << su << endl;
}
