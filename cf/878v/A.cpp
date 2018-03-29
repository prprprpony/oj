#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 87, B = 10;
char c[N];
int v[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> v[i];
    }
    int ad = 1023, orr = 0, xo = 0;
    for (int i = 0; i < B; ++i) {
        int a[2] = {};
        for (int k = 0; k <= 1; ++k) {
            int x = k;
            for (int j = 0; j < n; ++j) {
                int y = v[j] >> i & 1;
                switch (c[j]) {
                case '&':
                    x &= y;
                    break;
                case '|':
                    x |= y;
                    break;
                case '^':
                    x ^= y;
                    break;
                }
            }
            a[k] = x;
        }
        if (!a[0] && !a[1])
            ad ^= (1<<i);
        else if (a[0] && !a[1])
            xo ^= (1<<i);
        else if (a[0] && a[1])
            orr ^= (1<<i);
    }
    cout << "3\n" << "& " << ad << "\n^ " << xo << "\n| " << orr << '\n';
}
