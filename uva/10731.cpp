#include <bits/stdc++.h>
using namespace std;
#define PB push_back
int hao,ons,st[26],tp,low[26],dfn, d[26], si[26], sn;
vector<int> g[26], sc[26];
void dfs(int u)
{
    d[u] = low[u] = ++dfn;
    st[tp++] = u;
    ons |= 1<< u;
    for (int v : g[u])
        if (!low[v]) {
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else if (ons & (1 << v)) {
            low[u] = min(low[u],low[v]);
        }
    if (low[u] == d[u]) {
        sc[sn].clear();
        int x;
        do {
            si[x = st[--tp]] = sn;
            sc[sn].PB(x);
            ons ^= 1<<x;
        } while (u != x);
        ++sn;
    }
}
int main()
{
    int n,first=1;
    while (scanf("%d",&n) == 1 && n) {
        sn = 0;
        for (int i = 0; i < 26; ++i) g[i].clear();
        fill_n(low,26,0);
        if (first)
            first = 0;
        else
            puts("");
        hao = 0;
        for (int i = 0; i < n; ++i) {
            int c,s[5];
            for (int j = 0; j < 5; ++j) {
                while (!isalpha(c = getchar()));
                hao |= 1<<(s[j] = c-'A');
            }
            while (!isalpha(c = getchar()));
            c -= 'A';
            for (int j = 0; j < 5; ++j)
                g[c].PB(s[j]);
        }
        for (int i = 0; i < 26; ++i) { //printf("HAO123%d\n",i);
            if ((hao & (1<<i)) && !low[i]) {
                dfn = 0;
                tp = 0;
                dfs(i);
            }
        }
        for (int i = 0; i < 26; ++i)
            if (hao & (1<<i)) {
                int j = si[i];
                sort(sc[j].begin(),sc[j].end());
                for (int k = 0; k < sc[j].size(); ++k) {
                    printf("%c%c",sc[j][k]+'A'," \n"[k==sc[j].size()-1]);
                    hao ^= 1 << sc[j][k];
                }
            }
    }
}
