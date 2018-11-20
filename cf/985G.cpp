#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
typedef int64_t ll;
typedef uint64_t llu;
const int N = 2e5+87;
const int S = sqrt(N);
int n,m;
llu a,b,c,ans;
vector<ll> rt[N],lt[N];
vector<pii> e;
int in[N],vc;
vector<pii> qry[N];
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> a >> b >> c;
    while (m--) {
        int u,v;
        cin >> u >> v;
        if (u > v)
            swap(u,v);
        rt[u].push_back(v);
        lt[v].push_back(u);
        e.emplace_back(u,v);
    }
    for (int i = 0; i < n; ++i) {
        sort(begin(lt[i]),end(lt[i]));
        sort(begin(rt[i]),end(rt[i]));
    }
    for (ll i = n-3; i >= 0; --i)
        ans += (n-i-1)*(n-i-2)/2 * a * i;
    for (ll i = 1; i < n-1; ++i)
        ans += i*(n-i-1) * b * i;
    for (ll i = 2; i < n; ++i)
        ans += i*(i-1)/2 * c * i;
    for (ll i = 0; i < n; ++i) {
        for (auto j : rt[i]) {
            ans -= (a*i+b*j) * (n-j-1) + (j+1+n-1)*(n-j-1)/2 * c;
            ans -= (b*i+c*j) * i + (i-1)*i/2 * a;
            ans -= (a*i+c*j) * (j-i-1) + (i+1+j-1)*(j-i-1)/2 * b;
        }
        llu s = 0, w = 0, v = 0;
        for (int k = 0; k < rt[i].size(); ++k) {
            auto j = rt[i][k];
            w += k;
            v += c*j*k + s;
            s += b*j;
        }
        ans += a*i*w + v;
        s=0,w=0,v=0;
        for (int k = 0; k < lt[i].size(); ++k) {
            auto j = lt[i][k];
            w += k;
            v += b*j*k + s;
            s += a*j;
        }
        ans += c*i*w + v;
        s=0,w=lt[i].size()*rt[i].size(),v=0;
        for (auto j : lt[i])
            v += a*j*rt[i].size();
        for (auto j : rt[i])
            v += c*j*lt[i].size();
        ans += b*i*w + v;
        if (rt[i].size() <= S) {
            for (int j = 0; j < rt[i].size(); ++j)
                 qry[rt[i][j]].emplace_back(i,j+1);
        } else {
            ++vc;
            for (auto j : rt[i])
                in[j] = vc;
            for (const auto & p : e) {
                int j,k;
                tie(j,k) = p;
                if (in[j] == vc && in[k] == vc)
                    ans -= a*i+b*j+c*k;
            }
        }
    }
    for (ll j = 0; j < n; ++j) {
        ++vc;
        for (auto k : rt[j])
            in[k] = vc;
        for (const auto & p : qry[j]) {
            int i,k;
            tie(i,k) = p;
            for (; k < rt[i].size(); ++k)
                if (in[rt[i][k]] == vc)
                    ans -= a*i+b*j+c*rt[i][k];
        }
    }
    cout << ans << endl;
}
