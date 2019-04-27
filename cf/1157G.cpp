#include<bits/stdc++.h>
using namespace std;
const int N=205;
typedef bitset<N> bs;
int n,m;
bs a[N],f;
void go(const bs & c)
{
    bs b,r;
    bool cur = 0;
    for (int i = 0; i < n; ++i) {
        b = a[i] ^ c;
        if (b[0] != cur) {
            r[i] = 1;
            b ^= f;
        }
        if (cur * m == b.count())
            continue;
        if (cur)
            return;
        int w = 0;
        for (int j = 1; j < m; j++)
            w += b[j] != b[j-1];
        if (w != 1)
            return;
        cur = 1;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << r[i];
    cout << endl;
    for (int i = 0; i < m; ++i)
        cout << c[i];
    cout << endl;
    exit(0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    for (int i = 0; i < m; ++i)
        f[i] = 1;
    go(a[0]);
    if (n > 1)
        go(f ^ a[1]);
    cout << "NO\n";
}
