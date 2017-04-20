#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
/* I DUCK HORSE */
const int N = 5e5 + 87;
struct hp
{
    size_t operator () (const pii & x) const
    {
        return hash<long long>()(((long long)x.F)<<32 | x.S);
    }
};
unordered_map<pii,pii,hp> la;
vector<pii> t[N*4];
int p[N],sz[N],cc,tp;
pair<int,int> h[N];

void jizz(int o,int l,int r,int i,int j, pii x)
{
    if (i <= l && r <= j) {
        t[o].push_back(x);
        return;
    }
    int m=(l+r)>>1;
    if (i < m)
        jizz(o+o+1,l,m,i,j,x);
    if (j > m)
        jizz(o+o+2,m,r,i,j,x);
}
int find(int x) {return x == p[x] ? x : find(p[x]);}
void gao(int o,int l,int r)
{
//cout<<'['<<l<<','<<r<<']'<<'\n';
    int otp = tp, occ = cc;
    for (const auto & x : t[o]) {
//cout<<x.F<<','<<x.S<<'\n';
        int a = find(x.F), b = find(x.S);
        if (a == b)
            continue;
        if (sz[a] > sz[b])
            swap(a,b);
        h[tp++] = {a,p[a]};
        p[a]=b;
        sz[b]+=sz[a];
        --cc;
    }
    t[o].clear();

    if (r-l == 1) {
        cout << cc << '\n';
    } else {
        int m=l+((r-l)>>1);
        gao(o+o+1,l,m);
        gao(o+o+2,m,r);
    }
    while (tp > otp) {
        --tp;
        int a = h[tp].F;
        sz[p[a]] -= sz[a];
        p[a] = h[tp].S;
    }
    cc = occ;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    fill_n(sz,N,1);
    la.reserve(N*4);
    int T;
    cin>>T;

    while (T--) {
        la.clear();
        int n,m,q;
        cin>>n>>m>>q;
//        la.reserve((m+q)*2);
        cc = n;
        for (int i = 0; i < m; ++i) {
            int u,v;
            cin>>u>>v;
            if (u>v)
                swap(u,v);
            pii x(u,v);
            auto it = la.find(x);
            if (it == la.end() || it->F != x)
                la.insert({x,{0,1}});
            else
                it->S.S++;
        }
        for (int i = 0; i < q; ++i) {
            char c;
            int u,v;
            cin >> c >> u >> v;
            if (u>v)
                swap(u,v);
            pii x(u,v);
            auto it = la.find(x);
            if (c == 'N') {
                if (it == la.end() || it->F != x)
                    la.insert({x,{i,1}});
                else
                    it->S.S++;
            } else {
                if (!--it->S.S) {
                    jizz(0,0,q,it->S.F,i,x);
                    la.erase(it);
                }
            }
        }
        for (const auto & x : la)
            jizz(0,0,q,x.S.F,q,x.F);
        gao(0,0,q);
    }
}
