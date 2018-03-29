#include<bits/stdc++.h>
using namespace std;
const int N = 1087, inf = 0x3f3f3f3f, M = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
struct mat
{
    int a[3][3];
    mat()
    {
        memset(a,0,sizeof(a));
    }
    const int * operator [] (int i) const
    {
        return a[i];
    }
    int * operator [] (int i) 
    {
        return a[i];
    }
    mat operator = (const mat & x)
    {
        memcpy(a,x.a,sizeof(a));
        return x;
    }
    mat operator * (const mat & x)
    {
        mat t;
        for (int k = 0; k < 3; ++k)
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    (t[i][j] += a[i][k] * 1LL * x[k][j] % M) %= M;
        return t;
    }
    void print(string s)
    {
        cout << "=======" << s<< "========\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cout << a[i][j] << ",\n"[j==2];
    }
} t;
int main()
{
    t[0][0] = t[0][1] = 1;
    t[1][0] = t[1][1] = t[1][2] = 1;
    t[2][2] = t[2][1] = 1;

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    vector<pair<ll,int>> v;
    for (int i = 0; i < n; ++i) {
        ll a, l, r;
        cin >> a >> l >> r;
        --a;
        v.emplace_back(l,a<<1|1);
        v.emplace_back(r+1,a<<1|0);
    }
    v.emplace_back(m+1,0);
    sort(begin(v),end(v));
    mat ans;
    ans[1][0] = 1;
    int c[3] = {};
    ll lx = 2;
    for (int i = 0, j; i < v.size(); i = j) {
        ll w = v[i].F - lx;
        mat r = t;
        for (int k = 0; k < 3; ++k)
            if (c[k])
                for (int kk = 0; kk < 3; ++kk)
                    r[k][kk] = 0;
        /*
        for(int i = 0; i <3;++i)
            cout << "c[" << i << "]=" << c[i] << endl;
        cout << lx << ',' << v[i].F << endl;
        r.print("r");
        ans.print("ans");
        */
        for (;w;w>>=1, r=r*r)
            if (w&1)
                ans = r * ans;
        lx = v[i].F;
        for (j = i; j < v.size() && v[j].F == v[i].F; ++j) {
            int k = v[j].S >> 1;
            int x = (v[j].S & 1) ? 1 : -1;
            c[k] += x;
        }
    }
    cout << ans[1][0] << endl;
}
