#include<bits/stdc++.h>
#include "lib1965.h"
using namespace std;
const int N = 1e7+87,THRESHOLD=1e6;
template<typename T>
struct rmqq
{
    static const int K = 4;
    static const int M = N>>K;
    static const int G = __lg(M) + 1;
    int n;
    T * t[K+1];
    int * nxt;
    int m;
    T * v[G];
    function<T(T,T)> f;

    void build(T * a,int _n,function<T(T,T)> fun)
    {
        n = _n;
		t[0] = new T[n];
        copy_n(a,n,t[0]);
        f = fun;
        for (int i = 1; i <= K && (1<<i) <= n; ++i) {
			t[i] = new T[n-(1<<i)+1];
            for (int j = 0; j + (1<<i) <= n; ++j)
                t[i][j] = f(t[i-1][j],t[i-1][j+(1<<(i-1))]);
		}
        m = 0;
        int li = 0;
		nxt = new int[n];
		v[0] = new T[n];
        for (int i = 1<<K; i + (1<<K) < n; ++i) {
            T x = t[K][i-(1<<K)],y = t[K][i+1];
            if (x != a[i] && f(a[i],f(x,y)) == a[i]) {
                for (; li <= i; nxt[li] = m, ++li);
                v[0][m++] = a[i];
                i += (1<<K);
            }
        }
        for (; li < n; nxt[li] = m, ++li);
        for (int i = 1; (1<<i) <= m; ++i) {
			v[i] = new T[m-(1<<i)+1];
            for (int j = 0; j + (1<<i) <= m; ++j)
                v[i][j] = f(v[i-1][j],v[i-1][j+(1<<(i-1))]);
		}
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
template<typename T>
struct segt
{
	int n;
	T * t;
    function<T(T,T)> f;
	void bld(T*a,int o,int l,int r)
	{
		if (r-l==1) {
			t[o] = l[a];
			return;
		}
		int m=(l+r)>>1;
		bld(a,o+o+1,l,m);
		bld(a,o+o+2,m,r);
		t[o]=f(t[o+1+o],t[o+2+o]);
	}
	void build(T*a,int _n,function<T(T,T)> fun)
	{
		f=fun;
		t=new T[(n=_n)<<2];
		bld(a,0,0,n);
	}
	T qry(int o,int l,int r,int i,int j)
	{
		if (i <= l && r <= j)
			return t[o];
		int m = (l+r)>>1;
		if (j<=m)
			return qry(o+o+1,l,m,i,j);
		if (m<=i)
			return qry(o+o+2,m,r,i,j);
		return f(qry(o+o+1,l,m,i,j),qry(o+o+2,m,r,i,j));
	}
};
typedef uint64_t ui;
rmqq<ui> mx;
segt<ui> sg;
int n;
void init(int N, uint64_t C[])
{
	n = N;
	if (n <= THRESHOLD)
		sg.build(C,N,[](ui a,ui b)->ui{return max(a,b);});
	else
	    mx.build(C,N,[](ui a,ui b)->ui{return max(a,b);});
}
uint64_t RMQ(int a, int b)
{
	return n <= THRESHOLD ? sg.qry(0,0,n,a,b) : mx.qry(a,b);
}
