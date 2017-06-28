#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i(a),_B(b);i<_B;++i)
#define PER(i,a,b) for (int i((a)-1),_B(b);i>=_B;--i)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define F first
#define S second
#define EB emplace_back
#define PB push_back
#define SZ(a) ((int)a.size())
const int N = 1e5+87;
ll n;
char c[N];
int st[8787],tp;
inline bool ok(ll x) {return 1<=x&&x<=n;}
void go(ll s,ll t,ll u,int i)
{
    if (t != u) {
        if (u < t) {
            st[tp++] = 0;
            go ((s-1)/2,t-(s+1)/4,u,i);
        } else {
            st[tp++] = 1;
            go ((s-1)/2,t+(s+1)/4,u,i);
        }
    } else if (c[i]) {
        if (c[i] == 'L') {
            ll v = t-(s+1)/4;
            if (s >= 3 && ok(v)) {
                st[tp++] = 0;
                go((s-1)/2,v,v,i+1);
            } else
                go(s,t,t,i+1);
        } else if (c[i] == 'R') {
            ll v = t+(s+1)/4;
            if (s>=3&&ok(v)) {
                st[tp++] = 1;
                go((s-1)/2,v,v,i+1);
            } else
                go(s,t,t,i+1);
        } else {
            if (tp) {
                int d = st[--tp];
                ll v = t + (d ? - (s+1)/2 : (s+1)/2);
                go(2*s+1,v,v,i+1);
            } else
                go(s,t,t,i+1);
        }
    } else {
        printf("%lld\n",t);
    }
}
int main()
{
/*
(l+r)/2=t
r = t + ((s-1)/2-1)/2 +1
= t + (s+1)/4
l = 2t-r
= t -(s+1)/4

t = l + (sz(l)+1)/2
  = r - (sz(r)+1)/2
*/
    int q;
    scanf("%lld%d",&n,&q);
    while (q--) {
        ll u;
        scanf("%lld %s",&u, c);
        tp = 0;
        go(n,(n+1)/2,u,0);
    }
}
