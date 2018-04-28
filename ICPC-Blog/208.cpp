#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
template<class T>
bool cmin(T & a,const T & b) {return b < a ? a = b, 1 : 0;}
const int N = 1e5 + 87;
const ll inf = 1e18;
int g;
ll c[10], d[N];
int fin[N];
int u, v;
void input()
{
    int a,b,n,s[10];
    cin >> a >> b >> n;
    g = __gcd(a,b);
    fill_n(c,10,inf);
    for (int i = 0; i < n ;++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        cmin(c[s[i]], t);
    }
    cin >> u >> v;
}
void dijk()
{
    fill_n(d,g,inf);
    int x = u % g;
    d[x] = 0;
    typedef pair<ll,int> nd;
    priority_queue<nd,vector<nd>,greater<nd>> pq;
    pq.push({d[x],x});
    while (pq.size()) {
        ll w;
        tie(w,x) = pq.top();
        pq.pop();
        if (w > d[x])
            continue;
        x = x * 10 % g;
        for (int i = 0; i < 10; ++i, x = (x + 1) % g)
            if (cmin(d[x], w + c[i])) 
                pq.push({d[x],x});
    }
}
int go(int x)
{
    x %= g;
    if (fin[x])
        return fin[x];
    fin[x] = 1;
    for (int i = 0; i < 10; ++i) {
        int y = (10 * x + i) % g;
        if (d[x] + c[i] == d[y])
            fin[x] |= go(y);
    }
    return fin[x];
}
void prt(int x,int p)
{
    cout << p;
    if (fin[x] == 2) {
        cout << v << endl;
        return;
    }
    for (int i = 0; i < 10; ++i) {
        int y = (10 * x + i) % g;
        if (d[x] + c[i] == d[y] && fin[y] >= 2) {
            prt(y,i);
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    dijk();
    ll mv = inf;
    for (int i = 0; i < g; ++i)
        if ((10 * i + v) % g == 0)
            mv = min(mv, d[i]);
    if (mv == inf) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < g; ++i)
        if ((10 * i + v) % g == 0 && d[i] == mv)
            fin[i] = 2;
    go(u%g);
    prt(u%g,u);
}
