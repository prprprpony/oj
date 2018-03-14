#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d,h;
    cin >> n >> d >> h;
    if (n == 2) {
        cout << "1 2\n";
        return 0;
    }
    if (d < 2 || h < (d+1)/2) {
        cout << "-1\n";
        return 0;
    }
    int x, y, tp = 2;
    for (int i = 0; i < d + 1; ++i) {
        x = y;
        y = i == h ? 1 : tp++;
        if (i) 
            cout << x << ' ' << y << '\n';
    }
    while (tp <= n)
        cout << tp++ << ' ' << x << '\n';
}
