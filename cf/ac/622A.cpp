#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while (cin >> n) {
        ll a = sqrt(n * 2);
        while (a * (a + 1) / 2 < n)
            a++;
        while (a * (a + 1) / 2 >= n)
            a--;
        cout << n - a * (a + 1) / 2 << '\n';
    }
    return 0;
}
