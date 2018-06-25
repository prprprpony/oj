#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
char s[N],t[N];
int ps[N],pt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> (s+1) >> (t+1) >> q;
    for (int i = 1; s[i]; ++i)
        ps[i] = (s[i] == 'A' ? 1 : -1) + ps[i-1];
    for (int i = 1; t[i]; ++i)
        pt[i] = (t[i] == 'A' ? 1 : -1) + pt[i-1];
    while (q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x = ((ps[b] - ps[a-1]) % 3 + 3) % 3;
        int y = ((pt[d] - pt[c-1]) % 3 + 3) % 3;
        cout << (x == y ? "YES\n" : "NO\n");
    }
}
