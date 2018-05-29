#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define F first
#define S second
const int N = 1e5 + 87;
int dsu[N],fen[N],sz[N],n,q,tot;
map<int,int> cnt;
int find(int x) {return dsu[x] == x ? x : dsu[x] = find(dsu[x]);}
void sub(int i)
{
    if (--cnt[i] == 0)
        cnt.erase(i);
}
void meld(int x,int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return ;
    --tot;
    sub(sz[x]);
    sub(sz[y]);
    dsu[y] = x;
    sz[x] += sz[y];
    ++cnt[sz[x]];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    iota(dsu+1,dsu+n+1,1);
    fill_n(sz+1,n,1);
    tot = cnt[1] = n;
    while (q--) {
        int ty,x,y;
        cin >> ty;
        if (ty == 1) {
            cin >> x >> y;
            meld(x,y);
        } else {
            cin >> x;
            ll ans = tot * (tot - 1LL) / 2;
            if (x == 0) {
                cout << ans << '\n';
                continue;
            }
            ll su = 0;
            for (auto it = begin(cnt), jt = begin(cnt); it != end(cnt); ++it) {
                while (jt != end(cnt) && jt->F < it->F + x) {
                    su += jt->S;
                    ++jt;
                }
                su -= it->S;
                ans -= it->S * 1LL * su + it->S * (it->S - 1LL) / 2;
            }
            cout << ans << '\n';
        }
    }
}
