#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87, P = 1314127, M = 1010101333;
ll pw[N], hs[N];
int n,m,la[N],a[N];
vector<int> po[26];
char s[N];
void pre()
{
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i-1] * P % M;
}
void bld()
{
    for (int i = 1; i <= n; ++i) {
        s[i] -= 'a';
        if (la[s[i]])
            a[i] = i - la[s[i]];
        la[s[i]] = i;
        po[s[i]].push_back(i);
        hs[i] = (hs[i-1] * P + a[i]) % M;
    }
}
ll qry(int l,int r)
{
    --l;
    ll h = hs[r] - hs[l] * pw[r-l] % M;
    for (int i = 0; i < 26; ++i) {
        auto it = upper_bound(begin(po[i]),end(po[i]),l);
        if (it == po[i].end())
            continue;
        int p = *it;
        if (p > r)
            continue;
        h -= a[p] * pw[r - p] % M;
    }
    return (h % M + M) % M;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pre();
    cin >> n >> m >> (s + 1);
    bld();   
    while (m--) {
        int x, y, l;
        cin >> x >> y >> l;
        cout << (qry(x,x+l-1) == qry(y,y+l-1) ? "YES\n" : "NO\n");
    }
}
