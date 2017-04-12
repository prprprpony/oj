#include<bits/stdc++.h>
using namespace std;
const int N = 5487;
bool vis[N];
pair<int,int> pre[N];
int a[10];
void print(int v)
{
    if (pre[v].first)
        print(pre[v].first);
    putchar(pre[v].second | 48);
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) == 2) {
        for (int i = 0; i < m; ++i)
            scanf("%d",a+i);
        sort(a,a+m);
        fill_n(vis,n,0);
        if (!n) {
            puts("0");
            continue;
        }
        queue<int> q;
        q.push(0);
        while (q.size() && !vis[0]) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < m; ++i) if (v || a[i]) {
                int w = (10 * v + a[i]) % n;
                if (!vis[w]) {
                    vis[w] = true;
                    pre[w] = {v,a[i]};
                    q.push(w);
                }
            }
        }
        if (vis[0]) {
            print(0);
            puts("");
        } else {
            puts("0");
        }
    }
}
