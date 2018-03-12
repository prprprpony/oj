#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
typedef pair<int,int> pii;
#define F first
#define S second
vector<int> g[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    priority_queue<pii> pq;
    for (int i = 1; i <= n; ++i) pq.push({k,i});
    while (pq.size()) {
        int i,w;
        tie(w,i) = pq.top();
        pq.pop();
        if (pq.size() < w) {
            cout << "Oops!\n";
            return 0;
        }
        vector<pii> tmp;
        while (w--) {
            auto p = pq.top();
            pq.pop();
            g[i].push_back(p.S);
            if (--p.F > 0)
                tmp.push_back(p);
        }
        for (const auto & x : tmp)
            pq.push(x);
    }
    cout << n * k / 2 << '\n';
    for (int i = 1; i <= n; ++i)
        for (int j : g[i])
            cout << i << ' ' << j << '\n';
}
