#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define ALL(a) begin(a),end(a)
const int N = 1<<19;
int n,k;
vector<pii> d[N];
void upd(int i,pii p)
{
    d[i].push_back(p);
    sort(ALL(d[i]),greater<pii>());
    d[i].erase(unique(ALL(d[i])),end(d[i]));
    if (d[i].size() > 2)
        d[i].pop_back();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    n = 1<<k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        auto p = pii(a,i);
        upd(i,p);
        if (i) {
            ans = max(ans, d[i][0].F + d[i][1].F);
            cout << ans << '\n';
        }
        for (int j = 1; j < n; j <<= 1)
            if ((i | j) != i)
                for (const auto & x : d[i])
                    upd(i | j, x);
    }
}
