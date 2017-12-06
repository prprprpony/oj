#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n) == 1 && n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d",&x);
            pq.push(x);
        }
        long long ans = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            x += pq.top();
            pq.pop();
            ans += x;
            pq.push(x);
        }
        printf("%lld\n",ans);
    }
}
