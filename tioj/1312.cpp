#include <bits/stdc++.h>
using namespace std;
const int N = 11234;
int p[N],v[N];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
void meld(int a,int b)
{
    a = find(a), b = find(b);
    p[a] = b;
    v[b] = min(v[b],v[a]);
}
int main()
{
    int n,m,k;
    while (scanf("%d%d",&n,&m) == 2) {
        for (int i = 1; i <= n; ++i)
            p[i] = v[i] = i;
        for (int i = 0; i < m; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            meld(a,b);
        }
        scanf("%d",&k);
        printf("%d\n",v[find(k)]);
    }
}
