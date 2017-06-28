#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define PB push_back
const int N = 7087 * 2;
int suin[N],deg[N],k[2],s[2][N],n;
void go(int u)
{
    int b = (u&1)^1;
    if (suin[u] == 1) {
        for (int i = 0; i < k[b]; ++i) {
            int v = (((u>>1) - s[b][i] + n) % n)<<1|b;
            if (!suin[v]) {
                suin[v] = 2;
                go(v);
            }
        }
    } else {
        for (int i = 0; i < k[b]; ++i) {
            int v = (((u>>1) - s[b][i] + n) % n)<<1|b;
            if (--deg[v] == 0) {
                suin[v] = 1;
                go(v);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        cin >> k[i];
        for (int x = 0; x < k[i]; ++x)
            cin >> s[i][x];
        for (int j = 1; j < n; ++j)
            deg[j<<1|i] = k[i];
    }
    suin[0] = suin[1] = 1; // 1 su ,2 in
    go(0);
    go(1);
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j < n; ++j) {
            cout << (suin[j<<1|i] ? (suin[j<<1|i] == 1 ? "Lose" : "Win") : "Loop");
            cout << " \n"[j==n-1];
        }
}
