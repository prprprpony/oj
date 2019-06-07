#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+87;
int n,a[N];
struct node
{
    vector<int> ma,mb,fi,la;
    int ans;
    node(int w)
    {
        ma = mb = vector<int>(w,-1);
        fi = vector<int>(2*w+1,N);
        la = vector<int>(2*w+1,-1);
        ans = 0;
    }
};
node DC(int l,int r)
{
    int w = r - l;
    node t(w);
    if (w == 1) {
        t.ma[0] = t.mb[0] = a[l];
        if (a[l] < 3) 
            t.fi[a[l]] = t.la[a[l]] = l;
        t.ans = a[l] == 0;
        return t;
    }
    int m = l + w/2;
    const auto & x = DC(l,m);
    const auto & y = DC(m,r);
    t.ans = x.ans + y.ans;
    int ul=m,ur=m-1;
    for (int i = m-1; i >= l; --i) {
        int u = x.mb[i-l];
        if (u >= w)
            break;
        if (x.la[a[i]] != i)
            break;
        ul = i;
    }
    for (int i = m; i < r; ++i) {
        int u = y.ma[i-m];
        if (u >= w)
            break;
        if (y.fi[a[i]] != i)
            break;
        ur = i;
    }
    int rm = ur + 1;
    for (int i = m-1; i >= ul; --i) {
        int u = x.mb[i-l];
        rm = min(rm, y.fi[a[i]]);
        int j = m-1 + u+1-(m-i);
        if (j < m || j >= rm)
            continue;
        t.ans += y.ma[j-m] < u;
    }
    int lm = ul - 1;
    for (int i = m; i <= ur; ++i) {
        int u = y.ma[i-m];
        lm = max(lm, x.la[a[i]]);
        int j = m-(u+1-(i-m+1));
        if (j >= m || j <= lm)
            continue;
        t.ans += x.mb[j-l] < u;
    }
    t.ma[0] = a[l];
    for (int i = l + 1; i < r; ++i)
        t.ma[i-l] = max(t.ma[i-l-1],a[i]);
    t.mb.back() = a[r-1];
    for (int i = r - 2; i >= l; --i)
        t.mb[i-l] = max(t.mb[i-l+1],a[i]);
    for (int i = l; i < r; ++i)
        if (a[i] < 2*w+1) {
            t.fi[a[i]] = min(t.fi[a[i]], i);
            t.la[a[i]] = i;
        }
    return t;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    cout << DC(0,n).ans << endl;
}
