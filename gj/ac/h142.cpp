#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        int k = 0, p = 0, m = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c;
            switch (c) {
            case 'W':
                k += 10 + m * 5;
                m = 0;
                break;
            case 'L':
                p += 10;
                if (m < 5)
                    m++;
                break;
            case 'D':
                k += 5;
                p += 5;
                break;
            }
        }
        cout << k << ' ' << p << '\n';
    }

    return 0;
}
