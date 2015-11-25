#include <iostream>
using namespace std;
int main()
{
    int t, ans;
    long long a[6];
    long long m;
    cin >> t;
    while (t--) {
        m = 1;
        ans = 0;
        for (int i = 0; i < 6; i++) {
            cin >> a[i];
            m *= a[i];
        }
        
        for (int i = 1; i <= 4; i++)
            for (int j = i + 1; j <= 5; j++) {
                int n = a[0] * a[i] * a[j];
                if (m / n == n)
                    ans++;
            }
        cout << ans << endl;
    }

    return 0;
}
