#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t, e[3], cnt;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        for (int i = 0; i < 3; i++)
            cin >> e[i];
        sort(e, e + 3);
        cout << "Case " << cases << ": ";
        if (e[0] <= e[2] - e[1]) { // mind overflow!
            cout << "Invalid";
        } else {
            cnt = 1;
            for (int i = 1; i < 3; i++)
                if (e[i] == e[i-1])
                    cnt++;
            switch (cnt) {
                case 3:
                    cout << "Equilateral";
                    break;
                case 2:
                    cout << "Isosceles";
                    break;
                default:
                    cout << "Scalene";
                    break;
            }
        }
        cout << '\n';
    }
    return 0;
}
