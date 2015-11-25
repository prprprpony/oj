#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int t, n;
    set<int> num;
    cin >> t;
    while (t--) {
        num.clear();
        cin >> n;
        int c[n];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        sort(c, c + n);
        for (int i = 0; i < n; i++) {
            if (!num.count(c[i]))
                num.insert(c[i]);
            else if (!num.count(c[i] * 2))
                num.insert(c[i] * 2);
        }
        cout << num.size() << endl;
    }

    return 0;
}
