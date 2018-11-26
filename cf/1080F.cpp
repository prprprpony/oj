#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
/**/
const int N = 3e5+87;
const int S = sqrt(N);
struct block {
    vector<pair<pii,int>> v;
    vector<int> rt;
    int n,w;
    void bld()
    {
        sort(begin(v),end(v));
        n = v.size();
        multiset<pii> st;
        vector<queue<pii>> cnt(w);
        rt.resize(n);
        int nc = 0;
        int i=0,j=0;
        for (;i<n;++i) {
            while (nc < w && j<n) {
                pii x{v[j].F.S,v[j].F.F};
                if (cnt[v[j].S].size() == 0) {
                    ++nc;
                    st.insert(x);
                }
                cnt[v[j].S].push(x);
                ++j;
            }
            rt[i] = nc == w ? prev(end(st))->F : INT_MAX;
            st.erase(st.lower_bound(cnt[v[i].S].front()));
            cnt[v[i].S].pop();
            if (cnt[v[i].S].size() == 0) {
                --nc;
            } else {
                st.insert(cnt[v[i].S].front());
            }
        }
    }
    bool qry(int x,int y)
    {
        int k = lower_bound(begin(v),end(v),make_pair(pii(x,INT_MIN),INT_MIN)) - begin(v);
        return  k < n && rt[k] <= y;
    }
} blk[N];
int n,m,k;
vector<pii> st[N];
bool qry(int p,int x,int y)
{
    const auto & s = st[p];
    auto it = lower_bound(begin(s),end(s),pii{x,INT_MIN});
    return it!=end(s) && it->S <= y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while (k--) {
        int l,r,p;
        cin >> l >> r >> p;
        ++r;
        --p;
        auto & s = st[p];
        s.emplace_back(l,r);
    }
    for (int p = 0; p < n; ++p) {
        auto & s = st[p];
        sort(begin(s),end(s),
            [](const pii & a,const pii &b)->bool {
                return pii(a.F,-a.S) < pii(b.F,-b.S);
            });
        int i,j;
        for (i=1,j=0; i < s.size(); ++i) {
            while (j >= 0 && s[j].F <= s[i].F && s[i].S <= s[j].S)
                --j;
            s[++j] = s[i];
        }
        s.resize(j+1);
    }
    for (int i = 0; i * S < n; ++i) {
        int l = i*S, r = min(i*S+S,n);
        blk[i].w = r-l;
        for (int j = l; j < r; ++j) {
            for (const auto & p : st[j])
                blk[i].v.emplace_back(p,j-l);
        }
        blk[i].bld();
    }
    while (m--) {
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        --a,++y;
        bool ok = true;
        while (a % S && a < b)
            ok &= qry(a++,x,y);
        while (b % S && a < b)
            ok &= qry(--b,x,y);
        for (int i = a/S; i < b/S; ++i)
            ok &= blk[i].qry(x,y);
        cout << (ok ? "yes" : "no") << endl;
    }
}
