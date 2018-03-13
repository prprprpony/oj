#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a),end(a)
#define SZ(a) ((int)(a).size())
void solve(const vector<int> & a, vector<int> & ans,vector<int> & s,int p=1)
{
    if (SZ(s) >= SZ(ans))
        return;
    if (!SZ(a)) {
        ans = s;
        return;
    }
    vector<int> b;
    bool od = 0;
    for (int x : a) {
        if (x % 2) {
            od = 1;
            x -= 1;
        }
        x/=2;
        if ((!SZ(b) || x != b.back()) && x)
            b.push_back(x);
    }
    if (od) {
        s.push_back(p);
        solve(b,ans,s,p*2);
        s.pop_back();
        b.clear();
        for (int x : a) {
            if (x % 2)
                x -= -1;
            x/=2;
            if ((!SZ(b) || x != b.back()) && x)
                b.push_back(x);
        }
        s.push_back(-p);
        solve(b,ans,s,p*2);
        s.pop_back();
    } else {
        solve(b,ans,s,p*2);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a, ans(23), s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x)
            a.push_back(x);
    }
    sort(ALL(a));
    a.erase(unique(ALL(a)),end(a));
    solve(a,ans,s);
    cout << SZ(ans) << '\n';
    for (int i = 0; i < SZ(ans); ++i)
        cout << ans[i] << " \n"[i==SZ(ans)-1];
}
