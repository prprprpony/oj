#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
template<class T>
bool cmax(T & a,const T & b) {return a < b ? a = b, 1 : 0;}
template<class T>
bool cmin(T & a,const T & b) {return a > b ? a = b, 1 : 0;}
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define PER(i,a,b) for (int i((a)-1); i >= (b); --i)
#define SZ(a) ((int)(a).size())
/*>_<*/
typedef pii pt;
#define X first
#define Y second
pt operator + (const pt & a, const pt & b)
{
    return {a.X+b.X,a.Y+b.Y};
}
pt operator - (const pt & a, const pt & b)
{
    return {a.X-b.X,a.Y-b.Y};
}
ll operator ^ (const pt & a, const pt & b)
{
    return a.X * 1LL * b.Y - b.X * 1LL * a.Y;
}
ll operator * (const pt & a,const pt & b)
{
    return a.X * 1LL * b.X + a.Y * 1LL * b.Y;
}
ll dist(const pt & a,const pt & b)
{
    pt c = b - a;
    return c * c;
}
int nxt(int i,int n) {return i + 1 == n ? 0 : i + 1;}
const int N = 251234;
int n,k;
int sep[N],sn;
map<int,ll> ans[N];
pt p[N],ch[N];
ll far(int l,int r)
{
    if (r - l == 1)
        return dist(p[sep[r]-1], p[sep[l]]);
    l = sep[l];
    r = sep[r];
    if (ans[l].count(r))
        return ans[l][r];
    int bt=0, tp=0;
    for (int i = l; i < r; ++i) {
        while (tp - bt >= 2 && ((ch[tp-1]-ch[tp-2]) ^ (p[i] - ch[tp-2])) <= 0)
            --tp;
        ch[tp++] = p[i];
    }
    bt = tp-1;
    for (int i = r - 2; i >= l; --i) {
        while (tp - bt >= 2 && ((ch[tp-1]-ch[tp-2]) ^ (p[i] - ch[tp-2])) <= 0)
            --tp;
        ch[tp++] = p[i];
    }
    --tp;
    ll mx = 0;
    for (int i = 0, j = 1; i < j; ++i) {
        for (; ; j = nxt(j, tp)) {
            cmax(mx, dist(ch[i],ch[j]));
            if (((ch[i+1] - ch[i]) ^ (ch[nxt(j,tp)] - ch[j])) <= 0)
                break;
        }
    }
    return ans[l][r] = mx;
}
bool ok(ll m)
{
    int i,t;
    for (i = 0, t = 0; t < k && i < sn; ++t) {
        int h = 1;
        while (far(i,i+h) <= m && (i + h * 2) <= sn)
            h *= 2;
        int w = 0;
        for (; h; h >>= 1)  {
            int x = w | h;
            if (i + x <= sn && far(i,i+x) <= m)
                w = x;
        }
        i += w;
    }
    return i == sn;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> p[i].F >> p[i].S;
    sort(p,p+n);
    sn = 0;
    sep[sn++] = 0;
    for (int i = 1; i < n; ++i)
        if (p[i].F != p[i-1].F)
            sep[sn++] = i;
    sep[sn] = n;
    ll lo = 0, hi = 2e18;
    for (int i = 0; i < sn; ++i)
        cmax(lo, far(i,i+1));
    while (lo <= hi) {
        ll mi = lo + (hi - lo) / 2;
        if (ok(mi))
            hi = mi - 1;
        else
            lo = mi + 1;
    }
    cout << lo << endl;
}
