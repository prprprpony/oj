#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
int fen[N];
vector<pii> a[N];
int po[N];
int qry(int i)
{
    int ret = 0;
    for (; i; i ^= i & -i)
        ret += fen[i];
    return ret;
}
void upd(int i,int x)
{
    for (; i < N; i += i & -i)
        fen[i] += x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <n; ++i) {
        int l,r;
        cin >> l >> r;
        a[r - l + 1].emplace_back(l,r);
    }
    for (int i = m; i >= 1; --i)
        po[i] = a[i].size() + po[i+1];
    for (int i = 1; i <= m; ++i) {
        int ans = po[i];
        for (int j = i; j <= m; j += i)
            ans += qry(j);
        cout << ans << '\n';
        for (const pii & p : a[i]) {
            upd(p.F,1);
            upd(p.S+1,-1);
        }
    }
}
