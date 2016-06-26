#include <iostream>
using namespace std;
int cnt[10];
int main()
{
    int f, n, t;
    cin >> f >> n >> t;
    for (int i = 0; i < f; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'Y')
                ++cnt[j];
        }
    int ans = 0;
    for (int j = 0; j < n; j++)
        if (cnt[j] >= t)
            ++ans;
    cout << ans << endl;
    return 0;
}
