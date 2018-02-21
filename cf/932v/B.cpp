#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 87;
int s[10][N], p[N];
int f(int x)
{
    int k = 1;
    while (x > 0) {
        int y = x % 10;
        x /= 10;
        if (y > 0)
            k *= y;
    }
    return k;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for (int i = 0; i < 10; ++i)
        p[i] = i; 
    for (int i = 1; i < N; ++i) {
        int x = p[f(i)];
        p[i] = x;
        s[x][i] += 1;
            for (int j = 1; j < 10; ++j)
                s[j][i] += s[j][i-1];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l,r,k;
        cin >> l >> r >> k;
        cout << s[k][r] - s[k][l-1] << '\n';
    }
}
