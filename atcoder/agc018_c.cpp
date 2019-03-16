#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
typedef long long ll;
const int N = 1e5+87;
int a[N], b[N], c[N];
ll pr[N], po[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y,z;
    cin >> x >> y >> z;
    int n = x + y + z;
    ll ans = 0;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        ans += c[i];
        a[i] = a[i] - c[i];
        b[i] = b[i] - c[i];
        v.emplace_back(a[i],b[i]);
    }
    sort(begin(v),end(v),[](const pii&x,const pii&y){return x.F-x.S < y.F-y.S;});
    priority_queue<int,vector<int>,greater<int>> pq;
    ll su = 0; 
    for (int i = 0; i < n; ++i) {
        pq.push(v[i].S);
        su += v[i].S;
        if (pq.size() > y) {
            su -= pq.top();
            pq.pop();
        }
        pr[i] = su;
    }
    while (pq.size()) pq.pop();
    su = 0;
    for (int i = n-1; i >= 0; --i) {
        pq.push(v[i].F);
        su += v[i].F;
        if (pq.size() > x) {
            su -= pq.top();
            pq.pop();
        }
        po[i] = su;
    }
    ll mx = LLONG_MIN;
    for (int i = y-1; n-1-i >= x; ++i)
        mx = max(mx,pr[i]+po[i+1]);
    cout << ans + mx << endl;
}
