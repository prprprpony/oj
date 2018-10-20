#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
int d[N];
int main()
{
    int k;
    cin >> k;
    fill_n(d,k+1,N);
    d[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii{0,0});
    while (pq.size()) {
        int u,w;
        tie(w,u) = pq.top();
        pq.pop();
        if (w > d[u])
            continue;
        for (int i = 0; i < 10; ++i) {
            int v = u * 10 + i;
            if (v % k == 0 && v)
                v = k;
            else
                v %= k;
            int nw = w + i;
            if (nw < d[v]) {
                d[v] = nw;
                pq.push({nw,v});
            }
        }
    }
    cout << d[k] << '\n';
}
