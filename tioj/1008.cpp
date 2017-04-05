#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
int m[5],b[5];
const int V = 3.5e8;
bitset<V> vis;
int main()
{
    int n,t;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d", m + i);
    scanf("%d",&t);
    bool ts = true;
    for (int i = 0; i < n && ts; ++i)
        ts = m[i] < t;
    if (ts) {
        puts("-1");
        return 0;
    }
    b[0] = 1;
    for (int i = 1; i < 5; ++i)
        b[i] = 51 * b[i-1];
    queue<pii> q;
    q.push({0,0});
    vis[0] = 1;
    while (q.size()) {
        const pii x = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            int v = x.F/b[i]%51;
            int y = x.F - v * b[i];
            if (!vis[y]) {
                q.push({y,x.S+1});
                vis[y] = 1;
            }
            y += m[i]*b[i];
            if (!vis[y]) {
                if (m[i] ==t) {
                    printf("%d",x.S+1);
                    return 0;
                }
                q.push({y,x.S+1});
                vis[y] = 1;
            }
            for (int j = 0; j < n; ++j) if (j!=i) {
                int w = x.F/b[j]%51;
                int a = min(v,m[j]-w);
                int z = x.F-a*b[i]+a*b[j];
                if (!vis[z]) {
                    if (v-a==t||w+a==t) {
                        printf("%d",x.S+1);
                        return 0;
                    }
                    q.push({z,x.S+1});
                    vis[z] = 1;
                }
                z -= (v-a) * b[i];
                if (!vis[z]) {
                    q.push({z,x.S+1});
                    vis[z] = 1;
                }
            }
        }
    }
    puts("-1");
}
