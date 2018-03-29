#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int y = 0;
    for (int i = 1; i < n; ++i) {
        int d = abs(a[i] - a[i-1]);
        if (!d) {
            cout << "NO\n";
            return 0;
        }
        if (d != 1) {
            y = d;
        }
    }
    if (!y) {
        cout << "YES\n1000000000 1\n";
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int d = abs(a[i] - a[i-1]);
        int w = (a[i] - a[i-1]);
        if (d == 1) {
            if (a[i-1] % y == 1 && w < 0) {
                cout << "NO\n";
                return 0;
            }
            if (a[i-1] % y == 0 && w > 0) {
                cout << "NO\n";
                return 0;
            }
        } else if (d != y) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n" << int(1e9) << ' ' << y << '\n';
}
