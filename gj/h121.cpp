#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return (b != 0) ? gcd(b, a % b) : a;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans;
        cin >> ans;
        for (int i = 0, m; i < n - 1; i++) {
            cin >> m;
            ans = gcd(ans, m);
        }
        cout << ans << endl;   
    }

    return 0;
}
