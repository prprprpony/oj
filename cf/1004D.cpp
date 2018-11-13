#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 97;
int c[N],t,n,m,mx,l,g[N];
void ck(int x,int y)
{
    if (min(x,y) < 0 || x >= n || y >= m)
        return;
    memset(g,0,sizeof(g));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ++g[abs(i-x)+abs(j-y)];
    for (int i = 0; i < t; ++i)
        if (c[i] != g[i])
            return;
    cout << n << ' ' << m << '\n' << x+1 << ' ' << y+1 << endl;
    exit(0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        ++c[x];
        mx = max(mx, x);
    }
    if (c[0] != 1) {
        cout << "-1\n";
        return 0;
    }
    l = 1;
    while (c[l] == 4 * l)
        ++l;
    --l;

    for (n = 1; n * n <= t; ++n) {
        if (t % n)
            continue;
//        cerr << n << ' ' << m << endl;
        m = t/n;
        ck(n-1-l,mx - (n-1-l));
        ck(l,mx-l);
        ck(mx-l,l);
        ck(mx - (m-1-l),m-1-l);
    }   
    cout << "-1\n";
}
