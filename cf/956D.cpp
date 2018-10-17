#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
pii frac(int a,int b)
{
    if (b < 0)
        b=-b,a=-a;
    return pii(a,b);
}
bool lt(const pii & a,const pii & b)
{
    return a.F*1LL*b.S<b.F*1LL*a.S;
}
bool ltt(const pair<pii,pii> & a,const pair<pii,pii> & b)
{
    if (lt(a.F, b.F) || lt(b.F,a.F))
        return lt(a.F,b.F);
    return lt(b.S,a.S);
}
const int N = 1e5 + 87;
pii fv[N];
pair<pii,pii> pp[N];
int f[N];
void add(int i)
{
    for (;i<N;i+=i&-i)
        ++f[i];
}
int qry(int i)
{
    int r=0;
    for (;i;i^=i&-i)
        r += f[i];
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        int x,v;
        cin >> x >> v;
        pii yl = frac(v-w,x), yr = frac(v+w,x);
        fv[i] = yl;
        pp[i] = {yr,yl};
    }
    sort(fv,fv+n,lt);
    sort(pp,pp+n,ltt);
    long long ans = 0;
    for (int i = n-1; i >= 0; --i) {
        int k = lower_bound(fv,fv+n,pp[i].S,lt) - fv + 1;
        ans += qry(k);
        add(k);
    }
    cout << ans << endl;
}
/*
t = -x_i / v_i
=> t_i = -x_i / (v_i + v_w), -w <= v_w <= w
t_i = t_j
<=> -x_i / (v_i + v_w) = -x_j / (v_j + v_w)
<=> x_i / (v_i + v_w) = x_j / (v_j + v_w)
<=> (v_i + v_w) / x_i = (v_j + v_w) / x_j

t_i is a linear function of v_w

*/
