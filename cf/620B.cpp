#include <bits/stdc++.h>
using namespace std;
int s[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    int a, b;
    int ans = 0;
    cin >> a >> b;
    for ( ; a <= b; a++) {
        int t = a;
        while (t) {
            ans += s[t % 10];
            t /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}
