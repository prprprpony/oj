#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[10];
int main()
{
    int n;
    while (scanf("%d",&n) == 1) {
        fill_n(vis,10,0);
        int c = 10, k = 0;
        for (ll v = n; c; v += n, ++k) {
            for (ll t = v; t; t /= 10) {
                if (!vis[t%10]) {
                    vis[t%10]=1;
                    --c;
                }
            }
        }
        printf("%d\n",k);
    }
}
