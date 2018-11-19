#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
template<class T>
bool cmax(T&a,const T&b) {return a<b?a=b,1:0;}
/**/
const int N = 3e5 + 98;
int n,m,vis[N],vc,inp[N];
void gao(int out[],vector<int> g[],const vector<int>&p)
{
    ++vc;
    vector<int> q;
    for (auto i = p.size(); i--;) {
        q = {p[i]};
        vis[p[i]] = vc;
        for (size_t k = 0; k < q.size(); ++k) {
            for (int v : g[q[k]])
                if (vis[v] != vc) {
                    vis[v] = vc;
                    q.push_back(v);
                }
        }
        out[i] = out[i+1] + q.size();
    }
}
void gao2(int out2[],vector<int> g[],const vector<int>&p,const vector<int>&cand)
{
    ++vc;
    vector<int> q;
    for (auto i = p.size(); i--;) {
        q = {p[i]};
        vis[p[i]] = vc;
        for (size_t k = 0; k < q.size(); ++k) {
            for (int v : g[q[k]])
                if (vis[v] != vc) {
                    vis[v] = vc;
                    q.push_back(v);
                }
        }
        if (i && cand[i-1]) {
            q = {cand[i-1]};
            vis[q.back()] = vc;
            for (size_t k = 0; k < q.size(); ++k) {
                for (int v : g[q[k]])
                    if (vis[v] != vc) {
                        vis[v] = vc;
                        q.push_back(v);
                    }
            }
            out2[i-1] = q.size();
            for (int v : q)
                vis[v] = 0;
        }
    }
}
vector<int> g[N],h[N],gp,hp,gcand,hcand;
int in[N],out[N],d[N],in2[N],out2[N];
int dp(int u)
{
    if (d[u])
        return d[u];
    for (int v : g[u])
        cmax(d[u],dp(v));
    return ++d[u];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        h[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        g[0].push_back(i);
        h[i].push_back(0);
        g[i].push_back(n+1);
        h[n+1].push_back(i);
    }
    n += 2;
    dp(0);
    gp = {0};
    while (g[gp.back()].size()) {
        int u = gp.back();
        inp[u] = 1;
        for (int v : g[u])
            if (d[v] + 1 == d[u]) {
                gp.push_back(v);
                break;
            }
    }
    hp = gp;
    int ps = gp.size();
    reverse(begin(hp),end(hp));
    gao(out,g,gp);
    gao(in,h,hp);
    gcand.assign(ps,0);
    int ans = 0;
    for (int i = 0; i < ps; ++i) {
        if (in[i] + out[ps-1-i] - 1 >= n - 1) {
            ++ans;
//cerr << "u " << gp[i] << endl; cerr << ' ' << in[i] << ' ' << out[ps-1-i] << '\n';
        }

        if (i + 2 < ps) {
            ++vc;
            for (int u : g[gp[i]])
                if (!inp[u])
                    vis[u] = vc;
            int k = 0;
            for (int u : h[gp[i+2]])
                if (vis[u] == vc) {
                    gcand[i+1] = u;
                    ++k;
                }
            gcand[i+1] *= k <= 1; 
        }
    }
//for (int i = 0; i < ps; ++i) cerr <<"cand["<<i<<"]="<<gcand[i]<<endl;
    hcand = gcand;
    reverse(begin(hcand),end(hcand));
    gao2(out2,g,gp,gcand);
    gao2(in2,h,hp,hcand);
    for (int i = 0; i < ps; ++i)
        if (gcand[i]) {
//            cerr << "gcand[i]:" << gcand[i] << endl; cerr<<"in2 ou2 out[i+1] in[ps-1-(i-1)]" << in2[ps-1-i] << ' ' << out2[i] << ' ' << out[i+1] << ' ' <<  in[ps-1-(i-1)] << endl;
            if (in2[ps-1-i] + out2[i] - 1 + out[i+1] + in[ps-1-(i-1)] == n - 1) {
                ++ans;
 //               cerr << "v " <<  gcand[i] << endl;
            }
        }
    cout << ans-2 << '\n';
}
