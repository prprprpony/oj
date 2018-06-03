#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
typedef pair<int,int> pii;
#define F first
#define S second
pair<pii,int> a[N];
int v[N],m,p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a[0] = {pii(-2e9,-2e9),0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].F.F >> a[i].F.S;
        a[i].S = i;
        a[i].F.S *= -1;
    }
    sort(a+1,a+n+1);
    ++m;
    for (int i = 1; i <= n; ++i) {
        a[i].F.S *= -1;
        if (a[i].F.S > a[v[m-1]].F.S) {
            p[i] = v[m-1];
            v[m++] = i;
        } else {
            int j = lower_bound(v,v+m,i,[&](int x,int y)->bool{return a[x].F.S < a[y].F.S;}) - v;
            p[i] = v[j-1];
            v[j] = i;
        }
    }
    cout << m-1 << '\n';
    for (int i = m-2; i >= 1; --i)
        v[i] = p[v[i+1]];
    for (int i = 1; i < m; ++i)
        cout << a[v[i]].S << " \n"[i==m-1];
}
