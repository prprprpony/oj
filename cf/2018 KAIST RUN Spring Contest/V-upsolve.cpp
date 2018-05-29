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
const int N = 259487;
const ll inf = 1e18;
vector<int> g[N];
pair<int,pii> e[N];
typedef pair<ll,int> wt;
typedef pair<wt,int> hn;
wt d[N];
int st[N];
int n,m,k;
ll ans[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].S.F >> e[i].S.S >> e[i].F;
        e[i].F *= 2;
        g[e[i].S.F].push_back(i);
        g[e[i].S.S].push_back(i);
    }
    cin >> k;
    fill_n(d,N,wt(inf,N));
    priority_queue<hn,vector<hn>,greater<hn>> pq;
    for (int i = 0; i < k; ++i) {
        cin >> st[i];
        pq.push(hn(d[st[i]] = {0,st[i]}, st[i]));
    }
    while (pq.size()) {
        wt w;
        int u;
        tie(w,u) = pq.top();
        pq.pop();
        if (w != d[u])
            continue;
        for (int i : g[u]) {
            int v = e[i].S.F ^ e[i].S.S ^ u;
            if (cmin(d[v], wt(w.F+e[i].F,w.S))) {
                pq.push(hn(d[v],v));
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        tie(u,v) = e[i].S;
        ll w = e[i].F;
        ll du = d[u].F, dv = d[v].F;
        if (du < dv) {
            swap(u,v);
            swap(du,dv);
        }
        ll rt = min(du - dv,w);
        w -= rt;
        ans[d[v].S] += rt + w/2;
        ans[d[u].S] += w/2;
    }
    for (int i = 0; i < k; ++i) {
        ll & a = ans[st[i]];
        a *= 5;
        cout << a/10 << '.' << a%10 << '\n';
    }
}
