#include <bits/stdc++.h>
using namespace std;
char buf[100];
int p[26];
bool vis[26];
int sz[26];
int find(int x) {return x != p[x] ? p[x] = find(p[x]) : x;}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}
int main()
{
    int t, v, tree;
    scanf("%d ", &t);
    while (t--) {
        for (int i = 0; i < 26; i++) {
            p[i] = i;
            sz[i] = 1;
        }
        while (fgets(buf, sizeof(buf), stdin) != NULL && buf[0] != '*')
            Union(buf[1] - 'A', buf[3] - 'A');
        fgets(buf, sizeof(buf), stdin);
        v = strlen(buf) / 2;
        tree = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 26; i++) {
            int f = find(i);
            if (!vis[f]) {
                vis[f] = true;
                if (sz[f] > 1) {
                    tree++;
                    v -= sz[f];
                }
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, v);
    }
}
