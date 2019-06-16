#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 5e5+87;
int n,a[N],b[N],c[N],d[N],g[N],po[N];
// x = [a,b], y = [c,d]
bool ok(int l,int r)
{

    if (r - l == 1)
        return true;
    sort(g+l,g+r,[&](int i,int j){return b[i] < b[j];});
    vector<int> sep{l};
    po[r] = INT_MAX;
    for (int i=r-1; i>=l;--i)
        po[i] = min(po[i+1],a[g[i]]);
    for (int i = l; i < r; ++i)
        if (b[g[i]] <= po[i+1])
            sep.push_back(i+1);
    if (sep.size() > 2) {
        /*
cerr << "sep x" << endl;
cerr << "(l,r) "<< l << ' ' << r << endl;
for (int i = l; i < r; ++i)
    cerr << g[i] << ' ';
cerr << endl;
for (int x : sep)
    cerr << x << ' ';
cerr << endl;
cerr << "=============="<<endl;
*/
        for (int i = 0; i+1 < sep.size(); ++i)
            if (!ok(sep[i],sep[i+1]))
                return false;
        return true;
    }
    sort(g+l,g+r,[&](int i,int j){return d[i] < d[j];});
    sep = {l};
    po[r] = INT_MAX;
    for (int i=r-1; i>=l;--i)
        po[i] = min(po[i+1],c[g[i]]);
    for (int i = l; i < r; ++i)
        if (d[g[i]] <= po[i+1])
            sep.push_back(i+1);
    if (sep.size() > 2) {
//cerr << "sep y" << endl;
        for (int i = 0; i+1 < sep.size(); ++i)
            if (!ok(sep[i],sep[i+1]))
                return false;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> c[i] >> b[i] >> d[i];
    iota(g,g+n,0);
    cout << (ok(0,n) ? "YES\n" : "NO\n");
}
