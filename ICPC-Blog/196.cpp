#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
pii operator + (const pii & x,const pii & y) {return pii(x.F+y.F,x.S+y.S);}
const int N = 1e5 + 87;
int n,k;
pii a[N];
set<pii> ans;
void chk(pii p)
{
    int c = 0;
    for (int i = 0, j = n - 1; i <= j; ++i) {
        while (i < j && a[i] + a[j] > p)
            --j;
        if (a[i] + a[j] == p) {
            c += 1 + (i < j);
            --j;
        }
    }
    if (n - c <= k)
        ans.insert(p);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if (k >= n) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cin >> a[i].F >> a[i].S;
    sort(a,a+n);
    for (int i = 0; i <= k; ++i)
        for (int j = max(i, n - k - 1); j < n; ++j)
            chk(a[i] + a[j]);
    cout << ans.size() << '\n';
}
