#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, m, t;
    bool none = true;
    cin >> n;
    int buy[n + 1];
    memset(buy, -1, sizeof(buy));
    cin >> m;
    while (m--) {
        cin >> t;
        buy[t] = 0;
    }
    cin >> m;
    while (m--) {
        cin >> t;
        if (buy[t] == -1)
           buy[t] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (buy[i] == 1) {
            if (!none)
                cout << ' ';
            else
                none = false;
            cout << i;
        }
    }
    if (none)
        cout << "None";
    cout << '\n';
    return 0;
}
