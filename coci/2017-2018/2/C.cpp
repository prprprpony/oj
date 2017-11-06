#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
typedef pair<int,int> pii;
#define F first
#define S second
/*>_<*/
const int N = 5e5 + 87;
int a[N], pr[N], po[N];
map<int,vector<int>> v;
void add(vector<int> & x, int y)
{
    if (!SZ(x))
        x.PB(0);
    x.PB(y);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        pr[i] = (a[i] == i) + pr[i-1];
    for (int i = n; i >= 1; --i)
        po[i] = (a[i] == i) + po[i+1];
    for (int i = 1; i <= n; ++i) {
        int b = a[i] - (n + 1 - i);
        add(v[b],i);
    }
    int ans = pr[n];
    pii ai = {1,1};
    for (auto it = begin(v); it != end(v); ++it) {
        auto & d = it->S;
        d.PB(n+1);
        int k = it->F;
        int i,j;
        if ((n + k) % 2 == 0) {
            i = (n+k)/2;
            j = i + 1;
        } else {
            i = j = (n+k+1)/2;
        }
        auto r = upper_bound(ALL(d), j);
        auto l = r;
        while (1 <= i && j <= n) {
            while (*r <= j)
                ++r;
            while (*l >= i)
                --l;
            int w = pr[i-1] + po[j+1] + (r - l - 1);
            if (w > ans) {
                ans = w;
                ai = {i,j};
            }
            int t = min(*r - j, i - *l);
            j += t;
            i -= t;
        }
    }
//    cout << ans << '\n';
    cout << a[ai.F] << ' ' << a[ai.S] << '\n';
}
