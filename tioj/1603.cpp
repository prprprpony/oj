#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
const int N = 1e5+87;
template<typename T>
struct rmqq
{
    static const int K = 4;
    static const int M = N>>K;
    static const int G = __lg(M) + 1;
    int n;
    T t[K+1][N];
    int nxt[N];
    int m;
    T v[G][M];
    function<T(T,T)> f;

    void build(T * a,int _n,function<T(T,T)> fun)
    {
        n = _n;
        copy_n(a,n,t[0]);
        f = fun;
        for (int i = 1; i <= K && (1<<i) <= n; ++i)
            for (int j = 0; j + (1<<i) <= n; ++j)
                t[i][j] = f(t[i-1][j],t[i-1][j+(1<<(i-1))]);
        m = 0;
        int li = 0;
        for (int i = 1<<K; i + (1<<K) < n; ++i) {
            T x = f(t[K][i-(1<<K)],t[K][i+1]);
            if (t[K][i-(1<<K)] != a[i] && f(a[i],x) == a[i]) {
                for (; li <= i; nxt[li] = m, ++li);
                v[0][m++] = a[i];
                i += (1<<K);
            }
        }
        for (; li < n; nxt[li] = m, ++li);
        for (int i = 1; (1<<i) <= m; ++i)
            for (int j = 0; j + (1<<i) <= m; ++j)
                v[i][j] = f(v[i-1][j],v[i-1][j+(1<<(i-1))]);
    }
    T qry(int l,int r)
    {
        int k = r - l;
        if (k < (2<<K)) {
            k = __lg(k);
            return f(t[k][l],t[k][r-(1<<k)]);
        }
        T ret = f(t[K][l],t[K][r-(1<<K)]);
        l = nxt[l + (1<<K)], r = nxt[r - (1<<K)];
        if (l < r) {
            k = __lg(r - l);
            ret = f(ret,f(v[k][l],v[k][r-(1<<k)]));
        }
        return ret;
    }
};
rmqq<ui> mx,mn;
ui a[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    mx.build(a,n,[](ui a,ui b)->ui{return max(a,b);});
    mn.build(a,n,[](ui a,ui b)->ui{return min(a,b);});
    while (m--) {
        int l,r;
        cin >> l >> r;
        --l;
        cout << mx.qry(l,r) - mn.qry(l,r) << '\n';
    }
}
