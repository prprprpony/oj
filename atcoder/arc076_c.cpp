#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
int r,c,n;
pii w[112345];
int read()
{
    int x,y;
    cin >> x >> y;
    if (!x)
        return y;
    if (y == c-1)
        return c+x;
    if (x == r-1)
        return c+r+c-1-y;
    if (y == 0)
        return c+r+c+r-x-1;
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> n;
    ++r,++c;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        int a=read(),b=read();
        if (a > b)
            swap(a,b);
        w[i] = {a,b};
        if (a >= 0 && b >= 0) {
            v.push_back({a,i});
            v.push_back({b,i});
        }
    }
    sort(begin(v),end(v));
    vector<pii> s;
    for (auto p : v) {
        if (p.F == w[p.S].F) 
            s.push_back(p);
        else {
            if (s.back() != pii{w[p.S].F,p.S}) {
                cout << "NO\n";
                return 0;
            }
            s.pop_back();
        }
    }
    cout << "YES\n";
}
