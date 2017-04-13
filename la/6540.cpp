#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define EB emplace_back
const int N = 1e5+87;
vector<pii> e[2];
int p[N];
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        p[i] = i;
}
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int run(const vector<pii> & adj)
{
    int cnt = 0;
    for (auto x : adj) {
        int u = find(x.F);
        int v = find(x.S);
        if (v != u) {
            p[v] = u;
            ++cnt;
        }
    }
    return cnt;
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d: ",kase);
        int n,m;
        scanf("%d%d",&n,&m);
        e[0].clear();
        e[1].clear();
        while (m--) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            e[c].EB(u,v);
        }
        init(n);
        int up = run(e[1]);
        if (up + run(e[0]) != n - 1) {
            puts("No");
            continue;
        }
        init(n);
        run(e[0]);
        int lo = run(e[1]);
        int a = 0, b = 1;
        while (b < lo) {
            b+=a;
            a=b-a;
        }
        puts(b <= up ? "Yes" : "No");
    }
}
