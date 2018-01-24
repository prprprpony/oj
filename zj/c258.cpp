#include<bits/stdc++.h>
using namespace std;
struct
{
    vector<int> val, f;
    void co(int x)
    {
        val.push_back(x);
    }
    void init()
    {
        sort(begin(val),end(val));
        val.erase(unique(begin(val),end(val)),end(val));
        f.clear();
        f.resize(val.size()+1,0);
    }
    int id(int x)
    {
        return upper_bound(begin(val),end(val),x) - begin(val);
    }
    void add(int i,int v)
    {
        for (i = id(i); i <= val.size(); i += i&-i)
            f[i] += v;
    }
    int qry(int i)
    {
        int ans = 0;
        for (i = id(i); i; i ^= i&-i)
            ans += f[i];
        return ans;
    }
    int qry(int x,int y)
    {
        return qry(y) - qry(x);
    }
} f;
const int N = 5e5 +87;
pair<int,int> p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, r;   
        cin >> x >> r;
        p[i] = {x-r,x+r};
        f.co(p[i].second);
    }
    sort(p,p+n);
    f.init();
    long long ans = 0;
    for (int i = 0, j; i < n;) {
        for (j = i; j < n and p[j].first == p[i].first; ++j)
            ans += f.qry(p[j].first-1) + f.qry(p[j].second,2e9+987);
        for (; i < j; ++i)
            f.add(p[i].second,1);
    }
    cout << ans << '\n';
}
