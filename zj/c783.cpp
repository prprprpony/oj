#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        ll k = 9, ans = 0;
        if (n <= k) {
            ans = n;
        } else {
            ans = 9;
            while (10 * k + 9 < n) {
                k = 10  * k + 9;
                ans += 9;
            }
            for (char c : to_string(n - k))
                ans += c - '0';
        }
        printf("%lld\n", ans);
    }
}
